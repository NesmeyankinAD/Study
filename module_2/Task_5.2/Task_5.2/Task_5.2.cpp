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

		virtual void print()
		{
			std::cout << this->GetName() << std::endl;
			std::cout << "Количество сторон: " << this->GetQuantitySides() << std::endl;
		}
	};

	class Triangle : public Figure
	{		
	private:
		int a, b, c; //sides

	public:
		int Get_a() { return this->a; }
		int Get_b() { return this->b; }
		int Get_c() { return this->c; }


	private:
		int A, B, C; //angles

	public:
		int Get_A() { return this->A; }
		int Get_B() { return this->B; }
		int Get_C() { return this->C; }


	public:
		Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
		{
			this->Name = "Треугольник";

			this->a = a;
			this->b = b;
			this->c = c;

			this->A = A;
			this->B = B;
			this->C = C;
		};

		Triangle() : Figure(3)
		{
			this->Name = "Треугольник";

			this->a = 0;
			this->b = 0;
			this->c = 0;
					  
			this->A = 0;
			this->B = 0;
			this->C = 0;
		};

		void print() override 
		{
			std::cout << this->GetName() << std::endl;

			std::cout << "Стороны: ";
			std::cout << "a = " << this->Get_a() << ", ";
			std::cout << "b = " << this->Get_b() << ", ";
			std::cout << "c = " << this->Get_c() << std::endl;
								   
			std::cout << "Углы: "; 
			std::cout << "A = " << this->Get_A() << ", ";
			std::cout << "B = " << this->Get_B() << ", ";
			std::cout << "C = " << this->Get_C() << std::endl;
			std::cout << std::endl;
		}
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
	private:
		int a, b, c, d;

	public:
		int Get_a() { return this->a; }
		int Get_b() { return this->b; }
		int Get_c() { return this->c; }
		int Get_d() { return this->d; }
		
	private:
		int A, B, C, D;

	public:
		int Get_A() { return this->A; }
		int Get_B() { return this->B; }
		int Get_C() { return this->C; }
		int Get_D() { return this->D; }


	public:
		Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
		{
			this->Name = "Четырёхугольник";

			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;

			this->A = A;
			this->B = B;
			this->C = C;
			this->D = D;
		};

		Quadrangle() : Figure(4)
		{
			this->Name = "Четырёхугольник";

			this->a = 0;
			this->b = 0;
			this->c = 0;
			this->d = 0;
					  
			this->A = 0;
			this->B = 0;
			this->C = 0;
			this->D = 0;
		};

		void print() override
		{
			std::cout << this->GetName() << std::endl;

			std::cout << "Стороны: ";
			std::cout << "a = " << this->Get_a() << ", ";
			std::cout << "b = " << this->Get_b() << ", ";
			std::cout << "c = " << this->Get_c() << ", ";
			std::cout << "d = " << this->Get_d() << std::endl;
								   
			std::cout << "Углы: "; 
			std::cout << "A = " << this->Get_A() << ", ";
			std::cout << "B = " << this->Get_B() << ", ";
			std::cout << "C = " << this->Get_C() << ", ";
			std::cout << "C = " << this->Get_D() << std::endl;
			std::cout << std::endl;
		}
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

	void print_info(Figure* p)
	{
		p->print();
	}
}

using namespace FIGURE;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	Triangle triangle(1,2,3,4,5,6);		//создаём экземпляр
	
	Triangle* p_triangle = &triangle;	//создаём указатель на базовый класс = ссылка на экземпляр

	print_info(p_triangle);		//передаём в функцию указатель на базовый класс экземпляра


	RightAngledTriangle right_angled_triangle(1, 2, 3, 50, 60); 
	
	Triangle* p_right_angled_triangle = &right_angled_triangle;	

	print_info(p_right_angled_triangle);


	IsoscelesTriangle isosceles_triangle(20, 10, 75, 30);		
	
	Triangle* p_isosceles_triangle = &isosceles_triangle;		

	print_info(p_isosceles_triangle);


	EquilateralTriangle equilateral_triangle(20);

	Triangle* p_equilateral_triangle = &equilateral_triangle;

	print_info(p_equilateral_triangle);


	Quadrangle quadrangle(1, 2, 3, 4, 50, 60, 110, 80);

	Quadrangle* p_quadrangle = &quadrangle;

	print_info(p_quadrangle);


	Parallelogram parallelogram(10, 30, 120, 60);

	Quadrangle* p_parallelogram = &parallelogram;

	print_info(p_parallelogram);


	Rhomb rhomb(20, 150, 30);

	Quadrangle* p_rhomb = &rhomb;

	print_info(p_rhomb);


	FIGURE::Rectangle rectangle(10, 20); //существует некая функция Rectangle - конфликт имён

	Quadrangle* p_rectangle = &rectangle;

	print_info(p_rectangle);


	Square square(5);

	Quadrangle* p_square = &square;

	print_info(p_square);



	return EXIT_SUCCESS;
}