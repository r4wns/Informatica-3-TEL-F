#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>

#define UNSOLD 0
#define SOLD 1

#define N_PLAYERS 3

using namespace std;

class Dice {
public:
    int roll() {
        return rand() % 6 + 1;
    }
};

class Square {
public:
    string name;
    virtual bool isProperty() { return false; }
    virtual ~Square() = default;
};

class Property : public Square {
public:
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

    bool isProperty() override { return true; }
};

class Player {
public:
    string nickname;
    char symbol;
    int position;
    int money;
    bool inJail;
    int jailTurns;

    Player(string n, char s) {
        nickname = n;
        symbol = s;
        position = 0;
        money = 1500; // Initial money
        inJail = false;
        jailTurns = 0;
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
    vector<Square*> squares;

    Board() {
        players.push_back(Player("Franky", '$'));
        players.push_back(Player("Jimmy", '?'));
        players.push_back(Player("Trevor", '0'));

        // Initializing the board with properties and special places
        squares.push_back(new Square{"Go"});
        squares.push_back(new Property("Malignani Avenue", "Red", 100, 50));
        squares.push_back(new Property("Sello Avenue", "Red", 100, 50));
        squares.push_back(new Square{"Chance"});
        
        squares.push_back(new Square{"Community Chest"});
        squares.push_back(new Property("Vodnjan Street", "Blue", 150, 75));
        squares.push_back(new Property("Viale Europa", "Blue", 150, 75));
        squares.push_back(new Square{"Jail"});
        
        squares.push_back(new Square{"Free Parking"});
        squares.push_back(new Property("Borik", "Green", 200, 100));
        squares.push_back(new Property("Rovinj", "Green", 200, 100));
        squares.push_back(new Square{"Chance"});
        
        squares.push_back(new Square{"Community Chest"});
        squares.push_back(new Property("Old Town", "Yellow", 250, 125));
        squares.push_back(new Property("Golden Cape", "Yellow", 250, 125));
        squares.push_back(new Square{"Go to Jail"});
    }

    ~Board() {
        for (auto square : squares) {
            delete square;
        }
    }

    void showBoard() {
        system("clear"); // Use "cls" if on Windows
        cout << "Board:" << endl;
        map<int, char> playerPositions;
        for (size_t i = 0; i < players.size(); i++) {
            playerPositions[players[i].position] = players[i].symbol;
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int index = i * 4 + j;
                if (playerPositions.find(index) != playerPositions.end()) {
                    cout << "[" << playerPositions[index] << "]";
                } else {
                    cout << "[" << squares[index]->name[0] << "]";
                }
            }
            cout << endl;
        }

        cout << "Player positions:" << endl;
        for (size_t i = 0; i < players.size(); i++) {
            cout << " " << players[i].nickname << ": Square " << players[i].position << " (Money: $" << players[i].money << ")" << endl;
        }
    }

    bool askToBuy(Property* property, Player& player) {
        char choice;
        cout << "Would you like to buy " << property->name << " for $" << property->buyPrice << "? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            if (player.money >= property->buyPrice) {
                player.subtractMoney(property->buyPrice);
                property->status = SOLD;
                cout << "Congratulations! You bought " << property->name << "!" << endl;
                return true;
            } else {
                cout << "Sorry, you don't have enough money to buy " << property->name << "." << endl;
            }
        }
        return false;
    }

    void handleChance(Player& player) {
        int chance = rand() % 3;
        switch (chance) {
        case 0:
            cout << "Chance: Advance to Go (Collect $200)" << endl;
            player.position = 0;
            player.addMoney(200);
            break;
        case 1:
            cout << "Chance: Go directly to Jail. Do not pass Go. Do not collect $200." << endl;
            player.position = 7; // Jail position
            player.inJail = true;
            player.jailTurns = 0;
            break;
        case 2:
            cout << "Chance: Bank pays you dividend of $50" << endl;
            player.addMoney(50);
            break;
        default:
            cout << "Chance: No effect." << endl;
            break;
        }
    }

    void handleJail(Player& player) {
        if (player.inJail) {
            cout << player.nickname << " is in Jail." << endl;
            if (player.jailTurns < 3) {
                char choice;
                cout << "Do you want to try rolling for doubles to get out of Jail? (Y/N): ";
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    int roll1 = rand() % 6 + 1;
                    int roll2 = rand() % 6 + 1;
                    cout << "You rolled " << roll1 << " and " << roll2 << "." << endl;
                    if (roll1 == roll2) {
                        cout << "Doubles! You are out of Jail." << endl;
                        player.inJail = false;
                    } else {
                        cout << "No doubles. Stay in Jail." << endl;
                        player.jailTurns++;
                    }
                } else {
                    cout << player.nickname << " chose to stay in Jail." << endl;
                    player.jailTurns++;
                }
            } else {
                cout << "You have been in Jail for 3 turns. Paying $50 to get out." << endl;
                player.subtractMoney(50);
                player.inJail = false;
            }
        }
    }

    void movePlayer(Player& player, int roll) {
        player.position = (player.position + roll) % squares.size();
        cout << "You landed on: " << squares[player.position]->name << endl;

        if (squares[player.position]->name == "Chance") {
            handleChance(player);
        } else if (squares[player.position]->name == "Go to Jail") {
            cout << "Go directly to Jail. Do not pass Go. Do not collect $200." << endl;
            player.position = 7; // Jail position
            player.inJail = true;
            player.jailTurns = 0;
        } else if (squares[player.position]->name == "Free Parking") {
            cout << "You landed on Free Parking. Just take a rest!" << endl;
        } else if (squares[player.position]->name == "Jail") {
            cout << "Just visiting Jail." << endl;
        } else if (Property* property = dynamic_cast<Property*>(squares[player.position])) {
            if (property->status == UNSOLD) {
                bool bought = askToBuy(property, player);
                if (!bought) {
                    cout << "The property remains unsold." << endl;
                }
            } else {
                cout << "The property is already sold." << endl;
                // Handle rent payment if necessary
            }
        }
    }
};

int main() {
    srand(time(0)); // Initialize random number generator
    Board board;
    Dice dice;

    int currentPlayer = 0;

    while (true) {
        board.showBoard();

        Player& player = board.players[currentPlayer];

        if (player.inJail) {
            board.handleJail(player);
            currentPlayer = (currentPlayer + 1) % N_PLAYERS;
            cout << "Press Enter to continue..." << endl;
            cin.ignore();
            cin.get();
            continue;
        }

        cout << "It's " << player.nickname << "'s turn." << endl;
        cout << "Rolling the dice..." << endl;
        int diceRoll = dice.roll();
        cout << "You rolled a " << diceRoll << "." << endl;

        board.movePlayer(player, diceRoll);

        currentPlayer = (currentPlayer + 1) % N_PLAYERS;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
    }

    return 0;
}
