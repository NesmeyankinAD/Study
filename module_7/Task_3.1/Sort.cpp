#include <Windows.h>
#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <algorithm> 

// Асинхронная функция для поиска минимального элемента в диапазоне arr[start ... end-1]
void find_min_index_async(const std::vector<int>& arr, size_t start, size_t end, std::promise<size_t> promise) 
{
    size_t min_idx = start;

    for (size_t i = start + 1; i < end; ++i) 
    {
        if (arr[i] < arr[min_idx]) 
        {
            min_idx = i;
        }
    }
    promise.set_value(min_idx);
}

// Функция сортировки выбором с асинхронным поиском минимального элемента
void selection_sort_async(std::vector<int>& arr) 
{
    size_t n = arr.size();

    for (size_t i = 0; i < n - 1; ++i) 
    {
        
        std::promise<size_t> promise;
        std::future<size_t> future = promise.get_future();

        // Запускаем асинхронную задачу
        std::thread t(find_min_index_async, std::cref(arr), i, n, std::move(promise));

        // Ожидаем результат — индекс минимального элемента в текущем диапазоне
        size_t min_idx = future.get();

        // Меняем местами текущий элемент и минимальный
        if (min_idx != i) 
        {
            std::swap(arr[i], arr[min_idx]);
        }

        t.join();
    }
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::vector<int> data = { 64, 25, 12, 22, 11 };

    std::cout << "Исходный массив: ";
        for (auto v : data) std::cout << v << ' ';
        std::cout << std::endl;

    selection_sort_async(data);

    std::cout << "Отсортированный массив: ";
        for (auto v : data) std::cout << v << ' ';
        std::cout << std::endl;

    return 0;
}