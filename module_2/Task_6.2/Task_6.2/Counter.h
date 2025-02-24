#pragma once

class Counter
{
private:
	int value;

public:
	Counter();

	Counter(int InitValue);

	void IncrCounter();
	
	void DecrCounter();

	void CheckValue();
};