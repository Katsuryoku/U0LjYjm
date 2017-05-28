#ifndef _ELEVE
#define _ELEVE

#include <string>

using namespace std;
typedef enum etat{ Present, Absent };
class Eleve
{
    string nom_;
	string prenom_;
	char groupe_;
	string path_photo_;
	etat presence_;

  public:
	//Constructeur
	Eleve(const string & nom,  const string & prenom, const char & groupe,  const string & path_photo);
	
	//Methodes de retour des attributs
	string getNom() const {return nom_;};
    string getPrenom() const {return prenom_;};
	char getGroupe() const { return groupe_; };
	string getPhoto() const { return path_photo_; };
	etat getEtat() const { return presence_; };

	//Methodes de parametrisation des attributs
	void setEtat();
};
#endif