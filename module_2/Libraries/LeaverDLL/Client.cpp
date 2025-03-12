#include<iostream>
#include<Windows.h>
#include"Leaver.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string name;

	std::cout << "¬ведите им€: ";
	std::cin >> name;

	Leaver leaver;

	std::cout << leaver.leave(name) << std::endl;


	return EXIT_SUCCESS;
}