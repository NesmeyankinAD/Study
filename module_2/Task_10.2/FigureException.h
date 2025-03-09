#include<iostream>

#pragma once

namespace figure
{
	class FigureException : public std::exception
	{
	private:
		std::string message_error;

	public:
		FigureException(std::string message);

		const char* what() const;
	};
}


