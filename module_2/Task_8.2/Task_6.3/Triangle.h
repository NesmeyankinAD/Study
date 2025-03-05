#include"Figure.h"

#pragma once

namespace figure
{
	class Triangle : public Figure
	{
	private:
		int a, b, c; //sides

	public:
		int Get_a();
		int Get_b();
		int Get_c();


	private:
		int A, B, C; //angles

	public:
		int Get_A();
		int Get_B();
		int Get_C();

	public:
		Triangle(int a, int b, int c, int A, int B, int C);

		void PrintInfo() override;
	};
}


