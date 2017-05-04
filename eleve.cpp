#include "eleve.h"
#include <string>
#include <vector>

using namespace std;

Eleve::Eleve(const string & nom, const string & prenom, const string & path_photo)
{
	nom_ = nom;
	prenom_ = prenom;
	path_photo_ = path_photo;
};
