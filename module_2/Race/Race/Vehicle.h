#include<string>

#pragma once

//#ifdef VEHICLE_EXPORTS
//#define VEHICLE_API __declspec(dllexport)
//#else
//#define VEHICLE_API __declspec(dllimport)
//#endif

namespace vehicles
{
	enum class TypeOfVehicle
	{
		undef = 0,
		ground = 1,
		air = 2
	};

	class Vehicle
	{
	public:
		TypeOfVehicle type;

	private:
		std::string name_str;

		float speed{0};
		float finish_time{0};

	protected:
		Vehicle();

		Vehicle(TypeOfVehicle type, std::string name, float speed);

	public:
		virtual void FinishTime(float distance);

		std::string get_name();
	};
}

