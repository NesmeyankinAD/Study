#include<iostream>
#include<Windows.h>

#include"Vehicle.h"
#include"GroundVehicle.h"
#include"AirVehicle.h"
#include"Camel.h"
#include"FastCamel.h"
#include"Centaur.h"
#include"Boots.h"
#include"MagicCarpet.h"
#include"Eagle.h"
#include"Broom.h"

using namespace vehicles;


Vehicle** general_registration(TypeOfVehicle type_race,float distance)
{
	int choise[]{0};
	bool end_registration{ false };
	int vehicle_count{ 0 };

	Vehicle** vehicle_arr = new Vehicle* [7];

	for(int i = 0; !end_registration; i++)
	{
		if(i == 7) 
		{
			std::cout << "Зарегистрированы все возможные участники!" << std::endl;
			end_registration = true;
			break;
		}


		std::cout << "Гонка для наземного транспорта. Дистанция: " << distance << "." << std::endl;

		std::cout << "Зарегистрированные участники: "; // вызвать функцию вывода участников, перебрать массив указателей->get_name()

		std::cout << "1. Верблюд." << std::endl;
		std::cout << "2. Верблюд-быстроход." << std::endl;
		std::cout << "3. Кентавр." << std::endl;
		std::cout << "4. Ботинки-вездеходы." << std::endl;
		std::cout << "5. Ковёр-самолёт." << std::endl;
		std::cout << "6. Орёл." << std::endl;
		std::cout << "7. Метла." << std::endl;
		std::cout << "0. Закончить регистрацию." << std::endl;

		std::cout << "Выберите участника или 0 для окончания регистрации: ";
		std::cin >> choise[i];

		bool same_vehicle{ false }; //нахождение дублей
		for (int j = 0; j < i; j++)
		{
			if (choise[i] == choise[j])
			{
				std::cout << vehicle_arr[j]->get_name() + " уже зарегистрирован!" << std::endl;
				same_vehicle = true;
				break;
			}
		}
		if (same_vehicle) continue;


		if (choise[i] == 0) { end_registration = true; } //создаем регистрируемые объекты и кладём ссылки на них в массив

		else if (choise[i] == 1 && (type_race != TypeOfVehicle::air))
		{
			Camel camel; 
			vehicle_arr[i] = &camel;
			
			vehicle_count++;
		}
		else if (choise[i] == 2 && (type_race != TypeOfVehicle::air))
		{
			FastCamel fast_camel; 
			vehicle_arr[i] = &fast_camel;

			vehicle_count++;
		}
		else if (choise[i] == 3 && (type_race != TypeOfVehicle::air))
		{
			Centaur centaur; 
			vehicle_arr[i] = &centaur;

			vehicle_count++;
		}
		else if (choise[i] == 4 && (type_race != TypeOfVehicle::air))
		{
			Boots boots;
			vehicle_arr[i] = &boots;
			
			vehicle_count++;
		}
		else if (choise[i] == 5 && (type_race != TypeOfVehicle::ground))
		{
			MagicCarpet carpet; 
			vehicle_arr[i] = &carpet;
			
			vehicle_count++;
		}
		else if (choise[i] == 6 && (type_race != TypeOfVehicle::ground))
		{
			Eagle eagle; 
			vehicle_arr[i] = &eagle;

			vehicle_count++;
		}
		else if (choise[i] == 7 && (type_race != TypeOfVehicle::ground))
		{
			Broom broom;
			vehicle_arr[i] = &broom;

			vehicle_count++;
		}
		else 
		{
			std::cout << "Попытка зарегистрировать участника, не соответствующего типу гонки!";
			//ещё сценарии
		}
	}
	

}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);



	vehicles::Camel camel;
	vehicles::FastCamel fast_camel;
	vehicles::Centaur centaur;
	vehicles::Boots boots;
	vehicles::MagicCarpet carpet;
	vehicles::Eagle eagle;
	vehicles::Broom broom;

	std::cout << camel.get_name() << camel.FinishTime(700) << std::endl;

	std::cout << fast_camel.get_name() << fast_camel.FinishTime(1200) << std::endl;

	std::cout << centaur.get_name() << centaur.FinishTime(300) << std::endl;

	std::cout << boots.get_name() << boots.FinishTime(1000) << std::endl;

	std::cout << carpet.get_name() << carpet.FinishTime(10001) << std::endl;

	std::cout << eagle.get_name() << eagle.FinishTime(1000) << std::endl;

	std::cout << broom.get_name() << broom.FinishTime(2500) << std::endl;



	//опрос пользователя: выбор типа гонки, получение дистанции, регистрация на гонку

	int race{0};
	float race_distance{0.0};

	std::cout << "Добро пожаловать в симулятор гонок!" << std::endl;
	std::cout << "1. Гонка для наземного транспорта." << std::endl;
	std::cout << "2. Гонка для воздушного транспорта." << std::endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта." << std::endl;
	std::cout << "Выберите тип гонки: ";
	std::cin >> race;

	bool right_race_distance{0};
	while (!right_race_distance)
	{
		std::cout << "Введите дистанцию гонки: ";
		std::cin >> race_distance;
		if (race_distance <= 0) std::cout << "Дистанция должна быть положительна!" << std::endl;
		else right_race_distance = true;
	}

	int vehicle_count{0};
	bool start_race{false};

	std::cout << "На гонку должно быть зарегистрировано не менее 2 участников." << std::endl;
	std::cout << "1. Зарегистрировать участника." << std::endl;

	if (vehicle_count >= 2) { std::cout << "2. Начать гонку." << std::endl; start_race = true;}


	switch (race)
	{
	case 1: //ground break;
	case 2:	//air break;
	case 3: //general break;
	}




	//создание зарегистрированных объектов

	//выделение динамической памяти под хранение результатов, заполнение памяти

	//сортировка 

	//вывод результатов

	return EXIT_SUCCESS;
}

