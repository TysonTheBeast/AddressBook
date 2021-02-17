#pragma once
class adresa
{
private:
	char ulica[100];
	char broj[5];
	char grad[50];
public:
	void setUlica();
	void setBroj();
	void setGrad();
	char* getUlica();
	char* getBroj();
	char* getGrad();
	void unesiAdresu();
	bool pretragaPoUlici(char* u);
	adresa();
	~adresa();
};
