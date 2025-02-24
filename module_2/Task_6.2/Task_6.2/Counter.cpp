#include<iostream>
#include"Counter.h"

Counter::Counter()
{
	this->value = 1;
}

Counter::Counter(int InitValue)
{
	this->value = InitValue;
}

void Counter::IncrCounter()
{
	this->value++;
}

void Counter::DecrCounter()
{
	this->value--;
}

void Counter::CheckValue()
{
	std::cout << "Значение счётика: " << this->value << std::endl;
}