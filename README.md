solver.c is the sourcecode for the soduko solver with commnets for beginners to understand the fundementals of C

to complie:

gcc solver.c -o Solver

to run on linux:

./Solver 

solvernoComment.c is the same as solver.c but is there is not comments.

If you actually want to use this code for solving soduko puzzles:

to input your puzzle:

edit solvernoComment.c 

on line 64 

int puzzle[9][9]=    {{0, 0, 8, 0, 9, 0, 0, 5, 0},
                      {0, 1, 0, 0, 6, 5, 0, 0, 4},
                      {4, 0, 5, 0, 0, 0, 2, 0, 9},
                      {7, 3, 0, 0, 5, 0, 1, 0, 8},
                      {5, 0, 2, 0, 0, 0, 4, 0, 7},
                      {1, 0, 4, 0, 3, 0, 0, 9, 6},
                      {8, 0, 1, 0, 0, 0, 7, 0, 2},
                      {3, 0, 0, 1, 8, 0, 0, 4, 0},
                      {0, 4, 0, 0, 2, 0, 3, 0, 0}};
                      
the "block" of numbers is the grid.
0 = and open space

put your numbers in the respected spaces

I know this is a tedius way of doing it but this is not intended to be used as a solver in the first place.

If you would li9ke me to make it more user freindy and easier to put numbers in, let me know ;-)
