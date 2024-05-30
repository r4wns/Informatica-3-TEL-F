/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Albero di Natale Versione 1

*/

#include <iostream>

using namespace std;

void stampaAlbero(int numRighe) {
    if (numRighe < 3 || numRighe > 20) {
        cout << "Il numero di righe deve essere compreso tra 3 e 20." << endl;
        return;
    }

    for (int i = 1; i <= numRighe; ++i) {
        for (int j = 1; j <= numRighe - i; ++j)
            cout << " ";

        for (int k = 1; k <= 2 * i - 1; ++k)
            cout << "*";

        cout << endl;
    }

    int posizioneTronco = numRighe - (numRighe > 6 ? 3 : 1);

    int numColonneTronco = (numRighe > 6) ? 3 : 1;
    int numRigheTronco = (numRighe > 6) ? (numRighe > 8) ? (numRighe > 10) ? (numRighe > 12) ? 6 : 5 : 4 : 3 : 0;

    for (int i = 0; i < numRigheTronco; ++i) {
        for (int j = 0; j < posizioneTronco; ++j)
            cout << " ";

        for (int k = 0; k < numColonneTronco; ++k)
            cout << "*";

        cout << endl;
    }
}

int main() {
    int numRighe;

    cout << "Inserisci il numero di righe dell'albero (compreso tra 3 e 20): ";
    cin >> numRighe;

    stampaAlbero(numRighe);

    return 0;
}