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

#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'} };

char current_marker;
int current_player;

// رسم لوحة اللعبة
void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

// وضع العلامة في المكان المختار
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

// التحقق من وجود فائز
int winner() {
    // الصفوف والأعمدة
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    // الأقطار
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

// تبديل دور اللاعب
void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}
void game() {
    cout << "اللاعب 1، اختر علامتك (X أو O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won = 0;

    for (int i = 0; i < 9; i++) {
        cout << "دور اللاعب " << current_player << " (" << current_marker << ") - أدخل الرقم (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "رقم غير صالح! حاول مرة أخرى.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "هذا المكان مشغول! حاول مرة أخرى.\n";
            i--;
            continue;
        }

        drawBoard();

        player_won = winner();

        if (player_won != 0) {
            cout << "مبروك! اللاعب " << player_won << " هو الفائز!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        cout << "تعادل! لا يوجد فائز.\n";
    }
}

int main() {
    swapPlayerAndMarker();
    return 0;
}
