#ifndef _GROUPE_
#define _GROUPE_
#include "eleve.h"
#include <string>

#include <vector>

using namespace std;

class Groupe
{
	string nom_;
	vector<Eleve> list_eleve_;
public:
	Groupe(const string & nom, const vector<Eleve> & list_eleve);
	string getNom() const { return nom_; };
	void setGroupe(string text);
	~Groupe();
};

#endif