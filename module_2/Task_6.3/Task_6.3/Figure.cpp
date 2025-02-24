#include "Figure.h"


	FIGURE::Figure::Figure(int InitQuantitySides)
	{
		this->QuantitySides = InitQuantitySides;
	};

	FIGURE::Figure::Figure() : Figure(0)
	{
		this->Name = "Фигура";
	};

	int FIGURE::Figure::GetQuantitySides()
	{
		return this->QuantitySides;
	}

	std::string FIGURE::Figure::GetName()
	{
		return this->Name;
	}

	bool FIGURE::Figure::CheckFigure()
	{
		return true;
	}

	void FIGURE::Figure::PrintInfo()
	{
		std::cout << std::endl;
		std::cout << this->GetName() << std::endl;

		if (this->CheckFigure())	std::cout << "Правильная фигура" << std::endl;
		else						std::cout << "Неправильная фигура" << std::endl;

		std::cout << "Количество сторон: " << this->GetQuantitySides() << std::endl;
	}