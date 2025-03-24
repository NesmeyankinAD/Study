#include "Broom.h"

using namespace vehicles;

Broom::Broom() : AirVehicle("Метла", 20) {};

float Broom::FinishTime(float distance)
{
	float reduce_coef{ static_cast<float>(0.01 * floor(distance / 1000.0)) };

	return ((1.0 - reduce_coef) * distance) / this->speed;
}

