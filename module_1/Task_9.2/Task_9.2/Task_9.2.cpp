#include<iostream>
#include<locale.h>


void my_swap(int* x, int* y)
{
	std::cout << "x = " << *x << ", y = " << *y << std::endl;

	*x = *x ^ *y;	//x xor y = Z
	*y = *x ^ *y;	//Z xor y = x
	*x = *x ^ *y;	//Z xor x = y

	std::cout << "x = " << *x << ", y = " << *y << std::endl;
}


int main()
{
	int a = 5, b = 3;

	my_swap(&a, &b);
}
