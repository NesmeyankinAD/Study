#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() 
{
    std::cout << "[IN]" << std::endl;

    int n{0};
    std::cin >> n; // Количество элементов

    std::set<int> unique_numbers; // set для хранения уникальных чисел

    //Заполняем set
    // в set будут уникальные числа, отсортированные по возрастанию
    for (int i = 0; i < n; ++i) 
    {
        int num{0};

        std::cin >> num;
        unique_numbers.insert(num);
    }

    // Переносим уникальные числа в вектор для сортировки по убыванию
    std::vector<int> numbers(unique_numbers.begin(), unique_numbers.end());

    // Сортируем по убыванию
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // Выводим результат
    std::cout << "[OUT]" << std::endl;
    for (int num : numbers) 
    {
        std::cout << num << std::endl;
    }

    return 0;
}