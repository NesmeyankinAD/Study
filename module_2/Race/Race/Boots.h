#include"GroundVehicle.h"

#pragma once

namespace vehicles
{
	class Boots : public GroundVehicle
	{
	private:
		const float first_rest_time = 10;
		const float other_rest_time = 5;

	public:
		Boots();

		float FinishTime(float distance) override;
	};
}