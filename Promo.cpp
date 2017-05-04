#include "Promo.h"
#include <string>
#include <vector>

using namespace std;

Promo::Promo(const string & nom, const vector<Groupe> & list_groupe)
{
	nom_ = nom;
	list_groupe_ = list_groupe;
};

void Promo::setPromo(string text)
{
};
Groupe::~Groupe()
{
};
