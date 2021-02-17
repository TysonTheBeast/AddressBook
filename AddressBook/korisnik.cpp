#include "korisnik.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

void korisnik::setIme()
{
	cout << "Unesite ime korisnika: ";
	cin.getline(this->ime, 30);
}

void korisnik::setPrezime()
{
	cout << "Unesite prezime korisnika: ";
	cin.getline(this->prezime, 40);
}

void korisnik::setBroj()
{
	cout << "Unesite broj korisnika: ";
	cin.getline(this->broj, 20);
}

char* korisnik::getIme()
{
	return this->ime;
}

char* korisnik::getPrezime()
{
	return this->prezime;
}

char* korisnik::getBroj()
{
	return this->broj;
}

void korisnik::unesiKorisnika()
{
	system("cls");
	cout << "|| UNOS KORISNIKA ||" << endl;
	setIme();
	setPrezime();
	setBroj();
}

korisnik::korisnik()
{
	strcpy_s(this->ime, "Niko");
	strcpy_s(this->prezime, "Nikic");
	strcpy_s(this->broj, "061123456");
}

korisnik::~korisnik()
{
}
