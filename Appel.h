#ifndef APPEL_
#define APPEL_

#include "eleve.h"
#include <vector>

class Appel
{
	vector<Eleve> present_;
	vector<Eleve> absent_;

public:
	//Contructeur
	Appel(const vector<Eleve> &eleve_group);

	//Methodes de retour des attibuts
	vector<Eleve>& getPresent(){ return present_; };
	vector<Eleve>& getAbsent(){ return absent_; };
	
	//Methodes de parametrisation
	void present(Eleve &eleve_pres);
	void absent(Eleve &absen);
};
#endif