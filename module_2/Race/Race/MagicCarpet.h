#include"AirVehicle.h"

#pragma once

namespace vehicles
{
	class MagicCarpet : public AirVehicle
	{
	public:
		MagicCarpet();

		void FinishTime(float distance) override;
	};
}
