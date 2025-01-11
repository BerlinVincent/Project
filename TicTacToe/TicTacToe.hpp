#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

#define DIM 3
#define board_vec vector<vector<int>>

/**
 * @brief A Position on a Board's matrix
 */
class Position {
    public:
        // Attributes
        int x;  /** Position on the x-axis */
        int y;  /** Position on the y-axis */

        /**
         * The Default Constructor
         */
        Position();
        /**
         * A Constructor for a single Position Object
         * @param a Position on the x-Axis
         * @param b Position on the y-Axis
         */
        Position(int a, int b) {
            y = a;
            x = b;
        }
};

/**
 * @brief A Board for a Tic Tac Toe Game
 */
class Board {
    private:
        // Attributes
        int height;         /** Height of the Board */
        int width;          /** Width of the Board */
        board_vec matrix;   /** Matrix representing the Board*/

    public:
        /**
         * The Default Constructor
         */
        Board();
        /**
         * A Constructor for a single Board Object
         * @param a Height of the Board
         * @param b Width of the Board
         */
        Board(int a, int b) {
            height = a;
            width = b;
            matrix = vector<vector<int>>(a, vector<int>(b, 0));
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

        /**
         * @brief Set function to set a given Position on the Board to a given player's identifier
         * @param pos Position to be set
         * @param player identifier of the player (1 or -1)
         */
        void setMatrix(Position pos, int player) {
            matrix.at(pos.x).at(pos.y) = player;
        }
};

/**
 * @brief A function to convert a number on the Board to an appropriate character
 * @param boardPos Position on the Board
 * @returns char: "O" - player 1, "X" - player -1, " " no move set
 */
char posConvert(board_vec boardPos);

/**
 * @brief A function to make sure input coordinate is on the Board
 * @returns int: valid coordinate
 */
int inputValidation();

/**
 * @brief A function to display the Board in the Terminal
 * @param matrix A Board to be displayed
 */
void displayBoard(board_vec matrix);

/**
 * @brief Function to keep the game loop going until an end state is reached.
 * @param board Board on which the game is player
 * @param players Names given to player 1 and 2
 * @returns when an end state has been reached
 */
void play(Board &board, string players[2]);

/**
 * @brief Function to determine wether end state has been reached.
 * @param board Board on which the game is player
 * @returns bool: wether an end state has been reached
 */
bool endState(Board &board);