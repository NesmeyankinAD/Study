#include"IsoscelesTriangle.h"

#pragma once

namespace figure
{

	class EquilateralTriangle : public IsoscelesTriangle
	{
		//Равносторонний треугольник - все стороны равны, все углы равны 60
	
	public:	
		EquilateralTriangle(int a);
	
		void PrintInfo() override;
	};

}



