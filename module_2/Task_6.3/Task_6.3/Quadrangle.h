#include"Figure.h"

#pragma once

namespace FIGURE
{

	class Quadrangle : public Figure
	{
	public:
		struct Sides
		{
		private:
			int a, b, c, d;
	
		public:
			int Get_a();
			int Get_b();
			int Get_c();
			int Get_d();
	
			Sides(int a, int b, int c, int d);
	
			Sides();
		};
	
		struct Angles
		{
		private:
			int A, B, C, D;
	
		public:
			int Get_A();
			int Get_B();
			int Get_C();
			int Get_D();
	
			Angles(int A, int B, int C, int D);
	
			Angles();
		};
	
		Sides sides;
		Angles angles;
	
	public:
		Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
	
		Quadrangle();
	
		bool CheckFigure() override;
	
		void PrintInfo() override;
	};

}

