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
	Promo(const string & nom, const vector<Groupe> & list_groupe);
	string getNom() const { return nom_; };
	void setPromo(string text);
	~Promo();
};

#endif
