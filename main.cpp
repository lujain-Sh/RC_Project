// Puzzle Arcade - one menu, five games.

#include <iostream>
#include <string>

#include "common/ui.h"

// ===== REGISTRY 1/3: includes (add new games above this line) =====
#include "games/xo.h"
#include "games/hangman.h"
#include "games/guess.h"
#include "games/memory.h"
#include "games/sudoku4.h"

using namespace std;

void printMenu() {
    clearScreen();
    cout << "=====================================\n";
    cout << "           PUZZLE ARCADE\n";
    cout << "=====================================\n";
    // ===== REGISTRY 2/3: menu entries (add new games above this line) =====
    cout << "  1. XO (Tic-Tac-Toe)\n";
    cout << "  2. Hangman\n";
    cout << "  3. Number Guessing\n";
    cout << "  4. Memory Match\n";
    cout << "  5. Mini-Sudoku 4x4\n";
    cout << "  0. Exit\n\n";
}

int main() {
    try {
        while (true) {
            printMenu();
            cout << "Choose a game: ";
            int choice = -1;
            if (!parseInt(readLine(), choice)) choice = -1;

            switch (choice) {
                // ===== REGISTRY 3/3: game cases (add new games above this line) =====
                case 0:
                    cout << "Thanks for playing!\n";
                    return 0;
                default:
                    cout << "\nPlease choose a number from the menu.\n";
                    waitForEnter();
            }
        }
    } catch (const InputClosed&) {
        cout << "\nInput closed. Goodbye!\n";
    }
    return 0;
}
