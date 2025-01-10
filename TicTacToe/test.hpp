#include "TicTacToe.cpp"

/**
 * @brief A function to check wether all elements of a bool array are equal
 * This function uses a for loop with a flag to iteratively check each element for equivalence.
 * @param arr The bool array to be checked
 * @param n The number of elements in the array
 * @return bool: true if all elements are equal else false
 */
bool cba(bool arr[], size_t n);

/**
 * @brief A function to test the endState() function
 * This function creates a 3x3 Board and then tests whether endState() correctly handles column, row and diagonal win and non-win states.
 * @return bool: true if endState() functions properly else false
 */
bool test_endState();
