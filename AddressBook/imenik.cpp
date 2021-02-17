#include "imenik.h"
#include "adresa.h"
#include "korisnik.h"
#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void imenik::setAdrese()
{
	adresa* a = new adresa(); // zagrade nisu bitne -> znaci da koristi default constructor, ako su zagrade prazne/nepostojece
	(*a).unesiAdresu(); // or a->
	this->getAdrese().push_back(*a);
	//adrese.push_back(*a);
	delete a;
}

void imenik::setKorisnici()
{
	korisnik* k = new korisnik();
	k->unesiKorisnika();
	this->getKorisnici().push_back(*k);
	delete k;
}

vector<adresa>& imenik::getAdrese()
{
	return this->adrese;
}

vector<korisnik>& imenik::getKorisnici()
{
	return this->korisnici;
}

void imenik::ispisImenika()
{
	cout << "|| ISPIS IMENIKA ||" << endl;
	cout << "R. br.\tPrezime\t\tIme\t\tBroj\t\tAdresa\t\tGrad\n";
	cout << "-------------------------------------------------------------------------------------\n";
	if (getAdrese().size() == 0)
		cout << "Imenik je prazan.\n";
	else
	{
		korisnik* k = new korisnik();
		adresa* a = new adresa();
		for (int i = 0; i < adrese.size(); i++)
		{
			*k = this->getKorisnici()[i];
			*a = this->getAdrese()[i];
			cout << i + 1 << "\t";
			//cout << getKorisnici()[i].getIme() << endl;
			cout << k->getPrezime() << "\t\t" << k->getIme() << "\t\t" << k->getBroj() << "\t" << "ulica " << a->getUlica() << " br. " << a->getBroj() << "\t\t" << a->getGrad() << endl;
		}
		delete k, a;
	}
}

void imenik::pretragaPoImenu()
{
	cout << "Unesite ime koje trazite u imeniku: " << endl;
	char imeX[30];
	int br = 0;
	cin.getline(imeX, 30);
	korisnik* k = new korisnik();
	adresa* a = new adresa();
	cout << "R. br.\tPrezime\t\tIme\t\tBroj\t\tAdresa\t\tGrad\n";
	cout << "-------------------------------------------------------------------------------------\n";
	for (int i = 0; i < getKorisnici().size(); i++)
	{
		*k = this->getKorisnici()[i];
		*a = this->getAdrese()[i];
		if (_strcmpi(imeX, k->getIme()) == 0)
		{
			br++;
			cout << i + 1 << "\t" << k->getPrezime() << "\t\t" << k->getIme() << "\t\t" << k->getBroj() << "\t" << "ulica " << a->getUlica() << " br. " << a->getBroj() << "\t\t" << a->getGrad() << endl;
		}
	}
	if (br == 0)
	{
		cout << "Ne postoji osoba sa " << imeX << "imenom!" << endl;
	}
	delete k, a;
}

void imenik::pretragaPoPrezimenu()
{
	char prezimeX[40];
	vector<korisnik> imX;
	vector<adresa> imY;
	cout << "Unesite prezime koje trazite u imeniku: ";
	cin.getline(prezimeX, 40);
	for (int i = 0; i < this->getKorisnici().size(); i++)
	{
		if (_strcmpi(prezimeX, this->getKorisnici()[i].getPrezime()) == 0)
		{
			imX.push_back(this->getKorisnici()[i]);
			imY.push_back(this->getAdrese()[i]);
		}
	}
	if (imX.size() == 0)
	{
		cout << "Ne postoji osoba u imeniku sa " << prezimeX << " prezimenom!" << endl;
	}
	else
	{
		cout << "R. br.\tPrezime\t\tIme\t\tBroj\t\tAdresa\t\tGrad\n";
		cout << "-------------------------------------------------------------------------------------\n";
		for (int i = 0; i < imX.size(); i++)
		{
			cout << i + 1 << "\t" << imX[i].getPrezime() << "\t\t" << imX[i].getIme() << "\t\t" << imX[i].getBroj() << "\t" << "ulica " << imY[i].getUlica() << " br. " << imY[i].getBroj() << "\t\t" << imY[i].getGrad() << endl;
		}
		//drugi nacin
		/*for (auto i = imX.begin(); i != imX.end(); i++)
		{
			cout << i->getPrezime() << "\t\t" << i->getIme() << "\t\t" << i->getBroj() << "\t" << "ulica " << i->getUlica() << " br. " << i->getBroj() << "\t\t" << i->getGrad() << endl;
		}*/
		//treci nacin
		/*for (auto& i : imX)
		{
			cout << i.getPrezime() << "\t\t" << i.getIme() << "\t\t" << i.getBroj() << "\t" << "ulica " << i.getUlica() << " br. " << i.getBroj() << "\t\t" << i.getGrad() << endl;
		}*/
	}
}

void imenik::pretragaPoGradu()
{
	char gradX[50];
	cout << "Unesite ime grada iz kojeg je osoba koju trazite: ";
	cin.getline(gradX, 50);
	imenik* temp = new imenik();
	for (int i = 0; i < getKorisnici().size(); i++)
	{
		if (_strcmpi(gradX, this->getAdrese()[i].getGrad()) == 0)
		{
			temp->getAdrese().push_back(this->getAdrese()[i]);
			temp->getKorisnici().push_back(this->getKorisnici()[i]);
		}
	}
	if (temp->getAdrese().size() == 0)
	{
		cout << "Ne postoji osoba u imeniku sa " << gradX << " gradom!" << endl;
	}
	else
	{
		temp->ispisImenika();
	}
}

imenik::imenik()
{
}

imenik::~imenik()
{
}
