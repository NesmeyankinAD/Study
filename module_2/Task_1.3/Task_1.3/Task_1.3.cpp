#include<iostream>
#include<Windows.h>

struct Address
{
	std::string City;

	std::string Street;

	int HouseNumber;

	int FlatNumber;

	int Index;
};

void PrintAddress(Address& address)
{
	std::cout << "Адрес: " << std::endl;

	std::cout << "Город: " << address.City << std::endl;
	std::cout << "Улица: " << address.Street << std::endl;
	std::cout << "Номер дома: " << address.HouseNumber << std::endl;
	std::cout << "Номер квартиры: " << address.FlatNumber << std::endl;
	std::cout << "Почтовый индекс: " << address.Index << "\n\n";
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	Address address_1 = { "Ижевск", "30 лет Победы", 74, 24, 426054 };

	Address address_2 = { "Казань", "проспект Ямашева", 82, 59, 420126 };

	PrintAddress(address_1);

	PrintAddress(address_2);

}