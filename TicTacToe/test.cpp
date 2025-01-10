#include "test.hpp"

bool cba (bool arr[], size_t n) {
    bool flag = true;
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            flag = false;
        }
    }
    return flag;
}

bool test_endState() {
    Board board1(DIM, DIM);
    Board board2(DIM, DIM);
    Board board3(DIM, DIM);

    bool tests[3] = {false, false, false};

    Position pos[9] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1), Position(2, 2)};

    board1.setMatrix(pos[0], 1);
    board1.setMatrix(pos[3], 1);
    board1.setMatrix(pos[6], 1);

    board2.setMatrix(pos[0], -1);
    board2.setMatrix(pos[1], -1);
    board2.setMatrix(pos[2], -1);

    board3.setMatrix(pos[0], 1);
    board3.setMatrix(pos[4], 1);
    board3.setMatrix(pos[8], 1);

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