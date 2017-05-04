#ifndef APPEL_
#define APPEL_

#include "eleve.h"
#include <vector>

class Appel{
	vector<Eleve> present_;
	vector<Eleve> absent_;
public:
	Appel(const vector<Eleve> &eleve_group);
	void present(Eleve &eleve_pres);
	void absent(Eleve &absen);
}
#endif