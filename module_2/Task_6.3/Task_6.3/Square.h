#include"Rectangle.h"

#pragma once

namespace FIGURE
{

	class Square : public Rectangle
	{
		// вадрат - стороны равны, углы по 90
	
	public:
		Square();
	
		Square(int a);
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}


