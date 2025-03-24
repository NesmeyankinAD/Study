#include<iostream>
#include"VehiclesEnvironment.h"

using namespace vehicles;

vehicles::Camel			camel;
vehicles::FastCamel		fast_camel;
vehicles::Centaur		centaur;
vehicles::Boots			boots;
vehicles::MagicCarpet	carpet;
vehicles::Eagle			eagle;
vehicles::Broom			broom;

std::string vehicles::print_vehicles(Vehicle** vehicle_arr, int& vehicle_count)
{
	std::string print;

	for (int i = 0; i < vehicle_count; i++)
	{
		print += vehicle_arr[i]->get_name();
		print += " ";
	}
	return print;
}

void vehicles::registration(Vehicle** vehicle_arr, TypeOfVehicle type_race, float& distance, int& vehicle_count)
{
	//vehicle_arr	- внешний массив указателей типа Vehicle*, хранит ссылки на зарегистрированных участников, изменяется функцией
	//type_race		- тип гонки, перечисление vehicles::TypeOfVehicle
	//distance		- дистанция гонки
	//vehicle_count - количество участников гонки, изменяемая функцией внешняя переменная.

	static int choise[20]{ 0 };

	bool end_registration{ false };


	for (int i = vehicle_count; !end_registration; i++)
	{
		std::cout << "Гонка для наземного транспорта. Дистанция: " << distance << "." << std::endl;

		std::cout << "Зарегистрированные участники: " << print_vehicles(vehicle_arr, vehicle_count) << std::endl;

		std::cout << "1. Верблюд." << std::endl;
		std::cout << "2. Верблюд-быстроход." << std::endl;
		std::cout << "3. Кентавр." << std::endl;
		std::cout << "4. Ботинки-вездеходы." << std::endl;
		std::cout << "5. Ковёр-самолёт." << std::endl;
		std::cout << "6. Орёл." << std::endl;
		std::cout << "7. Метла." << std::endl;
		std::cout << "0. Закончить регистрацию." << std::endl;
		std::cout << std::endl;

		std::cout << "Выберите участника или 0 для окончания регистрации: ";
		std::cin >> choise[i];
		std::cout << std::endl;

		bool same_vehicle{ false }; //нахождение дублей
		for (int j = 0; j < i; j++)
		{
			if ((choise[i] == choise[j]) && (choise[i] != 0))
			{
				std::cout << vehicle_arr[j]->get_name() + " уже зарегистрирован!" << std::endl;
				std::cout << std::endl;
				i--;
				same_vehicle = true;
				break;
			}
		}
		if (same_vehicle) continue;


		if (choise[i] == 0) { end_registration = true; } //кладём ссылки участников в массив указателей на базовый класс

		else if (choise[i] == 1 && (type_race != TypeOfVehicle::air))
		{
			//Camel 
			vehicle_arr[i] = &camel;

			vehicle_count++;
		}
		else if (choise[i] == 2 && (type_race != TypeOfVehicle::air))
		{
			//FastCamel 
			vehicle_arr[i] = &fast_camel;

			vehicle_count++;
		}
		else if (choise[i] == 3 && (type_race != TypeOfVehicle::air))
		{
			//Centaur 
			vehicle_arr[i] = &centaur;

			vehicle_count++;
		}
		else if (choise[i] == 4 && (type_race != TypeOfVehicle::air))
		{
			//Boots
			vehicle_arr[i] = &boots;

			vehicle_count++;
		}
		else if (choise[i] == 5 && (type_race != TypeOfVehicle::ground))
		{
			//MagicCarpet
			vehicle_arr[i] = &carpet;

			vehicle_count++;
		}
		else if (choise[i] == 6 && (type_race != TypeOfVehicle::ground))
		{
			//Eagle 
			vehicle_arr[i] = &eagle;

			vehicle_count++;
		}
		else if (choise[i] == 7 && (type_race != TypeOfVehicle::ground))
		{
			//Broom
			vehicle_arr[i] = &broom;

			vehicle_count++;
		}
		else
		{
			std::cout << "Неверная команда или попытка зарегистрировать участника, не соответствующего типу гонки!" << std::endl;
			std::cout << std::endl;

			i--;

			if (vehicle_count == 4 && type_race == TypeOfVehicle::ground)
			{
				std::cout << "Для наземной гонки зарегистрированы все возможные участники!\n" << std::endl;
				end_registration = true;
			}

			if (vehicle_count == 3 && type_race == TypeOfVehicle::air)
			{
				std::cout << "Для воздушной гонки зарегистрированы все возможные участники!\n" << std::endl;
				end_registration = true;
			}

			if (vehicle_count == 3 && type_race == TypeOfVehicle::undef)
			{
				std::cout << "Для гонки зарегистрированы все возможные участники!\n" << std::endl;
				end_registration = true;
			}
		}
	}
}

void vehicles::sort(Vehicle** vehicle_arr, int& vehicle_count, float& race_distance)
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = vehicle_count - 1; i > 0; i--)
		{
			if ((vehicle_arr[i - 1]->FinishTime(race_distance)) > (vehicle_arr[i]->FinishTime(race_distance)))
			{
				Vehicle* temp = vehicle_arr[i - 1];

				vehicle_arr[i - 1] = vehicle_arr[i];
				vehicle_arr[i] = temp;
				swapped = true;
			}
		}
	} while (swapped);
}

void vehicles::race(Vehicle** vehicle_arr, int& vehicle_count, float& race_distance)
{
	vehicles::sort(vehicle_arr, vehicle_count, race_distance);

	for (int i = 0; i < vehicle_count; i++) //вывод в консоль
	{
		std::cout << (i + 1) << "." << vehicle_arr[i]->get_name() << " " << vehicle_arr[i]->FinishTime(race_distance) << std::endl;
	}
}