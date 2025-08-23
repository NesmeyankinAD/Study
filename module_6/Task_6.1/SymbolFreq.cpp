#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <list>

// Функция сравнения для сортировки по убыванию частоты, колонка second в pair
bool comparePairs(const std::pair<char, int>& a, const std::pair<char, int>& b) 
{
    return a.second > b.second;
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Ввод строки 
    std::cout << "[IN]" << std::endl;
    std::string text;
    std::getline(std::cin, text);

    // Подсчет частот символов
    // в map - пары символ_частота
    std::map<char, int> freq_map;
    for (char c : text) 
    {
        ++freq_map[c];
    }

    // Переносим вектор пар для сортировки по убыванию частоты
    std::vector<std::pair<char, int>> freq_vec(freq_map.begin(), freq_map.end());

    // Сортируем по убыванию частоты
    std::sort(freq_vec.begin(), freq_vec.end(), comparePairs);


    // Выводим результат по парам pair
    std::cout << "[OUT]" << std::endl;
    for (const auto& pair : freq_vec) 
    {
        char ch = pair.first;
        int count = pair.second;
        std::cout << ch << ": " << count << std::endl;
    }

    return 0;
}