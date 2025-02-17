#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<locale.h>


class Adress
{
private:
	std::string City;
	std::string Street;
	int			HouseNumber;
	int			FlatNumber;

public:

	Adress(std::string City, std::string Street, int HouseNumber, int FlatNumber) 
	{
		this->City = City;
		this->Street = Street;
		this->HouseNumber = HouseNumber;
		this->FlatNumber = FlatNumber;
	};

	Adress()
	{
		this->City = "City";
		this->Street = "Street";
		this->HouseNumber = 0;
		this->FlatNumber = 0;
	};

	std::string GetAdress()
	{
		return this->City + ", " + this->Street + ", " + std::to_string(this->HouseNumber) + ", " + std::to_string(this->FlatNumber);
	}
};


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	setlocale(LC_ALL, "Rus");


	std::ifstream InputFile("InputFile.txt");
	std::string s;

	std::fstream OutputFile("OutputFile.txt");

	if (InputFile.is_open())
	{
		InputFile >> s;
		int Quantity = std::stoi(s);

		Adress* arr;				//указатель на область памяти с объектами типа Adress
		arr = new Adress[Quantity];	//выделяем память под объекты типа Adress
									//в каждом arr[i] - объект, сначала инициализируется конструктором без параметров

		for (int i = 0; i < Quantity; i++)
		{
			std::string s1,s2,s3,s4;

			InputFile >> s1; //Город
			InputFile >> s2; //Улица
			InputFile >> s3; //Номер дома
			InputFile >> s4; //Номер квартиры
			
			arr[i] = Adress(s1, s2, std::stoi(s3), std::stoi(s4)); 
		}

		InputFile.close();
		
		OutputFile << std::to_string(Quantity) << std::endl;

		for (int i = Quantity - 1; i >= 0; i--)
		{
			//std::cout << arr[i].GetAdress() << std::endl;

			OutputFile << arr[i].GetAdress() << std::endl;
		}

		OutputFile.close();

		delete[] arr;
	}
	else { std::cout << "Не удалось открыть файл с адрессами!" << std::endl; }
}