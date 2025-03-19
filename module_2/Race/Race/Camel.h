#include"GroundVehicle.h"

#pragma once

namespace vehicles
{
	class Camel : public GroundVehicle
	{
	private:
		const float first_rest_time = 5;
		const float other_rest_time = 8;

	public:
		Camel();

		float FinishTime(float distance) override;
	};
}
