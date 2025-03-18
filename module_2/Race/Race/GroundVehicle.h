#include"Vehicle.h"

#pragma once

namespace vehicles 
{
	class GroundVehicle : public Vehicle
	{
	private:
		float travel_time{0};	//время движения до отдыха
								//длительности и количество перерывов - в наследниках

	public:
		GroundVehicle(std::string name, float speed, float travel_time);

	};
}
