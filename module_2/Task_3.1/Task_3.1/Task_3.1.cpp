#include<iostream>
#include<Windows.h>


class Calculator
{
private:
	double num1, num2;
	
public:
	Calculator() 
	{
		this->num1 = NULL;
		this->num2 = NULL;
	};

	void add()
	{
		std::cout << "num1 + num2 = " << (this->num1 + this->num2) << std::endl;
	}
	
	void multiply()
	{
		std::cout << "num1 * num2 = " << (this->num1 * this->num2) << std::endl;
	}

	void substract_1_2()
	{
		std::cout << "num1 - num2 = " << (this->num1 - this->num2) << std::endl;
	}

	void substract_2_1()
	{
		std::cout << "num2 - num1 = " << (this->num2 - this->num1) << std::endl;
	}

	void divide_1_2()
	{
		std::cout << "num1 / num2 = " << (this->num1 / this->num2) << std::endl;
	}

	void divide_2_1()
	{
		std::cout << "num2 / num1 = " << (this->num2 / this->num1) << std::endl;
	}
	
	bool set_num1(double num1)
	{
		if (num1) 
		{
			this->num1 = num1;
			return true;
		}
		else { return false; }
	}

	bool set_num2(double num2)
	{

		if (num2)
		{
			this->num2 = num2;
			return true;
		}
		else { return false; }
	}
};


int main()
{
	SetConsoleOutputCP(1251); SetConsoleCP(1251);


	bool work{ true };
	double N1{ 0 }, N2{ 0 };

	Calculator calc;

	while(1)
	{
		std::cout << "Введите num1, не равное нулю: ";
		std::cin >> N1;

		std::cout << "Введите num2, не равное нулю: ";
		std::cin >> N2;

		if (calc.set_num1(N1) && calc.set_num2(N2)) // ввод ненулевых чисел
		{
			calc.add();
			calc.multiply();
			calc.substract_1_2();
			calc.substract_2_1();
			calc.divide_1_2();
			calc.divide_2_1();
		}
		else
		{
			std::cout << "Неверный ввод! Вводите числа не равные нулю." << std::endl;
		}

		std::cout << "Хотите выйти? (1 - да, 0 - нет): ";
		std::cin >> work;

		if (work) break;
		else std::cout<< std::endl;
	}
		
	return EXIT_SUCCESS;
}