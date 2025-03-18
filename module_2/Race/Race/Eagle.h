#include"AirVehicle.h"

#pragma once

namespace vehicles
{
	class Eagle : public AirVehicle
	{
	public:
		Eagle();

		void FinishTime(float distance) override;
	};
}