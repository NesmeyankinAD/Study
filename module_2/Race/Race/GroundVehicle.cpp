#include"GroundVehicle.h"

using namespace vehicles;

GroundVehicle::GroundVehicle(std::string name, float speed, float travel_time) : Vehicle(TypeOfVehicle::ground, name, speed)
{
	this->travel_time = travel_time;
};