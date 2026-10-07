#include <iostream>
#include <vector>

using namespace std;

// حجم لوحة السودوكو (9x9)
const int N = 9;

// دالة لطباعة لوحة السودوكو بشكل جميل
void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        if (r % 3 == 0 && r != 0)
            cout << "---------------------------------\n";
        for (int d = 0; d < N; d++) {
            if (d % 3 == 0 && d != 0)
                cout << " | ";
            cout << " " << grid[r][d] << " ";
        }
        cout << endl;
    }
}

// دالة للتحقق إذا كان وضع الرقم في هذا المكان قانونياً أم لا
bool isSafe(int grid[N][N], int row, int col, int num) {
    // التحقق من الصف
    for (int d = 0; d < N; d++)
        if (grid[row][d] == num)
            return false;

    // التحقق من العمود
    for (int r = 0; r < N; r++)
        if (grid[r][col] == num)
            return false;

    // التحقق من المربع الصغير (3x3)
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// دالة لحل السودوكو باستخدام الخوارزمية التراجعية (Backtracking)
bool solveSudoku(int grid[N][N], int row, int col) {
    // إذا وصلنا للنهاية (الصف الثامن والعمود التاسع)، يعني خلصنا حل
    if (row == N - 1 && col == N)
        return true;

    // إذا انتهى العمود، ننتقل للصف اللي بعده
    if (col == N) {
        row++;
        col = 0;
    }

    // إذا كانت الخانة مشغولة برقم مسبقاً، ننتقل للخانة التالية
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        // إذا كان الرقم صالح، نضعه ونتابع
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        // إذا لم يكن صالحاً، نتراجع ونصفر الخانة (Backtrack)
        grid[row][col] = 0;
    }
    return false;
}

int main() {
    // لوحة سودوكو تجريبية (الأصفار تمثل الخانات الفارغة)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "لوحة السودوكو قبل الحل:\n";
    printGrid(grid);
    cout << "\n---------------------------------\n\n";

    if (solveSudoku(grid, 0, 0)) {
        cout << "لوحة السودوكو بعد الحل:\n";
        printGrid(grid);
    } else {
        cout << "عذراً، لا يوجد حل لهذا اللغز!\n";
    }

    return 0;
}