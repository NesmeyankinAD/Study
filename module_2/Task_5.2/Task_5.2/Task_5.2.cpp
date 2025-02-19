#include<iostream>
#include<Windows.h>
#include<string>

namespace FIGURE 
{
	class Figure
	{
	private:
		int QuantitySides;

	protected:
		std::string Name;

	protected:
		Figure(int InitQuantitySides)
		{
			this->QuantitySides = InitQuantitySides;
		};

	public:
		Figure() : Figure(0)
		{
			this->Name = "Фигура";
		};

		int GetQuantitySides()
		{
			return this->QuantitySides;
		}

		std::string GetName()
		{
			return this->Name;
		}
	};

	class Triangle : public Figure
	{
	public:
		struct Sides
		{
		private:
			int a, b, c;

		public:
			int Get_a() { return this->a; }

			int Get_b() { return this->b; }

			int Get_c() { return this->c; }

			Sides(int a, int b, int c)
			{
				this->a = a;
				this->b = b;
				this->c = c;
			};

			Sides()
			{
				this->a = 0;
				this->b = 0;
				this->c = 0;
			};
		};

		struct Angles
		{
		private:
			int A, B, C;

		public:
			int Get_A() { return this->A; }

			int Get_B() { return this->B; }

			int Get_C() { return this->C; }

			Angles(int A, int B, int C)
			{
				this->A = A;
				this->B = B;
				this->C = C;
			};

			Angles()
			{
				this->A = 0;
				this->B = 0;
				this->C = 0;
			};
		};

		Sides sides;
		Angles angles;

	public:
		Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
		{
			this->Name = "Треугольник";

			sides = Sides(a, b, c);
			angles = Angles(A, B, C);

		};

		Triangle() : Figure(3)
		{
			this->Name = "Треугольник";
		};

	public:
		//virtual void PrintInfo()
		//{
		//	std::cout << this->Name << std::endl;
		//
		//	std::cout << "a = " << this->sides.Get_a() << ", ";
		//	std::cout << "b = " << this->sides.Get_b() << ", ";
		//	std::cout << "c = " << this->sides.Get_c() << std::endl;
		//
		//	std::cout << "A = " << this->angles.Get_A() << ", ";
		//	std::cout << "B = " << this->angles.Get_B() << ", ";
		//	std::cout << "C = " << this->angles.Get_C() << std::endl;
		//}
	};

	class RightAngledTriangle : public Triangle
	{
		//Прямоугольный треугольник - угол С всегда равен 90

	public:
		RightAngledTriangle() : Triangle(0, 0, 0, 0, 0, 90) { this->Name = "Прямоугольный треугольник"; };

		RightAngledTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) { this->Name = "Прямоугольный треугольник"; };
	};

	class IsoscelesTriangle : public Triangle
	{
		//Равнобедренный треугольник - стороны a=c, углы A=C

	public:
		IsoscelesTriangle() : Triangle(1, 0, 1, 1, 0, 1) { this->Name = "Равнобедренный треугольник"; };

		IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) { this->Name = "Равнобедренный треугольник"; };
	};

	class EquilateralTriangle : public IsoscelesTriangle
	{
		//Равносторонний треугольник - все стороны равны, все углы равны 60

	public:
		EquilateralTriangle() : IsoscelesTriangle(1, 1, 60, 60) { this->Name = "Равносторонний треугольник"; };

		EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60) { this->Name = "Равносторонний треугольник"; };

	};

	class Quadrangle : public Figure
	{
	public:
		struct Sides
		{
		private:
			int a, b, c, d;

		public:
			int Get_a() { return this->a; }

			int Get_b() { return this->b; }

			int Get_c() { return this->c; }

			int Get_d() { return this->d; }

			Sides(int a, int b, int c, int d)
			{
				this->a = a;
				this->b = b;
				this->c = c;
				this->d = d;
			};

			Sides()
			{
				this->a = 0;
				this->b = 0;
				this->c = 0;
				this->d = 0;
			};
		};

		struct Angles
		{
		private:
			int A, B, C, D;

		public:
			int Get_A() { return this->A; }

			int Get_B() { return this->B; }

			int Get_C() { return this->C; }

			int Get_D() { return this->D; }

			Angles(int A, int B, int C, int D)
			{
				this->A = A;
				this->B = B;
				this->C = C;
				this->D = D;
			};

			Angles()
			{
				this->A = 0;
				this->B = 0;
				this->C = 0;
				this->D = 0;
			};
		};

		Sides sides;
		Angles angles;

	public:
		Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
		{
			this->Name = "Четырёхугольник";

			sides = Sides(a, b, c, d);
			angles = Angles(A, B, C, D);

		};

		Quadrangle() : Figure(4)
		{
			this->Name = "Четырёхугольник";
		};

	};

	class Parallelogram : public Quadrangle
	{
		//Параллелограмм - стороны a=c, b=d, углы A=C, B=D

	public:
		Parallelogram() : Quadrangle(1, 0, 1, 0, 1, 0, 1, 0) { this->Name = "Параллелограмм"; };

		Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) { this->Name = "Параллелограмм"; };
	};

	class Rhomb : public Parallelogram
	{
		//Ромб - стороны равны, углы A=C, B=D

	public:
		Rhomb() : Parallelogram(1, 1, 0, 0) { this->Name = "Ромб"; };

		Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) { this->Name = "Ромб"; };
	};

	class Rectangle : public Parallelogram
	{
		//Прямоугольник - стороны a=c, b=d, углы по 90

	public:
		Rectangle() : Parallelogram(1, 0, 90, 90) { this->Name = "Прямоугольник"; };

		Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) { this->Name = "Прямоугольник"; };
	};

	class Square : public Rectangle
	{
		//Квадрат - стороны равны, углы по 90

	public:
		Square() : Rectangle(1, 1) { this->Name = "Квадрат"; };

		Square(int a) : Rectangle(a, a) { this->Name = "Квадрат"; };
	};


	void PrintInfoTriangle(Triangle* triangle)
	{
		std::cout << triangle->GetName() << std::endl;

		std::cout << "Стороны: ";
		std::cout << "a = " << triangle->sides.Get_a() << ", ";
		std::cout << "b = " << triangle->sides.Get_b() << ", ";
		std::cout << "c = " << triangle->sides.Get_c() << std::endl;

		std::cout << "Углы: ";
		std::cout << "A = " << triangle->angles.Get_A() << ", ";
		std::cout << "B = " << triangle->angles.Get_B() << ", ";
		std::cout << "C = " << triangle->angles.Get_C() << std::endl;
		std::cout << std::endl;
	}

	void PrintInfoQuadrangle(Quadrangle* quadrangle)
	{
		std::cout << quadrangle->GetName() << std::endl;

		std::cout << "Стороны: ";
		std::cout << "a = " << quadrangle->sides.Get_a() << ", ";
		std::cout << "b = " << quadrangle->sides.Get_b() << ", ";
		std::cout << "c = " << quadrangle->sides.Get_c() << ", ";
		std::cout << "d = " << quadrangle->sides.Get_d() << std::endl;

		std::cout << "Углы: ";
		std::cout << "A = " << quadrangle->angles.Get_A() << ", ";
		std::cout << "B = " << quadrangle->angles.Get_B() << ", ";
		std::cout << "C = " << quadrangle->angles.Get_C() << ", ";
		std::cout << "C = " << quadrangle->angles.Get_D() << std::endl;
		std::cout << std::endl;
	}
}

using namespace FIGURE;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	Triangle triangle(1,2,3,4,5,6);		//создаём экземпляр
	
	Triangle* p_triangle = &triangle;	//создаём указатель на базовый класс = ссылка на экземпляр

	PrintInfoTriangle(p_triangle);		//передаём в функцию указатель на базовый класс экземпляра


	RightAngledTriangle right_angled_triangle(1, 2, 3, 50, 60); 
	
	Triangle* p_right_angled_triangle = &right_angled_triangle;	

	PrintInfoTriangle(p_right_angled_triangle);					


	IsoscelesTriangle isosceles_triangle(20, 10, 75, 30);		
	
	Triangle* p_isosceles_triangle = &isosceles_triangle;		

	PrintInfoTriangle(p_isosceles_triangle);					


	EquilateralTriangle equilateral_triangle(20);

	Triangle* p_equilateral_triangle = &equilateral_triangle;

	PrintInfoTriangle(p_equilateral_triangle);


	Quadrangle quadrangle(1, 2, 3, 4, 50, 60, 110, 80);

	Quadrangle* p_quadrangle = &quadrangle;

	PrintInfoQuadrangle(p_quadrangle);


	Parallelogram parallelogram(10, 30, 120, 60);

	Quadrangle* p_parallelogram = &parallelogram;

	PrintInfoQuadrangle(p_parallelogram);


	Rhomb rhomb(20, 150, 30);

	Quadrangle* p_rhomb = &rhomb;

	PrintInfoQuadrangle(p_rhomb);


	FIGURE::Rectangle rectangle(10, 20); //существует некая функция Rectangle - конфликт имён

	Quadrangle* p_rectangle = &rectangle;

	PrintInfoQuadrangle(p_rectangle);


	Square square(5);

	Quadrangle* p_square = &square;

	PrintInfoQuadrangle(p_square);



	return EXIT_SUCCESS;
}