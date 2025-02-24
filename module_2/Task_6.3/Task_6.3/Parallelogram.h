#include"Quadrangle.h"

#pragma once

namespace FIGURE
{

	class Parallelogram : public Quadrangle
	{
		//Параллелограмм - стороны a=c, b=d, углы A=C, B=D
	
	public:
		Parallelogram();
	
		Parallelogram(int a, int b, int A, int B);
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}

