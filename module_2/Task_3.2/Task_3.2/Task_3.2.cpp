#include<iostream>
#include<Windows.h>


class Counter
{
private:
	int value{0};

public:

	Counter() 
	{
		this->value = 1;
	}; 


	bool Master(char command)
	{
		switch (static_cast<int>(command))
		{
			case 43: IncrCounter(); return 1; break;
			case 45: DecrCounter(); return 1; break;
			case 61: CheckValue();	return 1; break;
			case 120:				return 0; break;

			default: std::cout << "Неверная комманда!" << std::endl; break;

		}
	}

	void IncrCounter()
	{
		this->value++;
	}

	void DecrCounter()
	{
		this->value--;
	}

	void CheckValue()
	{
		std::cout << "Значение счётика: " << this->value << std::endl;
	}

	void SetValue(int Value)
	{
		this->value = Value;
	}
		
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Counter counter;

	bool Init{false};

	std::cout << "Вы хотите указать начальное значение счётчика? (1 - да, 0 - нет): ";
	std::cin >> Init;
	std::cout << std::endl;

	if (Init)
	{
		int InitValue{0};

		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> InitValue;

		counter.SetValue(InitValue);
	}
	
	bool Work{ true };
	char command;

	while (Work)
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> command;

		Work = counter.Master(command);
	}
}