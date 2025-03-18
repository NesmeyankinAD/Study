#include"GroundVehicle.h"

#pragma once

namespace vehicles
{
	class FastCamel : public GroundVehicle
	{
	private:
		const float first_rest_time = 5;
		const float second_rest_time = 6.5;
		const float other_rest_time = 8;

	public:
		FastCamel();

		void FinishTime(float distance) override;
	};
}
