#include <iostream>
#include <string>
#include <ctime> // Per ottenere l'ora attuale

#define N 10

using namespace std;

struct Ticket {
    int number;
    string owner;
    string time;
};

typedef struct Queue {
    int head;
    int tail;
    int size;
    struct Ticket list[N];
} Queue_t;

void initialize(Queue_t* q) {
    q->head = -1;
    q->tail = -1;
    q->size = 0;
}

void showMenu() {
    cout << "Menu:" << endl;
    cout << "1. Aggiungi un biglietto" << endl;
    cout << "2. Estrai un biglietto" << endl;
    cout << "3. Mostra la coda" << endl;
    cout << "4. Esci" << endl;
    cout << "Scelta: ";
}

void addTicket(Queue_t* q) {
    if (q->size == N) {
        cout << "La coda dei biglietti è piena." << endl;
        return;
    }

    Ticket newTicket;
    time_t now = time(0);
    newTicket.time = ctime(&now); // Ottenere l'ora attuale
    newTicket.number = q->size + 1; // Incremento automatico del numero del biglietto
    cout << "Inserisci il nome del proprietario: ";
    cin >> newTicket.owner;

    if (q->head == -1) {
        q->head = 0;
    }
    q->tail = (q->tail + 1) % N;
    q->list[q->tail] = newTicket;
    q->size++;

    cout << "Biglietto aggiunto con successo." << endl;
}

void extractTicket(Queue_t* q) {
    if (q->size == 0) {
        cout << "La coda dei biglietti è vuota." << endl;
        return;
    }

    cout << "Biglietto estratto: " << endl;
    cout << "Numero: " << q->list[q->head].number << endl;
    cout << "Proprietario: " << q->list[q->head].owner << endl;
    cout << "Orario: " << q->list[q->head].time << endl;

    q->head = (q->head + 1) % N;
    q->size--;
}

void showQueue(Queue_t* q) {
    if (q->size == 0) {
        cout << "La coda dei biglietti è vuota." << endl;
        return;
    }

    cout << "Coda dei biglietti:" << endl;
    int i = q->head;
    for (int count = 0; count < q->size; ++count) {
        cout << "Numero: " << q->list[i].number << ", Proprietario: " << q->list[i].owner << ", Orario: " << q->list[i].time;
        i = (i + 1) % N;
    }
}

int main() {
    Queue_t q;
    initialize(&q);

    int choice = 0;
    while (choice != 4) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTicket(&q);
                break;
            case 2:
                extractTicket(&q);
                break;
            case 3:
                showQueue(&q);
                break;
            case 4:
                cout << "Arrivederci!" << endl;
                break;
            default:
                cout << "Scelta non valida." << endl;
        }
    }

    return 0;
}

