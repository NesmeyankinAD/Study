#include"Parallelogram.h"

#pragma once

namespace figure
{

	class Rhomb : public Parallelogram
	{
	//Ромб - стороны равны, углы A=C, B=D
	
	public:	
		Rhomb(int a, int A, int B);
	
		void PrintInfo() override;
	};

}


