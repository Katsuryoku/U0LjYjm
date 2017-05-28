#include "Groupe.h"
#include <string>
#include <vector>

using namespace std;

Groupe::Groupe(const string & nom)
{
	nom_ = nom;
	nbEleve_ = 0;
}

void Groupe::ad_eleve(Eleve & el)
{ 
	list_eleve_.push_back(el); 
	nbEleve_++;
}

void Groupe::setGroupe(string text) 
{
	nom_ = text;
}
