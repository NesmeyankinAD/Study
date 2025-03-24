#include"Centaur.h"

using namespace vehicles;


Centaur::Centaur() : GroundVehicle("Кентавр", 15, 8) {};

float Centaur::FinishTime(float distance)
{
	float temp_finish_time{ 0 };

	temp_finish_time = distance / (this->speed);

	if (temp_finish_time >= (this->travel_time))
	{
		int rest_num{ static_cast<int>(floor(temp_finish_time / this->travel_time)) };

		for (int i = 1; i <= rest_num; i++)
		{
			if (temp_finish_time == travel_time) break;

			temp_finish_time += this->rest_time;
		}
	}

	return temp_finish_time;
}