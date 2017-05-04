#ifndef APPEL_
#define APPEL_

#include "eleve.h"
#include <vector>

class Appel{
	vector<eleve> present_;
	vector<eleve> absent_;
public:
	Appel(const vector<eleve> &eleve_group);
	void present(eleve &eleve_pres);
	void absent(eleve &absen);
}
#endif