#include <iostream>
#include <locale.h>

//����� ������� �����
int main()
{
	setlocale(LC_ALL, "rus");

	int a, sum{0};

	do
	{
		std::cout << "������� ����� ����� (0 ��� ������): ";
		std::cin >> a;
		sum += a;

		if (a == 0) break;

	} while (1);

	std::cout << "����� ������� �����: " << sum << std::endl;

	return 0;
}