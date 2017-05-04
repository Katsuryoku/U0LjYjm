#ifndef _ELEVE
#define _ELEVE

#include <string>

using namespace std;

class Eleve
{
    string nom_;
	string prenom_;
	string path_photo_;
  public:
	Eleve(const string & nom,  const string & prenom,  const string & path_photo);
	string getNom() const {return nom_;};
    string getPrenom() const {return prenom_;};
	string getPhoto() const { return path_photo_; };
};
#endif