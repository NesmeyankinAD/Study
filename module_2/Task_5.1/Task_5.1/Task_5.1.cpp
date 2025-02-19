#include<iostream>
#include<Windows.h>
#include<string>


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
	Triangle() : Figure(3) 
	{
		this->Name = "Треугольник";
	};

};

class Quadrangle : public Figure
{
public:
	Quadrangle() : Figure(4) 
	{
		this->Name = "Четырёхугольник";
	};

};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Figure figure;

	std::cout << figure.GetName() << ": " << figure.GetQuantitySides() << std::endl;

	Triangle triangle;

	std::cout << triangle.GetName() << ": " << triangle.GetQuantitySides() << std::endl;

	Quadrangle quadrangle;

	std::cout << quadrangle.GetName() << ": " << quadrangle.GetQuantitySides() << std::endl;

}