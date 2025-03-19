#include"AirVehicle.h"

using namespace vehicles;

AirVehicle::AirVehicle(std::string name, float speed) : Vehicle(TypeOfVehicle::air, name, speed) {};

float AirVehicle::FinishTime(float distance)
{
	return 0.0;
}
