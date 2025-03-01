#include<iostream>

#define SUB(a, b) ((a) - (b))

int main()
{
	int b = 5;
	int c = 2;
	int a = 6;
	std::cout << SUB(a, b) << std::endl;
	std::cout << SUB(a, b) * c << std::endl;
	std::cout << SUB(a, b + c) * c << std::endl;
}
