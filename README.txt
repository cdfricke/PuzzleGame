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

The current program uses a map of key value pairs corresponding to the location and the tile value at that location.
For example, the above map would look like the following set of key value pairs:
[{0, 1}, {1, 2}, {2, 3},
 {3, 8}, {4, 0}, {5, 4},
 {6, 7}, {7, 6}, {8, 5}]

The first value in each pair is the key. It represents the numbered location of the "tile" in the 3x3 grid. These keys
are integers numbered 0-8. Keys 0-2 correspond to the top row, 3-5 corresponds to the middle row, and 6-8 to the bottom
row.

Valid moves are dependent on the location of zero. Based on it's location, there is 2-4 possible moves.
