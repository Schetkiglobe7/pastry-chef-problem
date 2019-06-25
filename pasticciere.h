#ifndef PASTICCIERE_H
#define PASTICCIERE_H

#include"tavolettaCioccolato.h"

class Pasticciere{
	private:
	 		TavolettaCioccolato *tav1;
	 		int maxBlocchi;
	 		int minSpreco;
	 		bool blocchiRiga(int last);
	 		bool blocchiColonna(int last);
	 		int cercaProssimo(int indice);
	 		void taglia(int indice,int qBlocchi,int qSprechi);
	 		
	 public:
	 		Pasticciere(TavolettaCioccolato * tav1){minSpreco=0;maxBlocchi=0;this->tav1=tav1;}
	 		~Pasticciere(){;} //distruttore
	 		void avviaAlgoritmo();
};
#endif