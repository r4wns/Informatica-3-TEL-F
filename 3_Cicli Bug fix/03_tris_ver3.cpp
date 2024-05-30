/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Tris Versione 3

*/
#include <iostream>

using namespace std;

char verificaVincitore(char tabella[3][3]);

void disegnaTabella(char tabella[3][3]) 
{
    cout << " 1 | 2 | 3 " << endl;
    cout << "-----------" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "-----------" << endl;
    cout << " 7 | 8 | 9 " << endl;
    cout << "-----------" << endl;

    cout << "Campo di gioco:" << endl;

    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            cout << " " << tabella[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "-----------" << endl;
    }
    cout << endl;
}

char verificaVincitore(char tabella[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        if (tabella[i][0] == tabella[i][1] && tabella[i][1] == tabella[i][2]) return tabella[i][0];
        if (tabella[0][i] == tabella[1][i] && tabella[1][i] == tabella[2][i]) return tabella[0][i];
    }

    if (tabella[0][0] == tabella[1][1] && tabella[1][1] == tabella[2][2]) return tabella[0][0];
    if (tabella[0][2] == tabella[1][1] && tabella[1][1] == tabella[2][0]) return tabella[0][2];

    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (tabella[i][j] != 'X' && tabella[i][j] != 'O') return ' ';
        }
    }

    return 'P';
}

int main() 
{
    char tabella[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int posizione;
    char giocatoreCorrente = 'X';

    do 
    {
        disegnaTabella(tabella);
        char risultato = verificaVincitore(tabella);
        if (risultato != ' ') 
        {
            if (risultato == 'P') 
            {
                cout << "Pareggio!" << endl;
            }
            else 
            {
                cout << "Il giocatore " << risultato << " ha vinto!" << endl;
            }
            break;
        }

        cout << "Giocatore " << giocatoreCorrente << ", inserisci il numero della posizione (1-9): ";
        cin >> posizione;

        if (posizione >= 1 && posizione <= 9 && tabella[(posizione - 1) / 3][(posizione - 1) % 3] == ' ') 
        {
            tabella[(posizione - 1) / 3][(posizione - 1) % 3] = giocatoreCorrente;

            char vincitore = verificaVincitore(tabella);
            if (vincitore != ' ') 
            {
                disegnaTabella(tabella);
                if (vincitore == 'P') 
                {
                    cout << "Pareggio!" << endl;
                }
                else 
                {
                    cout << "Il giocatore " << vincitore << " ha vinto!" << endl;
                }
                break;
            }

            giocatoreCorrente = (giocatoreCorrente == 'X') ? 'O' : 'X';
        }
        else 
        {
            cout << "Input non valido! Riprova." << endl;
        }
    } while (true);

    return 0;
}
