# Divide_And_Conquer

Author: Katarzyna Miałkowska

## Contents ##
1) genSquare.cxx,
- Generates n points in the square (0, 1) ^ 2 and prints their coordinates (x, y).
Takes the number of coordinates in the argument.
<number of coordinates>

2) distance.cxx
- The program finds the closest few points using
divide and conquer technique. It also includes the bruteForce algorithm and compares both algorithms.

3) genRandomPerm.cxx
- Generates a random permutation of the set {1, 2,. . . , n}.
Takes the maximum file size in the argument.
<max>

4) inversions.cxx
- The program finds the number of inversions in a given set using
divide and conquer technique. It also includes the bruteForce algorithm and compares the two algorithms.

## Makefile ##

- To compile all programs, execute:
 make all
- To clear the contents of unnecessary files, execute:
 make clean
- To run the shortest distance program (distance.cxx):
make distance
- To run the inversion counting program (inversions.cxx):
make inversions
