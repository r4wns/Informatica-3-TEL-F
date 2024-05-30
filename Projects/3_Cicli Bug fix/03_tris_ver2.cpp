/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Tris Versione 2

*/
#include <iostream>

using namespace std;

int stampaCampo(char campo[3][3])
{
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << campo[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

bool verificaVittoria(char campo[3][3], char segno)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((campo[i][0] == segno && campo[i][1] == segno && campo[i][2] == segno) ||
            (campo[0][i] == segno && campo[1][i] == segno && campo[2][i] == segno))
        {
            return true;
        }
    }

    if ((campo[0][0] == segno && campo[1][1] == segno && campo[2][2] == segno) ||
        (campo[0][2] == segno && campo[1][1] == segno && campo[2][0] == segno))
    {
        return true;
    }

    return false;
}

int main()
{
    char campo[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    char giocatore1 = 'X';
    char giocatore2 = 'O';

    int riga, colonna;
    char segno;

    bool giocoFinito = false;
    int mosseEffettuate = 0;

    cout << "Benvenuto al Gioco Tris!" << endl;

    while (!giocoFinito && mosseEffettuate < 9)
    {
        stampaCampo(campo);

        if (mosseEffettuate % 2 == 0)
        {
            cout << "Giocatore 1 (X), inserisci la tua mossa (riga e colonna): ";
            segno = giocatore1;
        }
        else
        {
            cout << "Giocatore 2 (O), inserisci la tua mossa (riga e colonna): ";
            segno = giocatore2;
        }

        cout << "Riga: ";
        cin >> riga;
        cout << "Colonna: ";
        cin >> colonna;

        if (riga >= 0 && riga < 3 && colonna >= 0 && colonna < 3 && campo[riga][colonna] == ' ')
        {
            campo[riga][colonna] = segno;
            ++mosseEffettuate;

            if (verificaVittoria(campo, segno))
            {
                giocoFinito = true;
                stampaCampo(campo);
                cout << "Giocatore " << (mosseEffettuate % 2 == 0 ? "2" : "1") << " ("
                     << (mosseEffettuate % 2 == 0 ? giocatore2 : giocatore1) << ") ha vinto!" << endl;
            }
        }
        else
        {
            cout << "Mossa non valida. Riprova." << endl;
        }
    }

    if (!giocoFinito)
    {
        stampaCampo(campo);
        cout << "Il gioco è finito in parità!" << endl;
    }

    return 0;
}
