#include"Parallelogram.h"

#pragma once

namespace figure
{

	class Rectangle : public Parallelogram
	{
		//Прямоугольник - стороны a=c, b=d, углы по 90
	
	public:
		Rectangle(int a, int b);
	
		void PrintInfo() override;
	};

}


