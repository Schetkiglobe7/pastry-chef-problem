#include"tavolettaCioccolato.h"
#include"pasticciere.h"

int main(void)
{
	int risposta;
	TavolettaCioccolato tav1;
	Pasticciere  ErnestKnam(&tav1); 
	do
	{
		cout<<"Avviare Algoritmo?(0 per avviare -/- 1 per terminare)"<<endl;
		cin>>risposta;
		switch(risposta)
		{
			case 0: 
					cout<<"Progetto ASD Antonio Pilato -0124/001307-"<<endl;
					cout<<"Problema del pasticciere"<<endl;
					cout<<"Inizio simulazione"<<endl;
					//pulisce il buffer
					cin.ignore();
					cout << "Press enter to continue...";
					//aspetta che venga premuto invio
					cin.get();
					//pulisce l'output precedente del terminale
					system("clear");
					tav1.stampa();
					ErnestKnam.avviaAlgoritmo();
					cout << "Premere il tasto Invio per terminare...";
					cin.ignore();
					return(0);
					break;
			case 1: 
					cout<<"esco"<<endl;	
					exit(1);
					break;

			default: 
					cout<<"scelta non valida"<<endl;
					break;
		}
	}while((risposta != 0)||(risposta != 1));
}