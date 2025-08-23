#include <Windows.h>
#include <iostream>
#include <vector>
#include <set>



void removeDuplicates(std::set<int>& vec) 
{
    std::set<int> seen; // для отслеживания уже встреченных элементов

    auto it = vec.begin(); // установили итератор на начало vec

    while (it != vec.end()) 
    {
        // если количество элементов по итератору it больше 0, нужно удалить его из vec
        if (seen.count(*it))
        {
            it = vec.erase(it);
            // при удалении it укажет на новый элемент, инкремент не нужен
        }
        // иначе добавить в seen
        else 
        {
            seen.insert(*it);
            it++;
        }
    }
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::set<int> data = { 1, 1, 2, 5, 6, 1, 2, 4 }; // set для сортировки элементов по возпрастанию

    removeDuplicates(data);


    for (int num : data) 
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}