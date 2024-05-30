/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Cicli Bug Fix

*/
#include <iostream>
using namespace std;

int main() {
	//Primo ciclo che avanza con indice +1
    cout << "Questo ciclo FOR avanzera' con indice + 1." << endl;
    
    int index = 0;
    while(index < 10) {
    	cout << "La variabile indice e': " << index << endl;
    	index++;
	}
	cout << "Ho finito il primo ciclo WHILE" << endl << endl;
	
	cout << "Questo ciclo FOR avanzera' con indice + 2." << endl;
	while(index < 10) {
		cout << "La variabile indice e': " << index << endl;
		index +2;
    }
    cout << "Ho finito il secondo ciclo WHILE" << endl << endl;
    
    cout << "Questo ciclo FOR avanzera' con indice -1." << endl;
	while(index > 0) {
		cout << "La variabile indice e': " << index << endl;
		index--;
    }
    cout << "Ho finito il terzo ciclo WHILE" << endl << endl;
    
    cout << "Questo ciclo FOR avanzera' con indice +1, con ripetizione gestita dalla variabile." << endl;
	int max = 7;
	while(index < max) {
		cout << "La variabile indice e': " << index << endl;
		index++;
    }
    cout << "Ho finito il quarto ciclo WHILE" << endl << endl;
    
    cout << "Questo ciclo FOR avanzera' con indice +1, ma con ripetizione gestita dalla variabile." << endl;
	max = 7;
	index = 3;
	while(index <= max) {
		cout << "La variabile indice e': " << index << endl;
		index++;
	}
	cout << "Ho finito il quinto ciclo FOR" << endl << endl;

	return 0;
}