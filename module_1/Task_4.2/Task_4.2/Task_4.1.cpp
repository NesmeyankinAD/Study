#include <iostream>
#include <locale.h>

//����� ���� ��������� �����

int main()
{
	setlocale(LC_ALL, "rus");

	int a, sum{ 0 };

	std::cout << "������� ����� �����: ";
	std::cin >> a;

	while (a != 0)
	{
		sum += (a%10);

		a = (a - (a % 10)) / 10;
			
	}

	std::cout << "����� ���� ��������� �����: " << sum << std::endl;

	return 0;
}