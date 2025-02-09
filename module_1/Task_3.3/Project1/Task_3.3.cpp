#include <iostream>
#include <locale.h>
#include <string>
#include <windows.h>

int main() {

    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char gender;
    std::string zodiac{};
    int age, z=0;

    
    std::cout << "Введите Ваш знак зодиака: ";
    std::getline((std::cin), zodiac);

    std::cout << "Введите Ваш возраст: ";
    std::cin >> age;

    std::cout << "Введите Ваш пол: ";
    std::cin >> gender;

        
    if (zodiac == "рыбы" || zodiac == "рак" || zodiac == "скорпион") z = 1;
    if (zodiac == "телец" || zodiac == "дева" || zodiac == "козерог") z = 2;
    
    
    if ((gender == 'м') || (gender == 'М'))
    {
        if (age < 40 && z == 1)
        {
            std::cout << "\n" << "Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным." << std::endl;
        }
        else { std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)" << std::endl; }
    }
    else if ((gender == 'ж') || (gender == 'Ж'))
    {
        if (age >= 15 && age <= 30) {
            std::cout << "\n" << "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех." << std::endl;
        }
        else { std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)" << std::endl; }
    }

    else std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)" << std::endl;
    
}