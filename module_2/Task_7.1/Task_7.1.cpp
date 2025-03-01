#include<iostream>
#include<Windows.h>

#define MODE 1

#if (MODE == 1) 
	float add(float num1, float num2)
	{
		return num1 + num2;
	}
#endif

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

#ifdef MODE
	
	#if (MODE == 0) 
		std::cout << "Работаю в режиме тренировки." << std::endl;
	
	#elif (MODE == 1)
	
		float num1, num2;

		std::cout << "Работаю в боевом режиме." << std::endl;
		
		std::cout << "Введите число 1: ";
		std::cin >> num1;

		std::cout << "Введите число 2: ";
		std::cin >> num2;

		std::cout << "Сумма чисел: " << add(num1, num2) << std::endl;
	
	#else 
		std::cout << "Неизвестный режим.Завершение работы" << std::endl;
	#endif

#elif 
	#error MODE undefined

#endif


}