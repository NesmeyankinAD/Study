#include <iostream>
#include <locale.h>

int main() {

	setlocale(LC_ALL, "Rus");
	
	bool a, b;
	
	//�������� ||
	std::cout << std::boolalpha << "�������� ||:" << "\n";
	
	a = true;b = true;
		std::cout << a << "\t" << b << "\t" << (a || b) << "\n";
	a = true;b = false;
		std::cout << a << "\t" << b << "\t" << (a || b) << "\n";
	a = false;b = true;
		std::cout << a << "\t" << b << "\t" << (a || b) << "\n";
	a = false;b = false;
		std::cout << a << "\t" << b << "\t" << (a || b) << "\n";
	
	std::cout << "\n" << "�������� &&:" << "\n";
	
	//�������� &&
	a = true;b = true;
		std::cout << a << "\t" << b << "\t" << (a && b) << "\n";
	a = true;b = false;
		std::cout << a << "\t" << b << "\t" << (a && b) << "\n";
	a = false;b = true;
		std::cout << a << "\t" << b << "\t" << (a && b) << "\n";
	a = false;b = false;
		std::cout << a << "\t" << b << "\t" << (a && b) << "\n";
	
	return 0;
}