#include "MesFonctions.h"
#include "menu.h"
#include "CImg.h"
#include "Appel.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace cimg_library;


int afficheAcceuil(void) {
	//Création des options du menu
	Menu AppelAcc("Acceuil");
	AppelAcc.ajouterOption("Fise 1", "Liste des groupes de Fise 1");
	AppelAcc.ajouterOption("Fise 2", "Liste des groupes de Fise 2");
	AppelAcc.ajouterOption("Fise 3", "Liste des groupes de Fise 3");
	AppelAcc.ajouterOption("Quitter", "Sortir de l'application");

	int c1;
	system("cls");
	//affichage acceuil
	do {
		cout << "Programme d'appel des eleves pour l'ensemble des" << endl
			<< "promotions de Telecom Saint Etienne" << endl << endl;
		AppelAcc.afficherMenu();
		cout << endl;
		c1 = AppelAcc.demanderChoix();
	} while (c1 < 0 || c1>3);
	return c1;
}

int afficheFise1(void) {
	//Création des options du menu
	Menu AppelFi1("Groupe des Fise1");
	AppelFi1.ajouterOption("GrpA", "Groupe A");
	AppelFi1.ajouterOption("GrpB", "Groupe B");
	AppelFi1.ajouterOption("GrpC", "Groupe C");
	AppelFi1.ajouterOption("GrpD", "Groupe D");
	AppelFi1.ajouterOption("GrpE", "Groupe E");
	AppelFi1.ajouterOption("Ret", "Retour");

	int c2;
	//affichage menu Fise1
	do {
		system("cls");
		cout << "Selectionner un groupe" << endl << endl;
		AppelFi1.afficherMenu();
		c2 = AppelFi1.demanderChoix();
	} while (c2 < 0 || c2>5);
	return c2;
}

Promo init_Fise1(string nomfich){

	//Creation de la promo Fise 1 et de ses groupes
	Promo Fise1("Fise 1");

	//création des groupes de Fise 1
	Groupe Fi1_A("Groupe Fise 1_A"), Fi1_B("Groupe Fise 1_B"), Fi1_C("Groupe Fise 1_C"),
		Fi1_D("Groupe Fise 1_D"), Fi1_E("Groupe Fise 1_E");

	//création des variables
	string nom, prenom, path_photo;
	char groupe;

	ifstream fich(nomfich, ios::in);
	if (!fich.is_open()) cout << "Erreur d'ouverture" << endl;
	else
	{
		while (!fich.eof())
		{
			getline(fich, nom, ';');
			getline(fich, prenom, ';');
			fich.get(groupe);
			fich.ignore();
			getline(fich, path_photo, '\n');
			Eleve el(nom, prenom, groupe, path_photo);
			switch (groupe)
			{
			case 'A':
				Fi1_A.ad_eleve(el);
				break;
			case 'B':
				Fi1_B.ad_eleve(el);
				break;
			case 'C':
				Fi1_C.ad_eleve(el);
				break;
			case 'D':
				Fi1_D.ad_eleve(el);
				break;
			case 'E':
				Fi1_E.ad_eleve(el);
				break;
			default:
				break;
			}
		}
		Fise1.ad_groupe(Fi1_A);
		Fise1.ad_groupe(Fi1_B);
		Fise1.ad_groupe(Fi1_C);
		Fise1.ad_groupe(Fi1_D);
		Fise1.ad_groupe(Fi1_E);
	}
	return Fise1;

}

void afficheAppel(Groupe grp){
	//On affiche les consignes
	cout << "Navigation : " << endl;
	cout << "Selectionner les eleves presents" << endl;
	cout << "Pour afficher les eleves suivants, faire FLECHE DE DROITE" << endl;
	cout << "Pour valider l'appel, faire ENTREE" << endl;
	cout << "Pour annuler, faire ECHAP" << endl;

	//on crée la liste des eleves à appeler et toutes les autres variables nécessaires
	vector <Eleve> listEleve;
	listEleve = grp.getListElev();
	Appel listeAppel(listEleve);
	vector <Eleve> Absent;
	vector <Eleve> Present;
	ofstream Appel;


	// Declare a display to draw the scene
	CImg<unsigned char> fond(990, 660, 1, 3, 0);
	CImg<unsigned char> scene = fond;
	CImgDisplay disp(scene, "Appel");

	// Center the window on the screen
	disp.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);
	bool first_open = true, leftClick = false, rightClick = false;
	unsigned int numEl;
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyENTER()) {//on gere l'appui sur echap et la fermeture de la fenetre 

		if (first_open || (disp.is_keyARROWRIGHT() & 1)){

			//Si c'est la première ouverture
			if (first_open)
				numEl = 0;

			//on controle l'appuie
			if (disp.is_keyARROWRIGHT()){
				//cout << "test" << endl<<endl;
				rightClick = true;
				disp.wait(500); //on attend a cause des rebonds du bouton
			}



			if (leftClick){
				if (numEl < 16)
					numEl = 0;
				else{
					if (numEl >= 16)
						numEl = numEl - 16;
				}
				//cout << "nouvelle valeur : " << numEl << endl;
			}

			if ((numEl < listEleve.size()) && (rightClick || first_open)){
				//leftClick = false;
				rightClick = false;
				first_open = false;
				scene = fond;
				//cout << "Debut" << endl;
				//on affiche en fonctions des parametres
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (numEl < listEleve.size()){
							//cout << numEl << endl;
							string path;
							path = listEleve[numEl].getPhoto();
							path = "trombino-Fise1/" + path;

							const char* c = path.c_str(); // on convertie notre string en const char* pour utiliser CImg

							// Declare an image
							CImg<unsigned char> image;
							// Load an image file into it
							image.load(c);
							scene.draw_image(j*(image.width() + 10), i*(image.height() + 10), image).display(disp);
						}
						numEl++;
					}
				}

				//cout << "wait" << endl;
			}
		}

	}
	if (disp.is_keyENTER() & 1){
		//on créer le nom du fichier et on ouvre le flux pour écrire
		string nomGrp;
		nomGrp = grp.getNom();
		nomGrp = "Appel du " + nomGrp+".txt";
		const char* c = nomGrp.c_str();

		Appel.open(c);
		if (!Appel.is_open()){
			system("cls");
			cout << "Erreur d'ouverture du fichier Appel" << endl;
		}
		else
		{
			//on recupere les presents et les absnets
			Present = listeAppel.getPresent();
			Absent = listeAppel.getAbsent();

			Appel << "Eleves presents " << Present.size() << endl;
			for (int i = 0; i < Present.size(); i++){
				Appel << Present[i].getNom() << " " << Present[i].getPrenom() << endl;
			}

			Appel << "Eleves absents " << Absent.size() << endl;
			for (int i = 0; i < Absent.size(); i++){
				Appel << Absent[i].getNom() << " " << Absent[i].getPrenom() << endl;
			}
			if (!Appel.good()){
				system("cls");
				cout << "Erreur d'ecriture sur le fichier Appel" << endl;
			}
			else{
				system("cls");
				cout << "Appel terminé" << endl;
			}
		}
	}
	if (disp.is_closed() || disp.is_keyESC())
	{
		system("cls");
		cout << "Appel Annule" << endl;
	}
}