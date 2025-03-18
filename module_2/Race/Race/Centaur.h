#include"GroundVehicle.h"

#pragma once

namespace vehicles
{
	class Centaur : public GroundVehicle
	{
	private:
		const float rest_time = 2;

	public:
		Centaur();

		void FinishTime(float distance) override;
	};
}
