#include"Figure.h"

#pragma once

namespace figure
{

	class Quadrangle : public Figure
	{
	private:
		int a, b, c, d;

	public:
		int Get_a();
		int Get_b();
		int Get_c();
		int Get_d();

	private:
		int A, B, C, D;

	public:
		int Get_A();
		int Get_B();
		int Get_C();
		int Get_D();
	
	public:
		Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
	
		void PrintInfo() override;
	};

}

