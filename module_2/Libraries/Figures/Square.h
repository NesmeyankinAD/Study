#include"Rectangle.h"

#pragma once

namespace figure
{

	class Square : public Rectangle
	{
		// вадрат - стороны равны, углы по 90
	
	public:
		Square(int a);
	
		void PrintInfo() override;
	};

}


