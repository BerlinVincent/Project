#include "TicTacToe.hpp"

bool endState(Board &board) {
    board_vec matrix = board.getMatrix();

    int row = 0, column = 0, diagonal1 = 0, diagonal2 = 0;
    int n = board.getHeight(), m = board.getWidth();

        for (int i = 0; i < n; i++) {
            diagonal1 += matrix.at(i).at(i);
            diagonal2 += matrix.at(i).at(n - i - 1);

            for (int j = 0; j < n; j++) {
                row += matrix.at(i).at(j);
                column += matrix.at(j).at(i);
            }

            return abs(row) == n || abs(column) == n;

            row = 0;
            column = 0;
        }

        return abs(diagonal1) == n || abs(diagonal2) == n;

}

bool play(Board &board) {
    return endState(board);
}