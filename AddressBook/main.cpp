#include <iostream>
#include "adresa.h"
#include "korisnik.h"
#include "imenik.h"


using std::cin;
using std::cout;
using std::endl;

int main()
{
	/*adresa a;
	a.unesiAdresu();
	korisnik k;
	k.unesiKorisnika();*/
	/*
- dio pretraga treba da sadrži novi meni koji nudi opcije

1. Pretraga po imenu
2. Pretraga po prezimenu
3. Pretraga po gradu
4. Vrati se
	*/
	int x, y;
	imenik im;
	do
	{
		system("cls");
		cout << "|| TELEFONSKI IMENIK ||" << endl;
		cout << "1. Unesi stavku\n";
		cout << "2. Ispis imenika\n";
		cout << "3. Pretraga\n";
		cout << "4. Kraj\n";
		cout << "Izbor: ";
		cin >> x;
		cin.ignore();
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else
		{
			if (x == 1)
			{
				im.setKorisnici();
				im.setAdrese();
				system("pause");
			}
			else if (x == 2)
			{
				im.ispisImenika();
				system("pause");
			}
			else if (x == 3)
			{
				do
				{
					system("cls");
					cout << "|| TELEFONSKI IMENIK ||" << endl;
					cout << "1. Pretraga po imenu\n";
					cout << "2. Pretraga po prezimenu\n";
					cout << "3. Pretraga po gradu\n";
					cout << "4. Vrati\n";
					cout << "Izbor: ";
					cin >> y;
					cin.ignore();
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
					else
					{
						if (y == 1)
						{
							im.pretragaPoImenu();
							system("pause");
						}
						else if (y == 2)
						{
							im.pretragaPoPrezimenu();
							system("pause");
						}
						else if (y == 3)
						{
							im.pretragaPoGradu();
							system("pause");
						}
					}
				} while (y != 4);
			}
			else if (x == 4)
			{
				system("exit");
			}
		}
	} while (x != 4);
	return 0;
}