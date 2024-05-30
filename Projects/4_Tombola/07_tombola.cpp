/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Tombola

*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define N 20
using namespace std;


int main()
{
	int vet[N];
	
	for(int i = 0; i < N; i++)
	{
		vet[i] = i+1;
	}
	cout << "Inizio estrazione." << endl;
	
	srand(time(0));
	int nEstratti = 0;
	while(nEstratti < N)
	{
		int pos = rand()%N;
		int tessera = vet[pos];
		if(tessera != 0)
		{
		    cout << "Il numero pescato e': " << tessera << endl;
		    nEstratti++;
			vet[pos] = 0;
		}
		
	}
	
	return 0;
}