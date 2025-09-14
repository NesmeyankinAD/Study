#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <numeric>

template<typename Iterator, typename Func>
void parallel_for_each(Iterator begin, Iterator end, Func func, size_t threshold = 1000) 
{
    auto length = std::distance(begin, end);

    if (length <= threshold) 
    {
        // В малом диапазоне делаем последовательный вызов
        std::for_each(begin, end, func);
    }
    else 
    {
        // Делим диапазон пополам
        Iterator mid = begin;
        std::advance(mid, length / 2);

        // Запускаем задачи для обеих половин
        auto future_left = std::async(std::launch::async, parallel_for_each<Iterator, Func>, begin, mid, func, threshold);
        auto future_right = std::async(std::launch::async, parallel_for_each<Iterator, Func>, mid, end, func, threshold);

        // Ждём завершения обеих
        future_left.get();
        future_right.get();
    }
}

int main() 
{

    std::vector<int> data(10000);
    
    std::iota(data.begin(), data.end(), 0); // Заполняем данными

    // Обработка — например, вывод первых 10 элементов
    auto print_elem = [](int& v) { v *= 2; }; // умножим каждый элемент на 2

    parallel_for_each(data.begin(), data.end(), print_elem, 1000);

    // Проверим
    for (int i = 0; i < 10; ++i) 
    {
        std::cout << data[i] << ' '; // вывод: 0 2 4 6 8 ...
    }
    std::cout << std::endl;

    return 0;
}