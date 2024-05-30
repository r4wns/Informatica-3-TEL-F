/*

Autore: Nazar Serhiyovich Markov

Classe: 3 TEL F

Programma: Sasso Carta Forbice Lizard Spock

*/
#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));

	string opzioni[] = { "Sasso" , "Carta" , "Forbici" , "Lizard" , "Spock" };
	int punteggioUser = 0;
	int punteggioPC = 0;
	int numeroPartite;

	    cout << "   SSSSS               CCCCC            FFFFFFFFF         LL                  SSSSS  " << endl;
		cout << " SS     SS           CC     CC          FF                LL                SS     SS" << endl;
		cout << " SS                CC        CC         FF                LL                SS       " << endl;
		cout << "   SSS             CC                   FFFFFFFFF         LL                  SSS    " << endl;
		cout << "      SSS          CC                   FF                LL                     SSS " << endl;
		cout << "        SS         CC        CC         FF                LL                       SS" << endl;
		cout << " SS     SS           CC     CC          FF                LL                SS     SS" << endl;
		cout << "   SSSSS     (.)       CCCCC      (.)   FF          (.)   LLLLLLLLL   (.)     SSSSS  " << endl;
		//Se per caso vi chiederete perche' ho fatto sta cagata - non aspettatevi una risposta
		//non lo so nemmeno io
		//Comunque, SCFLS sta per Sasso, Carta, Forbici, Lizard, Spock :)))
		//giusto per FAR CAPIRE VISUALMENTE al User che non sta firmando un contratto di vita e morte
		//ma che sta giocando a un giochino carino
		cout << "                                                             " << endl;
		cout << "|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;
		cout << "                                                             " << endl;

	cout << "Quante partite vuoi giocare? : ";
	cin >> numeroPartite;

	for (int i = 0; i < numeroPartite; ++i) {
		int sceltaUser = rand() % 5;
		int sceltaPC = rand() % 5;

		cout << "Hai scelto: " << opzioni[sceltaUser] << endl;
		cout << "Il tuo avversario ha scelto: " << opzioni[sceltaPC] << endl;

		if ((sceltaUser == 0 && (sceltaPC == 2 || sceltaPC == 3)) || (sceltaUser == 1 && (sceltaPC == 0 || sceltaPC == 4)) || (sceltaUser == 2 && (sceltaPC == 1 || sceltaPC == 3)) || (sceltaUser == 3 && (sceltaPC == 1 || sceltaPC == 4)) || (sceltaUser == 3 && (sceltaPC == 0 || sceltaPC == 2))) {
			//Mi e' venuta una paralisi alla mano mentre scrivevo questo if
			cout << "Hai vinto questa partita!!\n";
			punteggioUser++;

		}
		else if (sceltaUser == sceltaPC) {
			cout << "PAREGGIO!\n";
		}
		else {
			cout << "L'avversario ha vinto questa partita!\n";
			punteggioPC++;
		}
		cout << "--------------------------" << endl; //io uso questi come divisori per non ammuchiare tutto
	}
	cout << "Punteggio finale:\n";
	cout << "Tu: " << punteggioUser << " punti\n";
	cout << "Avversario: " << punteggioPC << " punti\n";

	if (punteggioUser > punteggioPC) {
		cout << "Complimenti, hai vinto questa partita!" << endl;
	}
	else if (punteggioUser < punteggioPC) {
		cout << "Mi dispiace, hai perso... :(" << endl;
	}
	else {
		cout << "La partita e' finita in pareggio" << endl;
	}
	
	return 0;
}
