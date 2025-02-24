#include"MathFunctions.h"
#include<iostream>

float Sum(float num1, float num2)
{
	return num1 + num2;
}

float Sub(float num1, float num2)
{
	return num1 - num2;
}

float Mult(float num1, float num2)
{
	return num1 * num2;
}

float Div(float num1, float num2)
{
	return num1 / num2;
}

float Power(float num1, float num2)
{
	float res{0};

	if (num2 == 0) res = 1;
	else 
	{
		res = num1;

		for (int i = 1; i < num2; i++)
		{
			res *= num1;
		}
	}

	return res;
}