/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Carattere ASCII

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int randomNumber = rand() % 26 + 65;

    cout << "Indovina il carattere associato al codice ASCII " << randomNumber << ": ";
    char guessedChar;
    cin >> guessedChar;

    if (guessedChar == static_cast<char>(randomNumber)) {
        cout << "Corretto! Il carattere associato al codice ASCII " << randomNumber << " e' " << guessedChar << endl;
    }
    else {
        cout << "Sbagliato. Il carattere corretto era " << static_cast<char>(randomNumber) << endl;
    }

    char randomChar = static_cast<char>(rand() % 26 + 65);

    cout << "Indovina il codice ASCII associato al carattere " << randomChar << ": ";
    int guessedASCII;
    cin >> guessedASCII;

    if (guessedASCII == static_cast<int>(randomChar)) {
        cout << "Corretto! Il codice ASCII associato al carattere " << randomChar << " e' " << guessedASCII << endl;
    }
    else {
        cout << "Sbagliato. Il codice ASCII corretto era " << static_cast<int>(randomChar) << endl;
    }

    return 0;
}

//Nazar Markov esercizio 0.2