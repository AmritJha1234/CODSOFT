#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};
int current_player = 1;

void drawBoard() {
    for (int i = 0; i < 9; i += 3)
        cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << (i < 6 ? "\n---|---|---\n" : "\n");
}
bool placeMarker(int slot) {
    if (board[slot-1] != 'X' && board[slot-1] != 'O') {
        board[slot-1] = (current_player == 1) ? 'X' : 'O';
        return true;
    }
    return false;
}
bool checkWinner() {
    const int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };
    for (int i = 0; i < 8; ++i)
        if (board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]])
            return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 9; ++i)
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    return true;
}
void switchPlayer() {
    current_player = 3 - current_player;
}
void game() {
    int moves = 0;
    while (moves < 9) {
        drawBoard();
        int slot;
        cout << "Player " << current_player << " (" << ((current_player == 1) ? 'X' : 'O') << "), enter your move (1-9): ";
        cin >> slot;
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        if (checkWinner()) {
            drawBoard();
            cout << "Player " << current_player << " wins!\n";
            return;
        }
        if (checkDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            return;
        }
        switchPlayer();
        moves++;
    }
}
int main() {
    char play_again;
    do {
        for (int i = 0; i < 9; ++i) board[i] = '1' + i;
        current_player = 1;
        game();
        cout << "Play again? (Y/N): "; 
        cin >> play_again;
    } while (play_again == 'Y' || play_again == 'y');
    return 0;
}
