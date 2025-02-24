#include"Parallelogram.h"

#pragma once

namespace FIGURE
{

	class Rectangle : public Parallelogram
	{
		//Прямоугольник - стороны a=c, b=d, углы по 90
	
	public:
		Rectangle();
	
		Rectangle(int a, int b);
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}


