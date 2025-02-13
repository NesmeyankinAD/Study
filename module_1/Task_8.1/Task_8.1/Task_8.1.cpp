#include <iostream>
#include <locale.h>

void counting_function()
{
    static int i = 0;
    i++;
    std::cout << "Количество вызовов функции: " << i << std::endl;
}



int main()
{
    setlocale(LC_ALL, "Rus");

    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
}