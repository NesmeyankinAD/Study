#include <iostream>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Rus");
    
    int a, b, c;
    
    std::cout << "������� ������ �����: ";
    std::cin >> a;
    
    std::cout << "\n" << "������� ������ �����: ";
    std::cin >> b;
    
    std::cout << "\n" << "������� ������ �����: ";
    std::cin >> c;
    
    std::cout << "\n" << "������� ������ �����: ";
    
    a > b
           ? a > c
                    ? c > b
                            ? (std::cout << "\n" << a << "\t" << c << "\t" << b)
                            : (std::cout << "\n" << a << "\t" << b << "\t" << c)
    
                    : (std::cout << "\n" << c << "\t" << a << "\t" << b)
    
           : b > c
                    ? c > a
                            ? (std::cout << "\n" << b << "\t" << c << "\t" << a)
                            : (std::cout << "\n" << b << "\t" << a << "\t" << c)
    
                    : (std::cout << "\n" << c << "\t" << b << "\t" << a);
}