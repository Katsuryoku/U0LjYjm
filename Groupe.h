#ifndef _GROUPE_
#define _GROUPE_
#include "eleve.h"
#include <string>

#include <vector>

using namespace std;

class Groupe
{
	string nom_;
	int nbEleve_;
	vector<Eleve> list_eleve_;
public:
	//constructeur
	Groupe(const string & nom);
	
	//fonction Get
	string getNom() const { return nom_; };
	int getNbEleve() const { return nbEleve_; };
	Eleve getEleve(int i) const { return list_eleve_[i]; };
	vector<Eleve>& getListElev() { return list_eleve_; };
	
	// Fonction d'ajout d'éléments et de modification de la classe
	void ad_eleve(Eleve & el);
	void setGroupe(string text);
	//~Groupe();
};

#endif