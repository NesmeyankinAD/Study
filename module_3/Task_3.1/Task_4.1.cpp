#include<iostream>
#include<Windows.h>

#include"QuickSort.h"


int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int SIZE = 18;
    int arr[SIZE] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    std::cout << "Исходный массив: ";
    print(arr, SIZE);

    quick_sort(arr, 0, SIZE - 1);

    std::cout << "Отсортированный массив: ";
    print(arr, SIZE);

    return 0;
}
