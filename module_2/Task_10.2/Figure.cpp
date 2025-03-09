#include "Figure.h"


	figure::Figure::Figure(int InitQuantitySides)
	{
		this->QuantitySides = InitQuantitySides;
	};

	figure::Figure::Figure() : Figure(0)
	{
		this->Name = "Фигура";
	};

	int figure::Figure::GetQuantitySides()
	{
		return this->QuantitySides;
	}

	std::string figure::Figure::GetName()
	{
		return this->Name;
	}

	void figure::Figure::PrintInfo()
	{
		std::cout << this->GetName() << " создана." << std::endl; 
		std::cout << std::endl;
	}