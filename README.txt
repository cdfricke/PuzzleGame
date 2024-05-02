Connor Fricke (cd.fricke23@gmail.com)
Latest Revision: 30-April-2024

This is a simple program designed for console output of a search algorithm solving a puzzle game, in which tiles are arranged 
in a 3x3 matrix with an initially shuffled state. The program will use a type of search algorithm, perhaps eventually multiple
iterations will use different search algorithms. The goal is to shuffle tiles to reach a goal state. A solution may look like:

  [ 1 2 3 ]
  [ 8 0 4 ]
  [ 7 6 5 ]

Algorithms are yet to be implements, but may be:
  A* search
  Greedy Search
  Depth-Limited Search

The current program implements the puzzle with a 2D dynamic array, and a Config class that represents the array and it's heuristic
evaluation.
