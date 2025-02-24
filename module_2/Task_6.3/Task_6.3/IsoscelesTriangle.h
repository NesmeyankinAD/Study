#include"Triangle.h"

#pragma once

namespace FIGURE
{

	class IsoscelesTriangle : public Triangle
	{
		//Равнобедренный треугольник - стороны a=c, углы A=C
	
	public:
		IsoscelesTriangle();
	
		IsoscelesTriangle(int a, int b, int A, int B);
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}


