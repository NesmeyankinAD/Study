#include<iostream>
#include<Windows.h>
#include <string>
#include <vector>

#include <pqxx/pqxx>


class SQL_manager
{
//поле conn - объект подключения типа pqxx::connection к БД PostgresSQL
//в него необходимо передать параметры для подключения к БД
private:
	pqxx::connection conn;

//конструктор создаёт объект типа SQL_manager
//в качестве параметра принимает строку с информацией о БД
//и передаёт её объекту подключения conn 
//"host=localhost port=5432 dbname=Cpp_PostgreSQL user=postgres password=sirius17"
public:
	SQL_manager(const std::string& connection_str) : conn(connection_str) {}

//методы создания таблиц
//в данном случае основная таблица связана с таблицей телефонов клиентов
//связью один ко многим
    void createTables() 
    {
        pqxx::work tx(conn);   //транзакция tx в подключении conn

        tx.exec(
            R"(CREATE TABLE IF NOT EXISTS clients 
                (
                id SERIAL PRIMARY KEY,
                first_name VARCHAR(50),
                last_name VARCHAR(50),
                email VARCHAR(100)
                );
            )"
        );
                
        tx.exec(
            R"(CREATE TABLE IF NOT EXISTS phones 
                (
                id SERIAL PRIMARY KEY,
                client_id INTEGER REFERENCES clients(id) ON DELETE CASCADE,
                phone VARCHAR(20)
                );
            )"
        );
        
        tx.commit();   //конец транзакции tx
        std::cout << "Таблицы созданы.\n";
    }

//добавление клиента
    int addClient(  const std::string& firstName, 
                    const std::string& lastName, 
                    const std::string& email) 
    {
        pqxx::work tx(conn);//транзакция tx

    //заполнение строки в таблице clients
    //в result запишется id клиента
        auto result = tx.exec_params
        (
            "INSERT INTO clients (first_name, last_name, email) VALUES ($1, $2, $3) RETURNING id",
            firstName, lastName, email
        );

    //преобразуем result-id в int-id 
        int clientId = result[0][0].as<int>();

        tx.commit();//конец транзакции tx

        return clientId;
    }

//добавление номера    
    void addPhone(int clientId, const std::string& phone) 
    {
        pqxx::work tx(conn);//транзакция tx

        tx.exec_params
        (
            "INSERT INTO phones (client_id, phone) VALUES ($1, $2)",
            clientId, phone
        );

        tx.commit();//конец транзакции tx
    }
//обновление информации о клиенте
    void updateClient(  int clientId, 
                        const std::string& firstName,
                        const std::string& lastName, 
                        const std::string& email) 
    {
        pqxx::work tx(conn);//транзакция tx

        tx.exec_params
        (
            "UPDATE clients SET first_name=$1, last_name=$2, email=$3 WHERE id=$4",
            firstName, lastName, email, clientId
        );

        tx.commit();//конец транзакции tx
    }

//удаление телефона клиента из таблицы phones
    void deletePhone(int clientId, const std::string& phone) 
    {
        pqxx::work tx(conn);

        tx.exec_params
        (
            "DELETE FROM phones WHERE client_id=$1 AND phone=$2",
            clientId, phone
        );

        tx.commit();
    }

//удаление клиента и всех его телефонов каскадно
    void deleteClient(int clientId) 
    {
        pqxx::work tx(conn);

        tx.exec_params("DELETE FROM clients WHERE id=$1", clientId);

        tx.commit();
    }

//поиск клиента
//searchTerm - выражение для поиска
    std::vector<int> findClient(const std::string& searchTerm)
    {
        pqxx::work tx(conn);

        //поиск по имени/фамилии/почте
        auto res1 = tx.exec_params
        (
            "SELECT c.id "
            "FROM clients c "
            "WHERE c.first_name ILIKE $1 OR c.last_name ILIKE $1 OR c.email ILIKE $1",
            "%" + searchTerm + "%"
        );

        //поиск по телефону
        //объединяем таблицы clients и phones
        auto res2 = tx.exec_params
        (
            "SELECT c.id "
            "FROM clients c "
            "JOIN phones p ON c.id=p.client_id "
            "WHERE p.phone ILIKE $1",
            "%" + searchTerm + "%"
        );
       
        std::vector<int> clientIDs; //вектор id клиентов


        if (res1.empty())
        {
            for (const auto& row : res2)
            {
                clientIDs.push_back(row["id"].as<int>());
            }
        }
        else if (res2.empty())
        {
            for (const auto& row : res1)
            {
                clientIDs.push_back(row["id"].as<int>());
            }
        }
        else if (res1.empty() && res2.empty()) 
        {
            std::cout << "Ничего не найдено.\n";
        }

        return clientIDs; //возвращаем вектор id клиентов
    }
};



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    try
    {
        //создаём подключение
        SQL_manager clients("host=localhost port=5432 dbname=Cpp_PostgreSQL user=postgres password=sirius17");

        //создаём таблицы
        clients.createTables();

        //добавляем клиента
        int client1 = clients.addClient("Client", "First", "FirstClient@email");

        //добавляем телефон клиенту
        clients.addPhone(client1, "88005553535");

        //обновляем информацию о клиенте
        clients.updateClient(client1, "Ivan", "Ivanov", "IvanovI@email");

        //ищем по email
        auto ids = clients.findClient("IvanovI@email");

        for (int id : ids)
        {
            std::cout << "Найден клиент с ID: " << id << std::endl;
        }

        //удаляем телефон клиента
        clients.deletePhone(client1, "88005553535");

        //удаляем клиента
        clients.deleteClient(client1);

    }
	catch (pqxx::sql_error e)
	{
		std::cout << e.what() << std::endl;
	}

}