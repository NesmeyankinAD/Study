#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility> 


template <typename T>
void moveVector(std::vector<T>& source, std::vector<T>& destination) 
{
    // ѕеремещаем source в destination
    destination = std::move(source);
    // «десь source станет пустым
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::vector<std::string> one = { "test_string1", "test_string2" };
    std::vector<std::string> two;

    moveVector(one, two);

    // проверка содержимого вектора two
    std::cout << "two: ";
    for (int i = 0; i < two.size(); i++) 
    {
        std::cout << two[i] << " ";
    }
    std::cout << std::endl;


    // проверка содержимого вектора one
    std::cout << "one: ";
    for (int i = 0; i < one.size(); i++)
    {
        std::cout << one[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}