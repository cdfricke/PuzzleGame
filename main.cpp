/*
Created by: Connor Fricke (cd.fricke23@gmail.com)
Created on: 25-Jan-2024
Program starts with an unsolved puzzle, which looks like a 3x3 array
of tiles which are unsorted. Each of the tiles has a number 1-8 except
for one random space within the array that has a 'zero' or empty space.
Computer will attempt to rearrange tiles until they are ordered
according to the goal state:

  1 2 3
  8   4
  7 6 5

# matrix locations are according to the following map
[[00, 01, 02]]
[[10, 11, 12]]
[[20, 21, 22]]
*/

#include <iostream>
#include <assert.h>
#include "include/matrix.h"     // personal header file for matrix of integers

int main()
{
    Matrix myMatrix(50,5);
    std::cout << myMatrix << std::endl;

    return 0;
}