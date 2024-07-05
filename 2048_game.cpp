#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int board[4][4];
int dirLine[] = {1, 0, -1, 0};
int dirColumn[] = {0, 1, 0, -1};

// Function to generate an unoccupied position
pair<int, int> generateUnoccupiedPosition() {
    int occupied = 1;
    int line, column;
    while (occupied) {
        line = rand() % 4;
        column = rand() % 4;
        if (board[line][column] == 0) {
            occupied = 0;
        }
    }
    return make_pair(line, column);
}

// Function to add a new piece (2) to the board
void addPiece() {
    pair<int, int> pos = generateUnoccupiedPosition();
    board[pos.first][pos.second] = 2;
}

// Function to start a new game
void newGame() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            board[i][j] = 0;
        }
    }
    addPiece();
    addPiece();
}

// Function to print the game board and instructions
void printUI() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0) {
                cout << ".";
            } else {
                cout << board[i][j];
            }
            cout << "\t";
        }
        cout << endl;
    }
    cout << "n: new game, w: up, s: down, d: right, a: left, q: quit\n" << endl;
}

// Function to check if a move can be made
bool canDoMove(int line, int column, int nextLine, int nextColumn) {
    if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 ||
        (board[nextLine][nextColumn] != 0 && board[nextLine][nextColumn] != board[line][column])) {
        return false;
    }
    return true;
}

// Function to apply the move in a given direction
void applyMove(int direction) {
    int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
    if (direction == 0) {
        startLine = 3;
        lineStep = -1;
    }
    if (direction == 1) {
        startColumn = 3;
        columnStep = -1;
    }

    int movePossible = 0;
    for (int i = startLine; i >= 0 && i < 4; i += lineStep) {
        for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
            int nextI = i + dirLine[direction];
            int nextJ = j + dirColumn[direction];
            if (canDoMove(i, j, nextI, nextJ)) {
                if (board[nextI][nextJ] == 0) {
                    board[nextI][nextJ] = board[i][j];
                    board[i][j] = 0;
                    movePossible = 1;
                } else if (board[nextI][nextJ] == board[i][j]) {
                    board[nextI][nextJ] += board[i][j];
                    board[i][j] = 0;
                    movePossible = 1;
                }
            }
        }
    }
    if (movePossible) {
        addPiece();
    }
}

int main() {
    srand(time(0));
    char commandToDir[128];
    commandToDir['s'] = 0;
    commandToDir['d'] = 1;
    commandToDir['w'] = 2;
    commandToDir['a'] = 3;
    newGame();

    while (true) {
        printUI();
        char command;
        cin >> command;
        if (command == 'n') {
            newGame();
        } else if (command == 'q') {
            break;
        } else {
            int currentDirection = commandToDir[command];
            applyMove(currentDirection);
        }
    }
    return 0;
}