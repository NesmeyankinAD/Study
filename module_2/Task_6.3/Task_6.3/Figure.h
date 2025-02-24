#include<iostream>

#pragma once

namespace FIGURE
{

	class Figure
	{
	private:
		int QuantitySides;
	
	protected:
		std::string Name;
	
	protected:
		Figure(int InitQuantitySides);
	
	public:
		Figure();
	
		int GetQuantitySides();
	
		std::string GetName();
	
		virtual bool CheckFigure();
	
		virtual void PrintInfo();
	
	};

}

