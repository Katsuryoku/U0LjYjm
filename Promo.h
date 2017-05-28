#ifndef _PROMO_
#define _PROMO_
#include "Groupe.h"
#include <string>

#include <vector>

using namespace std;

class Promo
{
	string nom_;
	vector<Groupe> list_groupe_;
public:
	Promo(const string & nom);
	string getNom() const { return nom_; };
	Groupe getGroupe(int i) { return list_groupe_[i]; }
	void ad_groupe(Groupe & grp){ list_groupe_.push_back(grp); };
	void setPromo(string text);
	//~Promo();
};

#endif
