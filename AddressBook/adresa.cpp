#include "adresa.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

void adresa::setUlica()
{
	cout << "Unesite ime ulice: ";
	cin.getline(this->ulica, 100);
}

void adresa::setBroj()
{
	cout << "Unesite broj kuce: ";
	cin.getline(this->broj, 5);
}

void adresa::setGrad()
{
	cout << "Unesite naziv grada: ";
	cin.getline(this->grad, 50);
}

char* adresa::getUlica()
{
	return this->ulica;
}

char* adresa::getBroj()
{
	return this->broj;
}

char* adresa::getGrad()
{
	return this->grad;
}

void adresa::unesiAdresu()
{
	cout << "-----------------------------------------\n";
	cout << "|| UNOS ADRESE ||" << endl;
	setUlica();
	setBroj();
	setGrad();
}

bool adresa::pretragaPoUlici(char* u)
{
	if (_strcmpi(this->ulica, u) == 0)
		return true;
	else return false;
}

adresa::adresa()
{
	strcpy_s(this->ulica, "Ulica");
	strcpy_s(this->broj, "bb");
	strcpy_s(this->grad, "Zenica");
}

adresa::~adresa()
{
}
