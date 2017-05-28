#include "eleve.h"
#include <string>
#include <vector>

using namespace std;

Eleve::Eleve(const string & nom, const string & prenom, const char & groupe, const string & path_photo)
{
	nom_ = nom;
	prenom_ = prenom;
	groupe_ = groupe;
	path_photo_ = path_photo;
}

void Eleve::setEtat(){
	if (presence_ = Present)
		presence_ = Absent;
	else
		presence_ = Present;
}