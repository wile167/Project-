#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

char currentSymbol = 'X';
int winsX = 0;
int winsO = 0;

void drawOneRow(int rowNumber) {
    for (int i = 0; i < SIZE; ++i) {
        cout << board[rowNumber][i];
        if (i < SIZE - 1) cout << " | ";
    }
    cout << endl;
}

void drawBoard() {
    for (int i = 0; i < SIZE; ++i) {
        drawOneRow(i);
        if (i < SIZE - 1) cout << "---------" << endl;
    }
}

bool validateInput(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

void setBoardCellValue(int row, int col) {
    board[row][col] = currentSymbol;
}

string checkWinner() {
    for (int i = 0; i < SIZE; ++i) {
        // Check rows
        if (board[i][0] == currentSymbol && board[i][1] == currentSymbol && board[i][2] == currentSymbol)
            return string(1, currentSymbol);
        // Check columns
        if (board[0][i] == currentSymbol && board[1][i] == currentSymbol && board[2][i] == currentSymbol)
            return string(1, currentSymbol);
    }
    // Check diagonals
    if (board[0][0] == currentSymbol && board[1][1] == currentSymbol && board[2][2] == currentSymbol)
        return string(1, currentSymbol);
    if (board[0][2] == currentSymbol && board[1][1] == currentSymbol && board[2][0] == currentSymbol)
        return string(1, currentSymbol);

    return "";
}

void updateCurrentSymbol() {
    currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
}

void endGame(const string& winner) {
    if (winner == "X") winsX++;
    else if (winner == "O") winsO++;

    cout << "Winner is " << winner << "!" << endl;
    cout << "Score - X: " << winsX << ", O: " << winsO << endl;

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = ' ';

    currentSymbol = 'X';
}

int main() {
    int row, col;

    while (true) {
        drawBoard();
        cout << "Current symbol: " << currentSymbol << endl;
        cout << "Enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        if (validateInput(row, col)) {
            setBoardCellValue(row, col);

            string winner = checkWinner();
            if (!winner.empty()) {
                drawBoard();
                endGame(winner);
            }
            else {
                updateCurrentSymbol();
            }
        }
        else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}