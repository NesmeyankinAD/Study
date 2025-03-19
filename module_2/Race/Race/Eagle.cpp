#include"Eagle.h"

using namespace vehicles;


Eagle::Eagle() : AirVehicle("Îğ¸ë", 8) {};

float Eagle::FinishTime(float distance)
{
	return ((1 - 0.06) * distance) / this->speed;
}