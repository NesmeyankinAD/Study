#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>

// Класс данных
class Data 
{
public:
    int scalar1;
    double scalar2;

    std::mutex mtx;

    Data(int a, double b) : scalar1(a), scalar2(b) {}
};

// Вариант 1: с использованием std::lock
void swap_with_lock(Data& a, Data& b) 
{
    std::lock(a.mtx, b.mtx);

    // После захвата обоих мьютексов, блокируем их
    std::lock_guard<std::mutex> lock_a(a.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> lock_b(b.mtx, std::adopt_lock);

    // Обмен данных
    std::swap(a.scalar1, b.scalar1);
    std::swap(a.scalar2, b.scalar2);
}

// Вариант 2: с использованием std::scoped_lock
void swap_with_scoped_lock(Data& a, Data& b) 
{
    std::scoped_lock lock(a.mtx, b.mtx);

    // Обмен данных
    std::swap(a.scalar1, b.scalar1);
    std::swap(a.scalar2, b.scalar2);
}

// Вариант 3: с использованием std::unique_lock
void swap_with_unique_lock(Data& a, Data& b) 
{
    std::unique_lock<std::mutex> lock_a(a.mtx, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(b.mtx, std::defer_lock);

    // Захватываем оба мьютекса одновременно, избегая взаимной блокировки
    std::lock(lock_a, lock_b);

    // Обмен данных
    std::swap(a.scalar1, b.scalar1);
    std::swap(a.scalar2, b.scalar2);
}

int main() 
{
    Data data1(1, 1.1);
    Data data2(2, 2.2);

    // Запускаем обмен в отдельных потоках для демонстрации
    std::thread t1(swap_with_lock, std::ref(data1), std::ref(data2));
    std::thread t2(swap_with_scoped_lock, std::ref(data1), std::ref(data2));
    std::thread t3(swap_with_unique_lock, std::ref(data1), std::ref(data2));

    t1.join();
    t2.join();
    t3.join();

    // Выводим результат
    std::cout << "Data1: " << data1.scalar1 << ", " << data1.scalar2 << "\n";
    std::cout << "Data2: " << data2.scalar1 << ", " << data2.scalar2 << "\n";

    return 0;
}