#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define UNSOLD 0
#define SOLD 1

#define N_PLAYERS 3

using namespace std;

class Dice {
public:
    int roll() {
        srand(time(0));
        return rand() % 6 + 1;
    }
};

class Property {
public:
    string name;
    string color;
    int buyPrice;
    int rent;
    int status;

    Property(string n, string c, int bp, int r) {
        name = n;
        color = c;
        buyPrice = bp;
        rent = r;
        status = UNSOLD;
    }
};

class Player {
public:
    string nickname;
    char symbol;
    int position;
    int money;

    Player(string n, char s) {
        nickname = n;
        symbol = s;
        position = 0;
        money = 1500; // Initial money
    }

    void addMoney(int amount) {
        money += amount;
    }

    void subtractMoney(int amount) {
        money -= amount;
    }
};

class Board {
public:
    vector<Player> players;
    vector<Property> squares;

    Board() {
        players.push_back(Player("Franky", '$'));
        players.push_back(Player("Jimmy", '?'));
        players.push_back(Player("Trevor", '0'));

        squares.push_back(Property("Go", "Null", 0, 0));
        squares.push_back(Property("Malignani Avenue", "red", 100, 50));
        squares.push_back(Property("Sello Avenue", "red", 100, 50));
        // Add more properties...
    }

    void showBoard() {
        system("cls");
        cout << "Player positions:" << endl;
        for (size_t i = 0; i < players.size(); i++) {
            cout << " " << players[i].nickname << ": Square " << players[i].position << endl;
        }
    }

    bool askToBuy(Property& property, Player& player) {
        char choice;
        cout << "Would you like to buy " << property.name << " for " << property.buyPrice << "? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            if (player.money >= property.buyPrice) {
                player.subtractMoney(property.buyPrice);
                property.status = SOLD;
                cout << "Congratulations! You bought " << property.name << "!" << endl;
                return true;
            } else {
                cout << "Sorry, you don't have enough money to buy " << property.name << "." << endl;
            }
        }
        return false;
    }
};

int main() {
    Board board;
    Dice dice;

    int currentPlayer = 0;

    while (true) {
        board.showBoard();

        cout << "It's " << board.players[currentPlayer].nickname << "'s turn." << endl;
        cout << "Rolling the dice..." << endl;
        int diceRoll = dice.roll();
        cout << "You rolled a " << diceRoll << "." << endl;

        board.players[currentPlayer].position = (board.players[currentPlayer].position + diceRoll) % board.squares.size();
        cout << "You landed on: " << board.squares[board.players[currentPlayer].position].name << endl;

        if (board.squares[board.players[currentPlayer].position].status == UNSOLD) {
            bool bought = board.askToBuy(board.squares[board.players[currentPlayer].position], board.players[currentPlayer]);
            if (!bought) {
                cout << "The property remains unsold." << endl;
            }
        }
        // Add logic for paying rent if property is owned by another player

        currentPlayer = (currentPlayer + 1) % N_PLAYERS;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
    }

    return 0;
}
