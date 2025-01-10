#include "TicTacToe.cpp"

/* Test functions here */

bool test_endState() {
    Board board1(DIM, DIM);
    Board board2(DIM, DIM);
    Board board3(DIM, DIM);

    Position pos00(0, 0);
    Position pos10(1, 0);
    Position pos20(2, 0);

    board1.setMatrix(pos00, 1);
    board1.setMatrix(pos10, 1);
    board1.setMatrix(pos20, 1);

    return endState(board1);
}