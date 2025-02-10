#include<iostream>
#include<locale.h>
#include<Windows.h>

struct Account
{
	std::string name;

	int account_number;

	float balance;
};

void Registration(Account &account)
{
	std::cout << "Введите имя владельца счёта: ";
	std::cin >> account.name;

	std::cout << "Введите номер счёта: ";
	std::cin >> account.account_number;

	std::cout << "Введите баланс счёта: ";
	std::cin >> account.balance;
}

void ChangeBalance(Account &account)
{
	std::cout << "Введите новый баланс счёта: ";
	std::cin >> account.balance;
	std::cout << std::endl;
}

void AccountInfo(Account &account)
{
	std::cout << "Информация о счёте: " << std::endl;

	std::cout << "Имя владельца: " << account.name << std::endl;
	std::cout << "Номер счёта: " << account.account_number << std::endl;
	std::cout << "Баланс счёта: " << account.balance << std::endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Account account_1;

	Registration(account_1);

	ChangeBalance(account_1);

	AccountInfo(account_1);
}