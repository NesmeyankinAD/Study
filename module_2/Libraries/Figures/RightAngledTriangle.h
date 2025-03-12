#include"Triangle.h"

#pragma once

namespace figure
{

	class RightAngledTriangle : public Triangle
	{
		//Прямоугольный треугольник - угол С всегда равен 90
	
	public:	
		RightAngledTriangle(int a, int b, int c, int A, int B);
	
		void PrintInfo() override;
	};

}


