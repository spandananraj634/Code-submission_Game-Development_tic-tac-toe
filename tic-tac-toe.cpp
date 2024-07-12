#include <iostream>
#include <vector>

using namespace std;

void renderBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool hasWinner(const vector<vector<char>>& board, char player) {
    for (const auto& row : board) {
        if (row[0] == player && row[1] == player && row[2] == player) {
            return true;
        }
    }

    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isTie(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        renderBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter the row (0, 1, or 2): ";
        cin >> row;
        cout << "Player " << currentPlayer << ", enter the column (0, 1, or 2): ";
        cin >> col;

        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (hasWinner(board, currentPlayer)) {
                renderBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if (isTie(board)) {
                renderBoard(board);
                cout << "The game is a tie!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "That cell is already taken, please choose another." << endl;
        }
    }

    return 0;
}
