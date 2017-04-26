#ifndef _ELEVE
#define _ELEVE

#include <string>

using namespace std;

class eleve
{
    string nom_;
	string prenom_;
	string path_photo_;
  public:
	Eleve(const string & nom_,  const string & prenom_,  const string & photo_, );
	string getNom() const {return nom_;};
    string getPrenom() const {return prenom_;};
    string getPhoto() const {return photo_;};
};


#endif