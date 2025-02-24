#include"Parallelogram.h"

#pragma once

namespace FIGURE
{

	class Rhomb : public Parallelogram
	{
	//Ромб - стороны равны, углы A=C, B=D
	
	public:
		Rhomb();
	
		Rhomb(int a, int A, int B);
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}


