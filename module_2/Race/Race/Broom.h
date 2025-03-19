#include"AirVehicle.h"

#pragma once

namespace vehicles
{
	class Broom : public AirVehicle
	{
	public:
		Broom();

		float FinishTime(float distance) override;
	};
}


