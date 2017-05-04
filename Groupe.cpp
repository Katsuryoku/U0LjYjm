#include "Groupe.h"
#include <string>
#include <vector>

using namespace std;

Groupe::Groupe(const string & nom, const vector<Eleve> & list_eleve)
{
	nom_ = nom;
	list_eleve_ = list_eleve;
};

void Groupe::setGroupe(string text) 
{
};
Groupe::~Groupe() 
{
};