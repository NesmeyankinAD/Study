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

    
    std::cout << "������� ��� ���� �������: ";
    std::getline((std::cin), zodiac);

    std::cout << "������� ��� �������: ";
    std::cin >> age;

    std::cout << "������� ��� ���: ";
    std::cin >> gender;

        
    if (zodiac == "����" || zodiac == "���" || zodiac == "��������") z = 1;
    if (zodiac == "�����" || zodiac == "����" || zodiac == "�������") z = 2;
    
    
    if ((gender == '�') || (gender == '�'))
    {
        if (age < 40 && z == 1)
        {
            std::cout << "\n" << "������� ����� ������������ ����. ����� �������� ����, ��� ������ �������� ����� �����������." << std::endl;
        }
        else { std::cout << "�������� ��� ��� ��������� � ����������. ��������� ������� ����� ;)" << std::endl; }
    }
    else if ((gender == '�') || (gender == '�'))
    {
        if (age >= 15 && age <= 30) {
            std::cout << "\n" << "����������� ����� �������� ��� ������� � ��������, ���������� �������� ���������� � ����������������� ���������.����� �� ������ ������, �� � ��������� : ������� ����, ������� ������� ����." << std::endl;
        }
        else { std::cout << "�������� ��� ��� ��������� � ����������. ��������� ������� ����� ;)" << std::endl; }
    }

    else std::cout << "�������� ��� ��� ��������� � ����������. ��������� ������� ����� ;)" << std::endl;
    
}