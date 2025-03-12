#include "FigureException.h"


figure::FigureException::FigureException(std::string message)
{
	this->message_error = message;
};

const char* figure::FigureException::what() const
{
	return message_error.c_str();
}