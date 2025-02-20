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
	
		virtual bool CheckFigure()
		{
			return true;
		}

		virtual void PrintInfo() 
		{
			std::cout << std::endl;
			std::cout << this->GetName() << std::endl;

			if(this->CheckFigure()) std::cout << "Правильная фигура" << std::endl;
			else					std::cout << "Неправильная фигура" << std::endl;

			std::cout << "Количество сторон: " << this->GetQuantitySides() << std::endl;
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
		bool CheckFigure() override
		{
			if (this->sides.Get_a() == 0 ||
				this->sides.Get_b() == 0 || 
				this->sides.Get_c() == 0 || 
				(this->angles.Get_A() + this->angles.Get_B() + this->angles.Get_C() != 180) )
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		void PrintInfo() override
		{
			Figure::PrintInfo();

			std::cout << "Стороны: ";
			std::cout << "a = " << this->sides.Get_a() << ", ";
			std::cout << "b = " << this->sides.Get_b() << ", ";
			std::cout << "c = " << this->sides.Get_c() << std::endl;
		
			std::cout << "Углы: ";
			std::cout << "A = " << this->angles.Get_A() << ", ";
			std::cout << "B = " << this->angles.Get_B() << ", ";
			std::cout << "C = " << this->angles.Get_C() << std::endl;
		}
	};

	class RightAngledTriangle : public Triangle
	{
		//Прямоугольный треугольник - угол С всегда равен 90

	public:
		RightAngledTriangle() : Triangle(0, 0, 0, 0, 0, 90) { this->Name = "Прямоугольный треугольник"; };

		RightAngledTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) { this->Name = "Прямоугольный треугольник"; };

		bool CheckFigure() override
		{
			if (Triangle::CheckFigure() && this->angles.Get_C() == 90) return true;
			
			else return false;
		}

		void PrintInfo() override
		{
			Triangle::PrintInfo();
		}
	};

	class IsoscelesTriangle : public Triangle
	{
		//Равнобедренный треугольник - стороны a=c, углы A=C

	public:
		IsoscelesTriangle() : Triangle(1, 0, 1, 1, 0, 1) { this->Name = "Равнобедренный треугольник"; };

		IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) { this->Name = "Равнобедренный треугольник"; };

		bool CheckFigure() override
		{
			if (Triangle::CheckFigure()) return true; //без иных условий, равенство a=c и A=C заложено в конструкторе

			else return false;
		}

		void PrintInfo() override
		{
			Triangle::PrintInfo();
		}
	};

	class EquilateralTriangle : public IsoscelesTriangle
	{
		//Равносторонний треугольник - все стороны равны, все углы равны 60

	public:
		EquilateralTriangle() : IsoscelesTriangle(1, 1, 60, 60) { this->Name = "Равносторонний треугольник"; };

		EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60) { this->Name = "Равносторонний треугольник"; };

		bool CheckFigure() override
		{
			if (Triangle::CheckFigure()) return true; //без иных условий, равенство сторон и углы по 60 заложены в конструкторе

			else return false;
		}

		void PrintInfo() override
		{
			Triangle::PrintInfo();
		}
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

		bool CheckFigure() override
		{
			if (this->sides.Get_a() == 0 ||
				this->sides.Get_b() == 0 ||
				this->sides.Get_c() == 0 ||
				this->sides.Get_d() == 0 ||
				(this->angles.Get_A() + this->angles.Get_B() + this->angles.Get_C() + this->angles.Get_D() != 360))
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		void PrintInfo() override
		{
			Figure::PrintInfo();

			std::cout << "Стороны: ";
			std::cout << "a = " << this->sides.Get_a() << ", ";
			std::cout << "b = " << this->sides.Get_b() << ", ";
			std::cout << "c = " << this->sides.Get_c() << ", ";
			std::cout << "d = " << this->sides.Get_d() << std::endl;

			std::cout << "Углы: ";
			std::cout << "A = " << this->angles.Get_A() << ", ";
			std::cout << "B = " << this->angles.Get_B() << ", ";
			std::cout << "C = " << this->angles.Get_C() << ", ";
			std::cout << "D = " << this->angles.Get_D() << std::endl;
		}

	};

	class Parallelogram : public Quadrangle
	{
		//Параллелограмм - стороны a=c, b=d, углы A=C, B=D

	public:
		Parallelogram() : Quadrangle(1, 0, 1, 0, 1, 0, 1, 0) { this->Name = "Параллелограмм"; };

		Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) { this->Name = "Параллелограмм"; };

		bool CheckFigure() override
		{
			if (Quadrangle::CheckFigure()) return true; //попарное равенство сторон и углов заложено в конструкторе

			else return false;
		}

		void PrintInfo() override
		{
			Quadrangle::PrintInfo();
		}
	};

	class Rhomb : public Parallelogram
	{
		//Ромб - стороны равны, углы A=C, B=D

	public:
		Rhomb() : Parallelogram(1, 1, 0, 0) { this->Name = "Ромб"; };

		Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) { this->Name = "Ромб"; };

		bool CheckFigure() override
		{
			if (Quadrangle::CheckFigure()) return true; //равенство сторон и попарное равенство углов заложено в конструкторе

			else return false;
		}

		void PrintInfo() override
		{
			Quadrangle::PrintInfo();
		}
	};

	class Rectangle : public Parallelogram
	{
		//Прямоугольник - стороны a=c, b=d, углы по 90

	public:
		Rectangle() : Parallelogram(1, 0, 90, 90) { this->Name = "Прямоугольник"; };

		Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) { this->Name = "Прямоугольник"; };

		bool CheckFigure() override
		{
			if (Quadrangle::CheckFigure()) return true;

			else return false;
		}

		void PrintInfo() override
		{
			Quadrangle::PrintInfo();
		}
	};

	class Square : public Rectangle
	{
		//Квадрат - стороны равны, углы по 90

	public:
		Square() : Rectangle(1, 1) { this->Name = "Квадрат"; };

		Square(int a) : Rectangle(a, a) { this->Name = "Квадрат"; };

		bool CheckFigure() override
		{
			if (Quadrangle::CheckFigure()) return true; //равенство сторон и попарное равенство углов заложено в конструкторе

			else return false;
		}

		void PrintInfo() override
		{
			Quadrangle::PrintInfo();
		}
	};
}

using namespace FIGURE;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Figure figure;

	Figure* p_figure = &figure;

	p_figure->PrintInfo();


	Triangle triangle(1, 2, 3, 50, 70, 60);		//создаём экземпляр

	Triangle* p_triangle = &triangle;			//создаём указатель на базовый класс = ссылка на экземпляр

	p_triangle->PrintInfo();					//по указателю на базовый класс вызываем переопределённые методы экземпляров


	RightAngledTriangle right_angled_triangle(1, 2, 3, 30, 60);

	Triangle* p_right_angled_triangle = &right_angled_triangle;

	p_right_angled_triangle->PrintInfo();


	IsoscelesTriangle isosceles_triangle(20, 10, 75, 20);

	Triangle* p_isosceles_triangle = &isosceles_triangle;

	p_isosceles_triangle->PrintInfo();


	EquilateralTriangle equilateral_triangle(10);

	Triangle* p_equilateral_triangle = &equilateral_triangle;

	p_equilateral_triangle->PrintInfo();


	Quadrangle quadrangle(1, 2, 3, 4, 90, 70, 110, 90);

	Quadrangle* p_quadrangle = &quadrangle;

	p_quadrangle->PrintInfo();


	Parallelogram parallelogram(10, 30, 120, 60);

	Quadrangle* p_parallelogram = &parallelogram;

	p_parallelogram->PrintInfo();


	Rhomb rhomb(20, 150, 20);

	Quadrangle* p_rhomb = &rhomb;

	p_rhomb->PrintInfo();


	FIGURE::Rectangle rectangle(10, 20); //существует некая функция Rectangle - конфликт имён

	Quadrangle* p_rectangle = &rectangle;

	p_rectangle->PrintInfo();


	Square square(5);

	Quadrangle* p_square = &square;

	p_square->PrintInfo();

	

	return EXIT_SUCCESS;
}