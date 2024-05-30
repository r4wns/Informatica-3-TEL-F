/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Super Enalotto

*/

#include <iostream>
#include <ctime>
#include <cstdlib>

#define due 5
#define tre 25
#define quattro 300
#define cinque 32000
#define sei 658000000

using namespace std;

int ritornoVincita(int numeriVincenti)
{
	switch(numeriVincenti)
	{
		case 2:
			return due;
		case 3:
			return tre;
		case 4:
			return quattro;
		case 5: 
			return cinque;
		case 6:
			return sei;
		default:
			return 0;
	}
}

void stampaSchedina(int schedina[2][6])
{
	cout << "--------------------------------------" << endl;
	cout << "Schedina:" << endl;
	cout << endl;
	for(int row = 0; row < 2; ++row)
	{
		for(int col = 0; col < 6; ++col)
		{
			cout << schedina[row][col] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	
	int numeroGiocate;
	cout << "Inserisci quante volte vuoi giocare: ";
	cin >> numeroGiocate;
	
	int giocateVinte = 0;
	int totaleSpeso = numeroGiocate;
	int totaleVinto = 0;
	
	for(int i = 0; i < numeroGiocate; ++i)
	{
		int numeroEstratto = rand() % 90 + 1;
		cout << "Numero estratto = " << numeroEstratto << endl;
		
		int schedina[2][6];
		for(int row = 0; row < 2; ++row)
		{
			for(int col = 0; col < 6; ++col)
			{
				schedina[row][col] = rand() % 90 + 1;
			}
		}
		
		stampaSchedina(schedina);
		
		int numeriIndovinati = 0;
		for(int row = 0; row < 2; ++row)
		{
			for(int col = 0; col < 6; ++col)
			{
				if(schedina[row][col] == numeroEstratto)
				{
					++numeriIndovinati;
					schedina[row][col] = -1;
				}
			}
		}
		
		if(numeriIndovinati > 0)
		{
			cout << "Numeri indovinati: " << numeriIndovinati << endl;
		}
		else
		{
			cout << "Riprova" << endl;
		}
		
		if(numeriIndovinati >= 2)
		{
			totaleVinto += ritornoVincita(numeriIndovinati);
			++giocateVinte;
		}
		
		cout << endl;
		cout << "*****************************************" << endl;
	}
	
	int totalePerso = totaleSpeso - totaleVinto;
	
	cout << "Numero di giocate: " << numeroGiocate << endl;
	cout << "Giocate vinte: " << giocateVinte << endl;
	cout << "Importo totale speso: " << totaleSpeso << " euro" << endl;
	cout << "Totale vinto: " << totaleVinto << " euro" << endl;
	cout << "Totale perso: " << totalePerso << " euro" << endl;
	
	return 0;
}
