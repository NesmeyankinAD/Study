#include<iostream>
#include"FigureException.h"

#pragma once

namespace figure
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
	
		virtual void PrintInfo();
	
	};

}

