#include <iostream>
#include <fstream>
#include <string>


class LogCommand 
{
public:
    virtual ~LogCommand() = default;
    virtual void print() = 0;
};

// Команда для вывода в консоль
class ConsoleLogCommand : public LogCommand 
{
private:
    std::string message_;

public:
    explicit ConsoleLogCommand(std::string message) : message_(std::move(message)) {}

    void print() override 
    {
        std::cout << message_ << std::endl;
    }
};

// Команда для записи в файл
class FileLogCommand : public LogCommand 
{
private:
    std::string filepath_;
    std::string message_;

public:
    FileLogCommand(std::string filepath, std::string message)
                    : filepath_(std::move(filepath)), message_(std::move(message)) {}

    void print() override 
    {
        std::ofstream file(filepath_, std::ios::app); // std::ios::app для добавления строк в файл

        if (file.is_open()) 
        {
            file << message_ << std::endl;
        }
        else 
        {
            std::cerr << "Error: unable to open file: " << filepath_ << std::endl;
        }
    }
};

// Функция для выполнения команды
void print(LogCommand& cmd) 
{
    cmd.print();
}


int main() 
{
    ConsoleLogCommand consoleCmd("Message to console");
    FileLogCommand fileCmd("log.txt", "Message to file");

    print(consoleCmd);  // печать в консоль
    print(fileCmd);     // запись в файл

    return 0;
}