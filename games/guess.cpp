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

// ---- Role B: input and validation ----
// Keeps asking until the player enters a whole number in [1, maxNumber].
int readGuess(int maxNumber) {
    int g = 0;
    while (true) {
        cout << "Your guess (1-" << maxNumber << "): ";
        if (parseInt(readLine(), g) && g >= 1 && g <= maxNumber) {
            return g;
        }
        cout << "Enter a whole number from 1 to " << maxNumber << ".\n";
    }
}
// ---- end Role B ----

// ---- Role C: rules and game loop ----
// Prints too high / too low plus a hot-cold hint based on the distance.
void giveHint(int guess, int secret, int maxNumber) {
    int diff = abs(guess - secret);

    cout << (guess < secret ? "Too low. " : "Too high. ");

    if (diff * 20 <= maxNumber)      cout << "Burning hot!\n";
    else if (diff * 7 <= maxNumber)  cout << "Hot.\n";
    else if (diff * 3 <= maxNumber)  cout << "Warm.\n";
    else                             cout << "Cold.\n";
}
// ---- end Role C ----

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
         << level.maxNumber << ".\n";

    // ---- Role C: game loop ----
    int attempts = 0;
    bool won = false;

    while (attempts < level.maxAttempts) {
        cout << "\nAttempt " << attempts + 1 << " of " << level.maxAttempts << "\n";

        int g = readGuess(level.maxNumber);
        attempts++;

        if (g == secret) {
            won = true;
            break;
        }
        giveHint(g, secret, level.maxNumber);
    }

    if (won) {
        cout << "\nYou win! You found " << secret << " in " << attempts
             << " attempt(s).\n";
    } else {
        cout << "\nGame over. The number was " << secret << ".\n";
    }
    // ---- end Role C ----

    waitForEnter();
}

}  // namespace guess