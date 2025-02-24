#include"Triangle.h"

#pragma once

namespace FIGURE
{

	class RightAngledTriangle : public Triangle
	{
		//Прямоугольный треугольник - угол С всегда равен 90
	
	public:
		RightAngledTriangle();
	
		RightAngledTriangle(int a, int b, int c, int A, int B);
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}


