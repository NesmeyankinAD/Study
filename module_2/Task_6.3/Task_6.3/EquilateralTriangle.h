#include"IsoscelesTriangle.h"

#pragma once

namespace FIGURE
{

	class EquilateralTriangle : public IsoscelesTriangle
	{
		//Равносторонний треугольник - все стороны равны, все углы равны 60
	
	public:
		EquilateralTriangle();
	
		EquilateralTriangle(int a);
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}



