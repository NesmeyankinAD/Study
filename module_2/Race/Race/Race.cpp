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


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	using namespace vehicles;


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

	//создание зарегистрированных объектов

	//выделение динамической памяти под хранение результатов, заполнение памяти

	//сортировка 

	//вывод результатов

	return EXIT_SUCCESS;
}

