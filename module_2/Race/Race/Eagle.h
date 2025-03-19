#include"AirVehicle.h"

#pragma once

namespace vehicles
{
	class Eagle : public AirVehicle
	{
	public:
		Eagle();

		float FinishTime(float distance) override;
	};
}