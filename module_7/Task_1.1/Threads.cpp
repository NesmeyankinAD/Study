#include <Windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>


int client_count = 0;

// Параметризируемое количество клиентов
const int max_clients = 10; 

// Мьютекс для защиты доступа к client_count
std::mutex mtx;

// Флаг завершения работы операциониста
std::atomic<bool> stop_operator(false);

// Функция клиента: увеличивает счётчик раз в секунду
void client_thread() 
{
    while (true) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::lock_guard<std::mutex> lock(mtx); //lock_guard вместо mtx.lock и mtx.unlok

        if (client_count < max_clients) 
        {
            client_count++;
            std::cout << "Клиент пришёл. Всего клиентов: " << client_count << std::endl;
        }
        else 
        {
            std::cout << "Очередь полна (" << client_count << "). Клиент не добавлен." << std::endl;
        }
    }
}
 
// Функция операциониста: уменьшает счётчик раз в 2 секунды, пока есть клиенты
// или пока его не остановили 
void operator_thread() 
{
    while (!stop_operator) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::lock_guard<std::mutex> lock(mtx);

        if (client_count > 0) 
        {
            client_count--;
            std::cout << "Операционист обслужил клиента. Осталось: " << client_count << std::endl;
        }
    }
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Создаём потоки
    std::thread clientThread(client_thread);
    std::thread operatorThread(operator_thread);

    // Запускаем на некоторое время
    std::this_thread::sleep_for(std::chrono::seconds(30));

    // Останавливаем операциониста
    stop_operator = true;

    // Ждём завершения потоков
    if (clientThread.joinable()) clientThread.detach(); 
    if (operatorThread.joinable()) operatorThread.join();

    std::cout << "Работа завершена." << std::endl;

    return 0;
}