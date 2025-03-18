#include"AirVehicle.h"

#pragma once

namespace vehicles
{
	class Broom : public AirVehicle
	{
	public:
		Broom();

		void FinishTime(float distance) override;
	};
}


