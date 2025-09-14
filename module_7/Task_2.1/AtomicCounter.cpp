#include <Windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

std::atomic<int> client_count(0); // атомарный счётчик

// Параметризируемое количество клиентов
const int max_clients = 10;

// Флаг завершения работы операциониста
std::atomic<bool> stop_operator(false);

// Функция клиента: увеличивает счётчик раз в секунду
void client_thread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        int current_count = client_count.load(); // читаем текущее значение

        if (current_count < max_clients)
        {
            // Попытка атомарно увеличить, если меньше max_clients
            if (client_count.compare_exchange_strong(current_count, current_count + 1))
            {
                std::cout << "Клиент пришёл. Всего клиентов: " << current_count + 1 << std::endl;
            }
        }
        else
        {
            std::cout << "Очередь полна (" << current_count << "). Клиент не добавлен." << std::endl;
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

        // проверка работы с разными способами упорядочения доступа к памяти
        int current_count = client_count.load(std::memory_order_relaxed); 

        if (current_count > 0)
        {
            // Попытка атомарно уменьшить
            if (client_count.compare_exchange_strong(current_count, current_count - 1))
            {
                std::cout << "Операционист обслужил клиента. Осталось: " << current_count - 1 << std::endl;
            }
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