#include "CImg.h"
#include "eleve.h"
#include "Groupe.h"
#include "menu.h"
#include "Promo.h"
#include "MesFonctions.h"
#include "Appel.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	//Variables du programme
	int c1, c2;
	bool fin = false;
	Promo Fise1(init_Fise1("trombino-Fise1/Fise1.txt"));
	Groupe Fise1_A(Fise1.getGroupe(0)), Fise1_B(Fise1.getGroupe(1)),Fise1_C(Fise1.getGroupe(2)),
		Fise1_D(Fise1.getGroupe(3)), Fise1_E(Fise1.getGroupe(4));

	//Lancement des menus
	do {
		c1 = afficheAcceuil();
		switch (c1) {
		case 0:
			c2 = afficheFise1();
			//lancement de l'appel en fonction du groupe
			switch (c2)
			{
			case 0: //Fise1_A
				system("cls");
				cout << Fise1_A.getNom() << endl;
				afficheAppel(Fise1_A);
				system("pause");
				break;
			case 1: //Fise1_B
				system("cls");
				cout << Fise1_B.getNom() << endl;
				afficheAppel(Fise1_B);
				system("pause");
				break;
			case 2: //Fise1_C
				system("cls");
				cout << Fise1_C.getNom() << endl;
				afficheAppel(Fise1_C);
				system("pause");
				break;
			case 3: //Fise1_D
				system("cls");
				cout << Fise1_D.getNom() << endl;
				afficheAppel(Fise1_D);
				system("pause");
				break;
			case 4: //Fise1_E
				system("cls");
				cout << Fise1_E.getNom() << endl;
				afficheAppel(Fise1_E);
				system("pause");
				break;
			default:
				break;
			}
			break;
		case 1:
			system("cls");
			cout << "Not implemented yet" << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Not implemented yet" << endl;
			system("pause");
			break;
		case 3:
			fin = true;
			break;
		}
	} while (!fin);
	system("cls");
}