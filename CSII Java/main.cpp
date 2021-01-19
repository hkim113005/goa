/*
 * This program plays a random number guessing game with the user.
 * The user gets three guesses to guess the random number between 1 and 10.
 * By Hyungjae Kim on 2021-01-19.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class Game {
public:
    bool game_continue() {
        return cont;
    }

    bool game_over() {
        return over;
    }

    void set_number() {
        number = random_number();
    }

    int get_number() {
        return number;
    }

    int random_number() {
        return rand() % 10 + 1;
    }

    void guess() {
        int g;

        cout << "Guess a number: ";
        cin >> g;

        check_guess(g);
    }

    void check_guess(int n) {
        if (number == n) {
            over = true;
        }
    }

    void ask() {
        string a;

        cout << "Would you like to play again? (Yes or No): ";
        cin >> a;

        if (a == "Yes" || a == "yes") {
            cont = true;
            return;
        }
        else if (a == "No" || a == "no") {
            cont = false;
            return;
        }
        else {
            cout << "Incorrect input, please enter the correct response type.\n";
            ask();
        }
    }

    void print(int op) {
        if (op == 0) {
            cout << "Yes! You got it!\n";
        }
        else if (op == 1) {
            cout << "Nope, that's not it.\n";
        }
        else if (op == 2) {
            cout << "The correct answer was " << number << endl;
        }
    }

private:
    int number;

    bool over = false;
    bool cont = true;
};

int main() {
    while (true) {
        Game game;

        game.set_number();

        for (int i = 0; i < 3; i++) {
            game.guess();

            if (game.game_over()) {
                game.print(0);
                game.ask();
                break;
            }
            else {
                game.print(1);
            }
        }

        if (!game.game_over()) {
            game.print(2);
            game.ask();
        }

        cout << endl << endl;

        if (!game.game_continue()) {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
