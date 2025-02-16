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

	Counter(int InitValue)
	{
		this->value = InitValue;
	};

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

		counter = Counter(InitValue);
	}
	
	bool Work{ true };
	char command;

	while (Work)
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> command;

		switch (static_cast<int>(command))
		{
		case '+': counter.IncrCounter();break;
		case '-': counter.DecrCounter();break;
		case '=': counter.CheckValue();	break;
		case 'x': Work = false;			break;

		default: std::cout << "Неверная комманда!" << std::endl; break;
		}
	}

	return EXIT_SUCCESS;
}