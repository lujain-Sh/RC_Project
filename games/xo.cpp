#include <iostream>
#include <vector>

using namespace std;

// --- Role A & B placeholders (for testing / integration) ---
// If your teammates are writing these separately, they can replace these functions 
// with their respective modules.

// Role A: State and Display
void drawBoard(const vector<char>& board) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    cout << "\n";
}

// Role B: Input and Moves
bool isValidMove(const vector<char>& board, int cell) {
    if (cell < 1 || cell > 9) return false;
    if (board[cell - 1] == 'X' || board[cell - 1] == 'O') return false;
    return true;
}

int getPlayerInput(char currentPlayer, const vector<char>& board) {
    int cell;
    while (true) {
        cout << "Player " << currentPlayer << ", enter a cell (1-9): ";
        cin >> cell;
        if (isValidMove(board, cell)) {
            return cell;
        }
        cout << "Invalid move or cell already taken. Try again.\n";
    }
}


// --- Role C: Rules and Game Loop ---

// Win/Draw Check Rules
bool checkWin(const vector<char>& board, char player) {
    // Winning combinations (Rows, Columns, Diagonals)
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == player &&
            board[wins[i][1]] == player &&
            board[wins[i][2]] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; // Found an empty spot, not a draw yet
        }
    }
    return true;
}

// Main Game Loop
void playGame() {
    vector<char> board = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char currentPlayer = 'X';
    bool gameRunning = true;

    cout << "=== Welcome to Tic-Tac-Toe! ===\n";

    while (gameRunning) {
        // Display state (Role A)
        drawBoard(board);

        // Get and apply move (Role B)
        int move = getPlayerInput(currentPlayer, board);
        board[move - 1] = currentPlayer;

        // Check for Win (Role C)
        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Congratulations! Player " << currentPlayer << " wins!\n";
            gameRunning = false;
        }
        // Check for Draw (Role C)
        else if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!\n";
            gameRunning = false;
        }
        // Switch Turns (Role C)
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
