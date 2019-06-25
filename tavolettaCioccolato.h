#ifndef TAVOLETTACIOCCOLATO_H
#define TAVOLETTACIOCCOLATO_H

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class TavolettaCioccolato{
private:
	int righe;
	int colonne;
	int lunghezzaBlocchi;
	int numNocciole;
	vector<char> cioccolata;
public:
	TavolettaCioccolato();
	~TavolettaCioccolato(){;} //distruttore
	void stampa(); //serve per stampare la tavoletta (usata dalla classe pasticcere)
	int getRighe(){return (this->righe);}
	int getColonne(){return (this->colonne);}
	int getLunghezzaBlocchi(){return (this->lunghezzaBlocchi);}
	int getNumNocciole(){return (this->numNocciole);}
	void setElemVector(int i,char elem){cioccolata.at(i)=elem;}
	char getElemVector(int i){return(cioccolata.at(i));}
};
#endif