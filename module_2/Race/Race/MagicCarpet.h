#include"AirVehicle.h"

#pragma once

namespace vehicles
{
	class MagicCarpet : public AirVehicle
	{
	public:
		MagicCarpet();

		float FinishTime(float distance) override;
	};
}
