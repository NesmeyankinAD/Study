#include<iostream>
#include<Windows.h>
#include<vector>

template<typename T>
T power2(T& num)
{
	return num * num;
}


template<typename T>
std::vector<T> power2(std::vector<T> vector)
{
	int size = vector.size();

	std::vector<T> vector2(size);

	for (int i = 0; i < size; i++)
	{
		vector2[i] = vector[i] * vector[i];
	}

	return vector2;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int num = 2;

	std::cout << "num^2 = " << power2<int>(num) << std::endl;

	std::vector<float> v1{2.1, 3.5, 6.7, 10.12, 9.18};

	std::vector<float> v2 = power2(v1);

	std::cout << "v1^2 = ";
	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl;
}