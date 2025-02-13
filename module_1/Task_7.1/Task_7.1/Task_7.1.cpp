#include<iostream>


int main()
{
	int a{ 0 };
	short b{ 0 };
	long c{ 0 };
	long long d{ 0 };
	float e{ 0 };
	double f{ 0 };
	long double g{ 0 };
	bool h{ 0 };

	std::cout << "int:\t\t" << &a << "\t" << sizeof(a) << std::endl;
	std::cout << "short:\t\t" << &b << "\t" << sizeof(b) << std::endl;
	std::cout << "long:\t\t" << &c << "\t" << sizeof(c) << std::endl;
	std::cout << "long long:\t" << &d << "\t" << sizeof(d) << std::endl;
	std::cout << "float:\t\t" << &e << "\t" << sizeof(e) << std::endl;
	std::cout << "double:\t\t" << &f << "\t" << sizeof(f) << std::endl;
	std::cout << "long double:\t" << &g << "\t" << sizeof(g) << std::endl;
	std::cout << "bool:\t\t" << &h << "\t" << sizeof(h) << std::endl;

	return 0;
}