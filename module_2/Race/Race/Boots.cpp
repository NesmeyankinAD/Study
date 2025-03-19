#include"Boots.h"

using namespace vehicles;


Boots::Boots() : GroundVehicle("Ботинки-вездеходы", 6, 60) {};

float Boots::FinishTime(float distance)
{
	float temp_finish_time{ 0 };

	temp_finish_time = distance / (this->speed);

	if (temp_finish_time >= (this->travel_time))
	{
		int rest_num{ static_cast<int>(floor(temp_finish_time / this->travel_time)) };

		for (int i = 1; i <= rest_num; i++)
		{
			if (temp_finish_time == travel_time) break;

			if (i == 1)	temp_finish_time += this->first_rest_time;
			else		temp_finish_time += this->other_rest_time;
		}
	}

	return temp_finish_time;
}