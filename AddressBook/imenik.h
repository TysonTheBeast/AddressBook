#pragma once
#include "imenik.h"
#include "adresa.h"
#include "korisnik.h"
#include <iostream>
#include <cstring>
#include <vector>

using std::vector;

class imenik
{
private:
	vector<adresa> adrese;
	vector<korisnik> korisnici;
public:
	void setAdrese();
	void setKorisnici();
	vector<adresa>& getAdrese();
	vector<korisnik>& getKorisnici();
	void ispisImenika();
	void pretragaPoImenu();
	void pretragaPoPrezimenu();
	void pretragaPoGradu();
	imenik();
	~imenik();
};


