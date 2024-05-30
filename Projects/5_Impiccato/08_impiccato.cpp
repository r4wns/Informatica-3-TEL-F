/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Impiccato

*/

#include <iostream>
#include <string>

using namespace std;

int visualizzaImpiccato(int tentativiErrati)
{
    cout << "   ________" << endl;
    cout << "   |      |" << endl;

    if (tentativiErrati >= 1)
        cout << "   O" << endl;

    if (tentativiErrati >= 2)
        cout << "   |";

    if (tentativiErrati >= 3)
        cout << "/";

    if (tentativiErrati >= 4)
        cout << "\\";

    cout << endl;

    if (tentativiErrati >= 5)
        cout << "   |";

    cout << endl;

    if (tentativiErrati >= 6)
        cout << "  /";

    if (tentativiErrati >= 7)
        cout << "\\";

    cout << endl;

    return tentativiErrati;
}

int main()
{
    string parolaSegreta;
    cout << "Inserisci la parola segreta: ";
    cin >> parolaSegreta;

    string parolaIndovinata(parolaSegreta.length(), '_');

    int tentativiErrati = 0;

    while (tentativiErrati < 7)
    {
        cout << "Parola indovinata: " << parolaIndovinata << endl;

        tentativiErrati = visualizzaImpiccato(tentativiErrati);

        char letteraIndovinata;
        cout << "Inserisci una lettera: ";
        cin >> letteraIndovinata;

        bool indovinatoCorrettamente = false;
        for (int i = 0; i < parolaSegreta.length(); ++i)
        {
            if (parolaSegreta[i] == letteraIndovinata)
            {
                parolaIndovinata[i] = letteraIndovinata;
                indovinatoCorrettamente = true;
            }
        }

        if (!indovinatoCorrettamente)
        {
            ++tentativiErrati;
        }

        if (parolaIndovinata == parolaSegreta)
        {
            cout << "Congratulazioni! Hai indovinato la parola: " << parolaSegreta << endl;
            break;
        }
    }

    if (tentativiErrati == 7)
    {
        cout << "Hai perso! La parola segreta era: " << parolaSegreta << endl;
        visualizzaImpiccato(7);
    }

    return 0;
}
