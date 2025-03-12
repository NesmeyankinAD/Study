#include<iostream>
#include<Windows.h>
#include"Greeter.h"
#include"Leaver.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string name;

	std::cout << "¬ведите им€: ";
	std::cin >> name;

	Greeter greeter;
	Leaver leaver;

	std::cout << greeter.greet(name) << std::endl;
	std::cout << std::endl;
	std::cout << leaver.leave(name) << std::endl;


	return EXIT_SUCCESS;
}