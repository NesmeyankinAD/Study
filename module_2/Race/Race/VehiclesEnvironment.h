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

#pragma once



namespace vehicles
{
	void registration(Vehicle** vehicle_arr, TypeOfVehicle type_race, float& distance, int& vehicle_count);

	std::string print_vehicles(Vehicle** arr, int& vehicle_count);

	void sort(Vehicle** vehicle_arr, int& vehicle_count, float& race_distance);

	void race(Vehicle** vehicle_arr, int& vehicle_count, float& race_distance);
}