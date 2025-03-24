#include<iostream>
#include<Windows.h>

#include"VehiclesEnvironment.h"

using namespace vehicles;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	bool end_race{false};

	while(!end_race)
	{
		int race_type{ 0 };
		float race_distance{ 0.0 };

		std::cout << "Добро пожаловать в симулятор гонок!" << std::endl;
		std::cout << "1. Гонка для наземного транспорта." << std::endl;
		std::cout << "2. Гонка для воздушного транспорта." << std::endl;
		std::cout << "3. Гонка для наземного и воздушного транспорта." << std::endl;
		std::cout << "Выберите тип гонки: ";

		std::cin >> race_type;
		std::cout << std::endl;

		bool right_race_distance{ 0 };
		while (!right_race_distance)
		{
			std::cout << "Введите дистанцию гонки: ";
			std::cin >> race_distance;
			if (race_distance <= 0) std::cout << "Дистанция должна быть положительна!" << std::endl;
			else right_race_distance = true;
		}
		std::cout << std::endl;


		int vehicle_count{ 0 }; //переменная, изменяемая функцией registration
		int action_choise{ 0 };
		bool permit_start_race{ false };

		Vehicle** vehicle_arr = new Vehicle* [7] {nullptr}; //массив указателей на базовый класс участников


		while (1)
		{
			std::cout << "На гонку должно быть зарегистрировано не менее 2 участников." << std::endl;
			std::cout << "1. Зарегистрировать участника." << std::endl;

			if (vehicle_count >= 2) { std::cout << "2. Начать гонку." << std::endl; permit_start_race = true; }

			std::cout << "Введите команду: ";
			action_choise = 0;
			std::cin >> action_choise;
			std::cout << std::endl;

			if (action_choise == 1)
			{
				registration(vehicle_arr, static_cast<TypeOfVehicle>(race_type), race_distance, vehicle_count);
			}
			else if (action_choise == 2 && permit_start_race)
			{
				std::cout << "Гонка началась!" << std::endl;
				std::cout << std::endl;
				std::cout << "Результаты гонки:" << std::endl;

				race(vehicle_arr, vehicle_count, race_distance);

				std::cout << std::endl;
				std::cout << "1. Провести ещё одну гонку." << std::endl;
				std::cout << "2. Выйти." << std::endl;
				std::cout << "Выберите действие: ";

				action_choise = 0;
				std::cin >> action_choise;
				std::cout << std::endl;

				if		(action_choise == 1) { break; }
				else if (action_choise == 2)
				{
					end_race = true;
					break;
				}
				else { std::cout << "Неверная команда!" << std::endl; }

			}
			else { std::cout << "Неверная команда!" << std::endl; }

		}
	}

	return EXIT_SUCCESS;
}

