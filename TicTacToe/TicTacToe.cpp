#include "TicTacToe.hpp"

bool endState(Board &board) {
    board_vec matrix = board.getMatrix();

    int row = 0, column = 0, diagonal1 = 0, diagonal2 = 0, moves_made = 0;
    int n = board.getHeight(), m = board.getWidth();

    for (int i = 0; i < n; i++) {
        diagonal1 += matrix.at(i).at(i);
        diagonal2 += matrix.at(i).at(n - i - 1);

        for (int j = 0; j < n; j++) {
            row += matrix.at(i).at(j);
            column += matrix.at(j).at(i);
        }
        
        if (abs(row) == n || abs(column) == n) {
            return true;    // only return if true, otherwise keep running
        }
        row = 0;
        column = 0;
    }

    return abs(diagonal1) == n || abs(diagonal2) == n;
}

char posConvert(int boardPos){
    if (boardPos == 1) {
        return 'O';
    } else if (boardPos == -1) {
        return 'X';
    }
    return ' ';
}

int inputValidation(){
    int pos;
    while (true) {
        cin >> pos;
        if (!cin) {
            cout << " Not a number. Try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else if (pos < 0 || pos >= 3) {
            cout << "\n Not on Board. Try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        } else break;
    }

    return pos;
}

void displayBoard(board_vec matrix) {
    cout << "   0  1  2\n";
    cout << "0 [" << posConvert(matrix.at(0).at(0)) << "]";
    cout << "[" << posConvert(matrix.at(0).at(1)) << "]";
    cout << "[" << posConvert(matrix.at(0).at(2)) << "]\n";
    
    cout << "1 [" << posConvert(matrix.at(1).at(0)) << "]";
    cout << "[" << posConvert(matrix.at(1).at(1)) << "]";
    cout << "[" << posConvert(matrix.at(1).at(2)) << "]\n";
    
    cout << "2 [" << posConvert(matrix.at(2).at(0)) << "]";
    cout << "[" << posConvert(matrix.at(2).at(1)) << "]";
    cout << "[" << posConvert(matrix.at(2).at(2)) << "]\n";
}

void play(Board &board, string players[2]) {
    bool draw_flag = false;
    int round = 0;
    int current_player = 1;
    board_vec matrix = board.getMatrix();

    while(!endState(board)) {
        cout << "Round " << round << "\n";
        sleep_for(seconds(1));

        cout << "This is the Board currently:\n";
        displayBoard(matrix);

        sleep_for(seconds(1));
        
        if (round % 2 == 0) {
            current_player = 1;
            cout << players[0] << "'s turn\n";
        } else {
            current_player = -1;
            cout << players[1] << "'s turn\n";
        }
        sleep_for(seconds(1));

        cout << "Make your move.\n";
        int pos_x = -1, pos_y = -1;

        cout << "Enter x coordinate number: ";
        pos_x = inputValidation();
        cout << "Enter y coordinate number: ";
        pos_y = inputValidation();

        while (matrix.at(pos_y).at(pos_x) != 0) {
            cout << "This is not a valid move. Try again.\n";
            cout << "Enter x coordinate number: ";
            pos_x = inputValidation();
            cout << "Enter y coordinate number: ";
            pos_y = inputValidation();
        }

        Position pos(pos_x, pos_y);
        board.setMatrix(pos, current_player);
        matrix = board.getMatrix();
        round++;
        cout << '\n';
        sleep_for(seconds(1));

        if (round == 9) {
            draw_flag = true;
            break;
        }
    }

    if (draw_flag) {
        cout << "Draw!";
    } else if (current_player == 1) {
        cout << players[0] << " wins!";
    } else if (current_player == -1) {
        cout << players[1] << " wins!";
    } else {
        cout << "\nSomething went very wrong. Failure exit.\n";
        exit(EXIT_FAILURE);
    }

    cout << "\nEnd state of the Game:\n";
    displayBoard(matrix);
    sleep_for(seconds(1));
    
    cout << "\nEnding game. Play again!\n";
    return;
}

int main() {
    string players[2];
    Board board(DIM, DIM);

    cout << "Welcome to Tic Tac Toe.\n";
    sleep_for(seconds(1));
    cout << "Enter the first player's name: ";
    cin >> players[0];
    cout << "First player is now " << players[0] << "\n";
    sleep_for(seconds(1));
    cout << "Enter the second player's name: ";
    cin >> players[1];
    cout << "Second player is now " << players[1] << "\n";
    sleep_for(seconds(1));
    cout << "Starting a new game of Tic Tac Toe.\n";

    play(board, players);
}