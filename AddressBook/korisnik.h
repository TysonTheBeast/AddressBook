#pragma once
class korisnik
{
private:
	char ime[30];
	char prezime[40];
	char broj[20];
public:
	void setIme();
	void setPrezime();
	void setBroj();
	char* getIme();
	char* getPrezime();
	char* getBroj();
	void unesiKorisnika();
	korisnik();
	~korisnik();
};