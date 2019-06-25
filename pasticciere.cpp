#include"pasticciere.h"

void Pasticciere::avviaAlgoritmo(){  
	
	minSpreco=this->tav1->getRighe()*this->tav1->getColonne()-this->tav1->getNumNocciole();
	cout<<"righe: "<</*this->*/tav1->getRighe()<<endl;
	cout<<"colonne: "<</*this->*/ tav1->getColonne()<<endl;
	cout<<"lunghezzaBlocchi: "<</*this->*/tav1->getLunghezzaBlocchi()<<endl;
	cout<<"numNocciole: "<</*this->*/tav1->getNumNocciole()<<endl;
	cout<<"min spreco iniziale: "<<minSpreco<<endl<<endl;
	cout<<"premi invio per continuare..."<<endl;
	cin.ignore();
	this->taglia(-1,0,0);
}

int Pasticciere::cercaProssimo(int indice){ //cerca l'elemento del vector successivo all'attuale
	indice = indice+1;
	int j=indice%this->tav1->getColonne();
	for(int i=indice/this->tav1->getColonne();i<this->tav1->getRighe();i++)
	{
		while(j<this->tav1->getColonne())
		{
			if(this->tav1->getElemVector(i*this->tav1->getColonne()+j)=='0') //se nella posizione i*colonne c'è uno zero ritorna l'indice
			{
				return (i*this->tav1->getColonne()+j);
			}
			j++;
		}
		j=0;
	}
	return(-1);//se non c'è neanche uno zero memorizzato nel vector, allora ritorno -1
}
		//controlla i blocchi di riga disponibili
bool Pasticciere::blocchiRiga(int indice){
	int L=1;
	for(int i=1;i<this->tav1->getLunghezzaBlocchi();i++)
	{
		if( ( (indice+i)/this->tav1->getColonne() ) == (indice/this->tav1->getColonne() ) )
		{
			if (this->tav1->getElemVector(indice+i)=='0')
			{
				L++;
			}
		}
	}
	return (L==this->tav1->getLunghezzaBlocchi());
}
    //controlla i blocchi in colonna disponibili
bool Pasticciere::blocchiColonna(int indice) {
	int L = 1;


	for(int i=1;i<this->tav1->getLunghezzaBlocchi();i++)
	{
		if( ( indice+i*this->tav1->getColonne() ) < ( (this->tav1->getRighe() ) * this->tav1->getColonne() ) )
		{
			if(this->tav1->getElemVector(indice+i*this->tav1->getColonne())=='0')
			L++;
		}
	}
	return(L ==this->tav1->getLunghezzaBlocchi());
}


void Pasticciere::taglia(int indice,int qBlocchi,int qSprechi){ //metodo che effettua il taglio
	indice = this->cercaProssimo(indice);
	if(indice >=0 && minSpreco != 0)//se esiste
		{
			//Caso 1
			if(blocchiRiga(indice))
				{
					for(int i=0;i<this->tav1->getLunghezzaBlocchi();i++)
						{	
							this->tav1->setElemVector(indice+i,'+');
						}
					this->taglia((indice+this->tav1->getLunghezzaBlocchi())-1,qBlocchi+1,qSprechi);
					for(int i=0;i<this->tav1->getLunghezzaBlocchi();i++) //setto a zero
						{	
							this->tav1->setElemVector(indice+i,'0');
						}
				}
			//Caso 2
			if(blocchiColonna(indice))
				{
					for(int i=0;i<this->tav1->getLunghezzaBlocchi();i++)
						{
							this->tav1->setElemVector(indice+(i*tav1->getColonne()),'+');
						}
					taglia(indice,qBlocchi+1,qSprechi);
					for(unsigned i=0;i<this->tav1->getLunghezzaBlocchi();i++)
						{
							this->tav1->setElemVector(indice+(i*tav1->getColonne()),'0');
						}
				}
				//caso 3
			qSprechi++;
			//miglioramento inserimento di euristica per ottimizzazione
			if(qSprechi< minSpreco)  
			{
				taglia(indice,qBlocchi,qSprechi);
			}	
		}
		else 
			if(qBlocchi>maxBlocchi)  //aggiorno e stampo
			{

				this->maxBlocchi=qBlocchi;
				this->minSpreco=qSprechi;
				this->tav1->stampa();
				cout<<"maxBlocchi finale: "<<this->maxBlocchi<<endl;
				cout<<"minSpreco finale: "<<this->minSpreco<<endl;
			}
}







