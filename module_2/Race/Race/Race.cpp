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


	Camel camel;
	vehicles::FastCamel fast_camel;
	Centaur centaur;
	Boots boots;
	MagicCarpet carpet;
	Eagle eagle;
	Broom broom;

	std::cout << camel.get_name()<< std::endl;
	std::cout << fast_camel.get_name() << std::endl;
	std::cout << centaur.get_name() << std::endl;
	std::cout << boots.get_name()<< std::endl;
	std::cout << carpet.get_name() << std::endl;
	std::cout << eagle.get_name() << std::endl;
	std::cout << broom.get_name() << std::endl;

	return EXIT_SUCCESS;
}

