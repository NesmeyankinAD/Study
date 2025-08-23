#include <Windows.h>
#include <iostream>
#include <vector>


class Counter 
{
private:
    int sum = 0;
    int count = 0;

public:
    // Функтор - вызываем объект как функцию
    void operator()(int value) 
    {
        if (value % 3 == 0) 
        {
            sum += value;
            ++count;
        }
    }

    int get_sum() const 
    {
        return sum;
    }

    int get_count() const 
    {
        return count;
    }
};

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Counter counter;

    // Чтение чисел
    std::vector<int> numbers;

    int n{0};

    std::cout << "Количетсво элеметнов вектора: ";
    std::cin >> n;
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        int num{0};

        std::cin >> num;
        numbers.push_back(num);
    }
 
    // Обработка чисел функтором
    for (int num : numbers) 
    {
        counter(num);
    }

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}