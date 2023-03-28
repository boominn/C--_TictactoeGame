

#include <iostream>
#include <cstring>
using namespace std;

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char turn = 'X';

void display_board() {
    cout << "-------------" << endl;
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << "-------------" << endl;
}

bool is_winner() {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // Check columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }

    return false;
}

bool is_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void play() {
    int row, col;
    cout << "It's " << turn << "'s turn. Enter row (0-2) and column (0-2) to make a move: ";
    cin >> row >> col;

    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid move! Please try again." << endl;
        play();
        return;
    }

    if (board[row][col] != ' ') {
        cout << "That cell is already taken! Please try again." << endl;
        play();
        return;
    }

    board[row][col] = turn;
    display_board();

    if (is_winner()) {
        cout << turn << " has won the game!" << endl;
        return;
    }

    if (is_draw()) {
        cout << "The game is a draw!" << endl;
        return;
    }

    turn = (turn == 'X') ? 'O' : 'X';
