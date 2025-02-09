#include<iostream>
#include<locale.h>

int power(int value, int power)
{
	int result = 1;

	for (int i = 0; i < power; i++)
	{
		result *= value;
	}
	std::cout << value << " в степени " << power << " = " << result << std::endl;

	return 0;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	power(5, 2);
	power(3, 3);
	power(4, 4);
		
	return 0;
}