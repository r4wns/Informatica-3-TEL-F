/*

Progetto Monopoly
Sviluppatore: Mykhailo Rudovskyi
Classe: 3TELF
Tempo impiegato: ??? h

*/
#include <iostream>
#include <time.h>
#include <vector>

#define UNSOLD 0
#define SOLD 1
#define HOME 2
#define HOTEL 3

#define N_PLAYERS 3

using namespace std;

class Dice {
public:
    int throW() {
        srand(time(0));

        return rand() % 6 + 1;
    }
};

class Plot {
public:
    string name;
    string color;
    int buyPrice;
    int homePrice;
    int hotelPrice;
    int baseGain;
    int homeGain;
    int hotelGain;
    int property;

    Plot(string n, string c, int bp, int hmp, int hlp, int bg, int hmg, int hlg) {
        name = n;
        color = c;
        buyPrice = bp;
        homePrice = hmp;
        hotelPrice = hlp;
        baseGain = bg;
        homeGain = hmg;
        hotelGain = hlg;
        property = UNSOLD;
    }
};

class Player {
private:
    vector<Plot> _properties;
    int _money;
    bool _isPlaying;

public:
    string nick;
    char symbol;

    Player(string n, char s) {
        nick = n;
        symbol = s;
        _money = 500;
        _isPlaying = true;
    }

    void addMoney(int toAdd) {
        _money += toAdd;
    }

    void subMoney(int toSubtract) {
        _money -= toSubtract;
    }

    void addProperty(Plot& newProperty) {
        newProperty.property = SOLD;
        _properties.push_back(newProperty);
    }

    int getMoney() {
        return _money;
    }
};

class City {
private:
    void _createField() {
        Plot plot1("Go", "Null", 0, 0, 0, 0, 0, 0);

        Plot plot2("Via_Malignani", "red", 100, 200, 300, 50, 100, 150);
        Plot plot3("Via_Sello", "red", 100, 200, 300, 50, 100, 150);
        Plot plot4("Via_Copernico", "red", 100, 200, 300, 50, 100, 150);

        Plot plot5("Prigione", "Null", 0, 0, 0, 0, 0, 0);

        Plot plot6("Via_Marte", "green", 100, 200, 300, 50, 100, 150);
        Plot plot7("Via_Giove", "green", 100, 200, 300, 50, 100, 150);
        Plot plot8("Via_Saturno", "green", 100, 200, 300, 50, 100, 150);

        Plot plot9("Imprevisto", "Null", 0, 0, 0, 0, 0, 0);

        Plot plot10("Via_Cielo", "blue", 100, 200, 300, 50, 100, 150);
        Plot plot11("Via_Mare", "blue", 100, 200, 300, 50, 100, 150);
        Plot plot12("Via_Terra", "blue", 100, 200, 300, 50, 100, 150);

        Plot plot13("Alla_Prigione", "Null", 0, 0, 0, 0, 0, 0);

        Plot plot14("Via_OnePiece", "yellow", 100, 200, 300, 50, 100, 150);
        Plot plot15("Imprevisto", "Null", 0, 0, 0, 0, 0, 0);
        Plot plot16("Via_Malignani", "yellow", 100, 200, 300, 50, 100, 150);

        field.push_back(plot1);
        field.push_back(plot2);
        field.push_back(plot3);
        field.push_back(plot4);
        field.push_back(plot5);
        field.push_back(plot6);
        field.push_back(plot7);
        field.push_back(plot8);
        field.push_back(plot9);
        field.push_back(plot10);
        field.push_back(plot11);
        field.push_back(plot12);
        field.push_back(plot13);
        field.push_back(plot14);
        field.push_back(plot15);
        field.push_back(plot16);
    }

public:
    int playerPositions[N_PLAYERS];
    vector<Plot> field;

    City() {
        // Tutti i giocatori partono dalla casella 0
        for (int i = 0; i < N_PLAYERS; i++) {
            playerPositions[i] = 0;
        }

        _createField();
    }
};

void showPositions(City monopoly, vector<Player> players) {
    system("cls");
    cout << "Posizione dei giocatori:" << endl;

    for (int i = 0; i < N_PLAYERS; i++) {
        cout << " " << players[i].nick << "; Casella n. " << monopoly.playerPositions[i] << endl;
    }
}

int main() {
    Player g1("Franky", '$');
    Player g2("Jimmy", '?');
    Player g3("Trevor", '0');

    vector<Player> players;
    players.push_back(g1);
    players.push_back(g2);
    players.push_back(g3);

    City monopoly;

    int turn = 0;

    while (true) {
        showPositions(monopoly, players);

        cout << "Turno del giocatore " << players[turn].nick << endl;
        cout << " Soldi: " << players[turn].getMoney() << endl;

        turn = (turn + 1) % N_PLAYERS;

        system("pause");
    }

    return 0;
}