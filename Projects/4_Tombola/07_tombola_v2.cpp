/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Tombola

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#define RIGHE 3
#define COLONNE 9

using namespace std;

void inizializzaTabella(int tabella[RIGHE][COLONNE]) 
{
    srand(time(0));

    for (int colonna = 0; colonna < COLONNE; ++colonna) 
	{
        int numeri_disponibili[COLONNE * 10] = {0};
        for (int riga = 0; riga < RIGHE; ++riga) 
		{
            int min_num = colonna * 10 + 1;
            int max_num = (colonna + 1) * 10;
            int num;
            bool unico;
            do 
			{
                num = min_num + rand() % (max_num - min_num + 1);
                unico = (numeri_disponibili[num] == 0);
            } while (!unico);
            tabella[riga][colonna] = num;
            numeri_disponibili[num] = 1;
        }
    }
}
void stampaTabella(const int tabella[RIGHE][COLONNE]) 
{
    for (int riga = 0; riga < RIGHE; ++riga) 
	{
        for (int colonna = 0; colonna < COLONNE; ++colonna) 
		{
            cout << tabella[riga][colonna];
            if (colonna != COLONNE - 1) 
			{
                cout << " | ";
            }
        }
        cout << endl;
        if (riga != RIGHE - 1) 
		{
            cout << "------------------------------------------" << endl;
        }
    }
}

int main() 
{
    int tabella[RIGHE][COLONNE];

    inizializzaTabella(tabella);
    stampaTabella(tabella);

    return 0;
}
