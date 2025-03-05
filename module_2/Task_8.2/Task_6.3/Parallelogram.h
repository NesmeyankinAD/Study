#include"Quadrangle.h"

#pragma once

namespace figure
{

	class Parallelogram : public Quadrangle
	{
		//Параллелограмм - стороны a=c, b=d, углы A=C, B=D
	
	public:	
		Parallelogram(int a, int b, int A, int B);
	
		void PrintInfo() override;
	};

}

