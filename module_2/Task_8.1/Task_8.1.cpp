#include<iostream>
#include<Windows.h>


class LenghtException : public std::exception
{
public:
	const char* what() const override
	{
		return "bad_lenght";
	}
};

int function(std::string str, int forbidden_length)
{
	if (str.length() != forbidden_length)
	{
		return str.length();
	}
	else throw LenghtException();
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int forbidden_length{0};

	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;

	bool work{ true };
	std::string word;

	while (work)
	{
		std::cout << "Введите слово: ";
		std::cin >> word;

		try
		{
			std::cout << "Длина слова '" << word << "' равна " << function(word, forbidden_length) << std::endl;
		}
		catch (LenghtException) 
		{
			std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;

			work = false;
		}
	}
}