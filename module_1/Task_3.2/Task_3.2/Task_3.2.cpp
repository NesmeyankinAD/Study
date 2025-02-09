#include <iostream>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Rus");
    
    int a, b, c;
    
    std::cout << "¬ведите первое число: ";
    std::cin >> a;
    
    std::cout << "\n" << "¬ведите второе число: ";
    std::cin >> b;
    
    std::cout << "\n" << "¬ведите третье число: ";
    std::cin >> c;
    
    std::cout << "\n" << "¬ведите третье число: ";
    
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