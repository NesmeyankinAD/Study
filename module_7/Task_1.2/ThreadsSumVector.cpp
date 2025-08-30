#include <Windows.h>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>      // для форматирования таблицы
#include <algorithm>    // для std::fill заполнение векторов

// Функция для вычисления суммы части вектора
void partial_sum(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& result, size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i)
    {
        result[i] = v1[i] + v2[i];
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Определение размеров массивов
    std::vector<size_t> sizes = { 1000, 10000, 100000, 1000000 };

    // Количество потоков для тестирования
    std::vector<int> thread_counts = { 2, 4, 8, 16 };

    // Вывод количества ядер
    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "Доступное количество ядер: " << cores << "\n\n";

    // Таблица
    std::cout   << std::setw(12) << "Размер"
                << std::setw(12) << "Потоки"
                << std::setw(15) << "Время (мкс)"
                << std::endl;

    for (auto size : sizes)
    {
        // Инициализация векторов
        std::vector<int> v1(size);
        std::vector<int> v2(size);
        std::vector<int> result(size);

        // Заполнение векторов единицами
        std::fill(v1.begin(), v1.end(), 1);
        std::fill(v2.begin(), v2.end(), 1);

        for (auto thread_count : thread_counts)
        {
            // Распараллеливание
            // вектор потоков
            std::vector<std::thread> threads;

            size_t block_size = size / thread_count;

            auto start_time = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < thread_count; ++i)
            {
                size_t start_id = i * block_size;

                size_t end_id = (i == thread_count - 1) ? size : start_id + block_size;

                threads.emplace_back(partial_sum, std::cref(v1), std::cref(v2), std::ref(result), start_id, end_id);
            }

            // Ожидание завершения потоков
            for (auto& t : threads)
            {
                t.join();
            }

            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

            // Вывод результатов
            std::cout   << std::setw(12) << size
                        << std::setw(12) << thread_count
                        << std::setw(15) << duration_ms
                        << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}