#include"Figure.h"

#pragma once

namespace FIGURE
{
	class Triangle : public Figure
	{
	public:
		struct Sides
		{
		private:
			int a, b, c;

		public:
			int Get_a();
			int Get_b();
			int Get_c();

			Sides(int a, int b, int c);

			Sides();
		};

		struct Angles
		{
		private:
			int A, B, C;

		public:
			int Get_A();
			int Get_B();
			int Get_C();

			Angles(int A, int B, int C);

			Angles();
		};

		Sides sides;
		Angles angles;

	public:
		Triangle(int a, int b, int c, int A, int B, int C);

		Triangle();

	public:
		bool CheckFigure() override;

		void PrintInfo() override;
	};
}


