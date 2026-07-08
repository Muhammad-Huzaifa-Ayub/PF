/*Tic-Tac-Toe Variant – 3x3x3 Cube

Problem:
Create a 3D Tic-Tac-Toe board (3×3×3).

Players can place X or O in any of the 27 cells.

Check if there is a winning line in any dimension (rows, columns, pillars, diagonals).

Skills Practiced: 3D traversal, conditional checks along multiple axes, algorithmic thinking.*/


#include <iostream>
#include <iomanip>
using namespace std;

const int N = 3;

void initBoard(char board[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';
}

void displayBoard(char board[N][N])
{
    cout << "\n  1  2  3\n";  // Column headers
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " ";  // Row header
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

bool checkLine(char a, char b, char c, char p) {
    return (a == p && b == p && c == p);
}

bool checkWin(char board[N][N], char p) {
    // Rows and Columns
    for (int i = 0; i < N; i++) {
        if (checkLine(board[i][0], board[i][1], board[i][2], p)) return true;
        if (checkLine(board[0][i], board[1][i], board[2][i], p)) return true;
    }
    // Diagonals
    if (checkLine(board[0][0], board[1][1], board[2][2], p)) return true;
    if (checkLine(board[0][2], board[1][1], board[2][0], p)) return true;

    return false;
}

int main() {
    char board[N][N];
    initBoard(board);

    char player = 'X';
    int moves = 0;

    while (moves < 9) {
        displayBoard(board);

        int row, col;
        cout << "\nPlayer " << player << " enter (row col) [1-3]: ";
        cin >> row >> col;
        row--; col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '.') {
            cout << "Invalid move.\n";
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "\nPlayer " << player << " WINS!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    displayBoard(board);
    cout << "\nGame Draw.\n";
    return 0;
}

