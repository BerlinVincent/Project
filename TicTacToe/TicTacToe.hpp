#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define DIM 3
#define board_vec std::vector<std::vector<int>>

class Position {
    public:
        int x;
        int y;

        Position(int a, int b) {
            x = a;
            y = b;
        }
};

class Board {
    private:
        // Attributes
        int height;
        int width;
        board_vec matrix;

    public:
        // Constructor
        Board(int a, int b) {
            height = a;
            width = b;
            matrix = std::vector(a, std::vector(b, 0));
        }

        // Get Functions
        int getHeight() {
            return height;
        }
        int getWidth() {
            return width;
        }
        board_vec getMatrix() {
            return matrix;
        }

        // Set Functions
        void setMatrix(Position pos, int player) {
            matrix.at(pos.x).at(pos.y) = player;
        }
};

/**
 * Function to keep the game loop going until an end state is reached.
 * @returns bool: wether an end state has been reached
 */
bool play(Board &board);

/**
 * Function to determine wether end state has been reached.
 * @returns bool: wether an end state has been reached
 */
bool endState(Board &board);