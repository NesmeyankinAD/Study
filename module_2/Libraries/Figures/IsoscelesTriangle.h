#include"Triangle.h"

#pragma once

namespace figure
{
	class IsoscelesTriangle : public Triangle
	{
		//Равнобедренный треугольник - стороны a=c, углы A=C
	
	public:	
		IsoscelesTriangle(int a, int b, int A, int B);
	
		void PrintInfo() override;
	};
}


