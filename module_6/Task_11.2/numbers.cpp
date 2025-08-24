#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>

class big_integer 
{
private:
    std::string number; // число в виде строки без знака

public:
    // Конструктор из строки
    big_integer(const std::string& num) : number(num) {}

    // Конструктор перемещения
    big_integer(big_integer&& other) noexcept : number(std::move(other.number)) {}


    // Перемещающий оператор присваивания
    big_integer& operator=(big_integer&& other) noexcept
    {
        if (this != &other) 
        {
            number = std::move(other.number);
        }
        return *this;
    }

    // Оператор сложения
    big_integer operator+(const big_integer& rhs) const 
    {
        std::string result;

        const std::string& a = this->number;
        const std::string& b = rhs.number;

        int carry = 0;
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;

        while (i >= 0 || j >= 0 || carry) 
        {
            int digitA = (i >= 0) ? a[i] - '0' : 0;
            int digitB = (j >= 0) ? b[j] - '0' : 0;

            int sum = digitA + digitB + carry;

            carry = sum / 10;

            result.push_back((sum % 10) + '0');

            i--;
            j--;
        }

        std::reverse(result.begin(), result.end());
        return big_integer(result);
    }

    // Оператор умножения
    big_integer operator*(int num) const
    {
        if (num == 0) return big_integer("0");
        if (num == 1) return big_integer(this->number);

        std::string result;

        int carry = 0;

        for (int i = static_cast<int>(number.size()) - 1; i >= 0; --i) 
        {
            int prod = (number[i] - '0') * num + carry;

            carry = prod / 10;

            result.push_back((prod % 10) + '0');
        }

        if (carry) { result.push_back(carry + '0'); }

        std::reverse(result.begin(), result.end());

        return big_integer(result);
    }

    // Вывод числа - операция << через поток os
    // нужно получить доступ к полю number, поэтому функция friend
    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) 
    {
        os << num.number;
        return os;
    }
};

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    auto number1 = big_integer("114575");
    auto number2 = big_integer("1"); //"78524"

    auto result = number1 + number2; 
    std::cout << result << std::endl;     

    auto product = number2 * 1;      
    std::cout << product << std::endl;

    return 0;
}