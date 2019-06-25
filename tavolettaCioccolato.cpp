#include"tavolettaCioccolato.h"
#include<string>

void TavolettaCioccolato::stampa(){//stampa la tavoletta di cioccilata
	for(int i=0;i<this->righe;i++)
	{
		for(int j=0;j<this->colonne;j++)
		{
			cout<< this->cioccolata.at(i*colonne+j)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
 TavolettaCioccolato::TavolettaCioccolato(){
	/*this->*/numNocciole=0;
	/*this->*/righe=0;
	/*this->*/colonne=0;
	/*this->*/lunghezzaBlocchi=0;
	int tempRighe,tempColonne,tempLunghezzaBlocchi;
	fstream input("input.txt",ios::in);
	input>>tempRighe;
	if(tempRighe >= 3) /*this->*/righe=tempRighe;
	else {cout<<"Vincolo righe non rispettato! R>=3"<<endl; exit(1);}
	input>>tempColonne;
	if(tempColonne <=10) /*this->*/colonne = tempColonne;
	else{cout<<"vincolo colonne non rispettato! C<=10"<<endl; exit(1);}
	input>>tempLunghezzaBlocchi;
	if(tempLunghezzaBlocchi >=1 && tempLunghezzaBlocchi <= /*this->*/righe && tempLunghezzaBlocchi <= /*this->*/colonne)
		/*this->*/lunghezzaBlocchi = tempLunghezzaBlocchi;
	else{cout<<"vincolo lunghezzaBlocchi non rispettato! L>=1 && L<=R,C"<<endl; exit(1);}
	input.get();
	string temporanea;
	for (unsigned i = 0; i</*this->*/righe; i++)
	{
		getline(input, temporanea, '\n');
	for (unsigned j = 0; j</*this->*/colonne; j++)
		{
			/*this->*/cioccolata.push_back(temporanea.at(j));
			if (/*this->*/cioccolata.at(i*(colonne)+j) == '#')
				{
					/*this->*/numNocciole++;
				}

		}

		temporanea.clear();
	}
	input.close();
}