#include "TicTacToe.cpp"

bool cba (bool arr[], size_t n) {
    bool flag = true;
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            flag = false;
        }
    }
    return flag;
}

/* Test functions here */

bool test_endState() {
    Board board1(DIM, DIM);
    Board board2(DIM, DIM);
    Board board3(DIM, DIM);

    bool tests[3] = {false, false, false};

    Position pos00(0, 0);
    Position pos10(1, 0);
    Position pos20(2, 0);
    Position pos01(0, 1);
    Position pos11(1, 1);
    Position pos21(2, 1);
    Position pos02(0, 2);
    Position pos12(1, 2);
    Position pos22(2, 2);

    board1.setMatrix(pos00, 1);
    board1.setMatrix(pos10, 1);
    board1.setMatrix(pos20, 1);

    board2.setMatrix(pos00, -1);
    board2.setMatrix(pos01, -1);
    board2.setMatrix(pos02, -1);

    board3.setMatrix(pos00, 1);
    board3.setMatrix(pos11, 1);
    board3.setMatrix(pos22, 1);

    tests[0] = endState(board1);
    tests[1] = endState(board2);
    tests[2] = endState(board3);

    if (tests[0]) {
        cout << "passed test for column win\n";
    } else {
        cout << "failed test for column win\n";
    }
    if (tests[1]) {
        cout << "passed test for row win\n";
    } else {
        cout << "failed test for row win\n";
    }
    if (tests[2]) {
        cout << "passed test for diagonal win\n";
    } else {
        cout << "failed test for diagonal win\n";
    }
    
    return cba(tests, 3);
}

int main() {
    if (test_endState())
    {
        cout << "passed Test: test_endState()\n";
    } else {
        cout << "failed Test: test_endState()\n";
    }
    return 0;
}