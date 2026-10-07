#include "memory.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "../common/ui.h"

using namespace std;

namespace memory_match {
   

bool isValidPosition(int row, int col, const vector<vector<bool>>& revealed) {
    if (row < 0  row >= 4  col < 0 || col >= 4) {
        cout << "Error: Position out of bounds (0-3)!\n";
        return false;
    }
    if (revealed[row][col]) {
        cout << "Error: Card already revealed! Choose another card.\n";
        return false;
    }
    return true;
}

void pickTwoCards(const vector<vector<bool>>& revealed, CardPosition& card1, CardPosition& card2) {
    while (true) {
        cout << "Select first card (enter row and column 0-3): ";
        if (!(cin >> card1.row >> card1.col)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter integers only.\n";
            continue;
        }

        if (isValidPosition(card1.row, card1.col, revealed)) {
            break;
        }
    }
    }
}

 // namespace memory_match
