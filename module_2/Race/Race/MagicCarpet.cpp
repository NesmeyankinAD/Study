#include"MagicCarpet.h"

using namespace vehicles;


MagicCarpet::MagicCarpet() : AirVehicle("Ковёр-самолёт", 10) {};

float MagicCarpet::FinishTime(float distance)
{
	float temp_finish_time{ 0 };

	if		(distance < 1000)	{ temp_finish_time = distance / this->speed; }
	else if (distance < 5000)	{ temp_finish_time = ((1 - 0.03) * distance) / this->speed; }
	else if (distance < 10000)	{ temp_finish_time = ((1 - 0.1) * distance) / this->speed; }
	else						{ temp_finish_time = ((1 - 0.05) * distance) / this->speed; }

	return temp_finish_time;
}