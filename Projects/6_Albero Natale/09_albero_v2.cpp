/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Albero di Natale Versione 2

*/
#include <iostream>
#include <windows.h>

using namespace std;

void setColor(int text, int background) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4));
}

void drawTree(int numRighe) {
    if (numRighe < 3 || numRighe > 9) {
        cout << "Il numero di righe deve essere compreso tra 3 e 9." << endl;
        return;
    }

    for (int i = 1; i <= numRighe; ++i) {
        for (int j = 1; j <= numRighe - i; ++j)
            cout << " ";

        setColor(12, 1);
        for (int k = 1; k <= 2 * i - 1; ++k) {
            if (k == 1 || k == 2 * i - 1) {
                cout << "o";
            } else {
                cout << "*";
            }
        }
        setColor(15, 0);

        cout << endl;
    }

    int posizioneTronco = (2 * numRighe - 1) / 2; 

    int numColonneTronco = (numRighe > 6) ? 3 : 1;
    int numRigheTronco = (numRighe > 6) ? (numRighe > 8) ? 4 : 3 : 1;

    for (int i = 0; i < numRigheTronco; ++i) {
        for (int j = 0; j < posizioneTronco - numColonneTronco / 2; ++j)
            cout << " ";

        setColor(12, 1); 
        for (int k = 0; k < numColonneTronco; ++k)
            cout << "*";
        setColor(15, 0);

        cout << endl;
    }
}

int main() {
    int numRighe;

    cout << "Inserisci il numero di righe dell'albero (compreso tra 3 e 9): ";
    cin >> numRighe;

    drawTree(numRighe);

    return 0;
}
