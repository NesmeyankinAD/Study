#include"Vehicle.h"

using namespace vehicles;

Vehicle::Vehicle()
{
	this->speed = 0;
	this->type = TypeOfVehicle::undef;
	this->name_str = "";
	FinishTime(0);
}

Vehicle::Vehicle(TypeOfVehicle type, std::string name, float speed)
{
	this->type = type;
	this->name_str = name;
	this->speed = speed;
}

void Vehicle::FinishTime(float distance)
{
	this->finish_time = 0;
}

std::string Vehicle::get_name()
{
	return this->name_str;
}