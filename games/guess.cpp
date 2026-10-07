#include "guess.h"

#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

#include "../common/ui.h"

using namespace std;

namespace guess {

namespace {

struct Level {
    string name;
    int maxNumber;
    int maxAttempts;
};

void showBanner() {
    cout << "=====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "=====================================\n\n";
}

Level chooseLevel() {
    while (true) {
        cout << "Choose a difficulty:\n";
        cout << "  1. Easy   (1-50,   10 attempts)\n";
        cout << "  2. Medium (1-100,   7 attempts)\n";
        cout << "  3. Hard   (1-500,   9 attempts)\n";
        cout << "  4. Insane (1-1000,  8 attempts)\n";
        cout << "Your choice: ";

        int c = -1;
        if (parseInt(readLine(), c)) {
            if (c == 1) return {"Easy", 50, 10};
            if (c == 2) return {"Medium", 100, 7};
            if (c == 3) return {"Hard", 500, 9};
            if (c == 4) return {"Insane", 1000, 8};
        }
        cout << "\nPlease enter 1-4.\n\n";
    }
}


}  // namespace

void play() {
    clearScreen();
    showBanner();

    Level level = chooseLevel();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, level.maxNumber);
    const int secret = dist(gen);

    cout << "\n" << level.name << " mode: I'm thinking of a number between 1 and "
         << level.maxNumber;

        int g = 0;
        while (true) {
            cout << " - your guess: ";
            if (parseInt(readLine(), g) && g >= 1 && g <= level.maxNumber) break;
            cout << "Enter a whole number from 1 to " << level.maxNumber << ".\n";
        }

    waitForEnter();
}

}  // namespace guess