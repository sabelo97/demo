#include <stdio.h> 
#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"

int isAvailable(int puzzle[][9], int row, int col, int num)
{
    
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i, j;

    for(i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return fillSudoku(puzzle, row, col+1);
            else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
            
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fillSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main()
{
    int i, j, g = 0;
    int VERBOSE = 0;
    
    int puzzle[9][9]={{0, 0, 8, 0, 9, 0, 0, 5, 0},
                      {0, 1, 0, 0, 6, 5, 0, 0, 4},
                      {4, 0, 5, 0, 0, 0, 2, 0, 9},
                      {7, 3, 0, 0, 5, 0, 1, 0, 8},
                      {5, 0, 2, 0, 0, 0, 4, 0, 7},
                      {1, 0, 4, 0, 3, 0, 0, 9, 6},
                      {8, 0, 1, 0, 0, 0, 7, 0, 2},
                      {3, 0, 0, 1, 8, 0, 0, 4, 0},
                      {0, 4, 0, 0, 2, 0, 3, 0, 0}};


    printf("%sDo you want  verbose output? (show all the tries I have made)\n\n 1 = yes\n 0 = no\n", KGRN);
    scanf("%d", &VERBOSE);

    printf("%syour original unsolved puzzle is:\n\n", KRED);
    printf("%s\n+-----+-----+-----+\n", KNRM);

    for(i=1; i<10; ++i)
    { 
        for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
        printf("|\n");
        if (i%3 == 0) printf("+-----+-----+-----+\n\n");
    }

    if (VERBOSE == 1)
    {

        for (g = 0; g < 10; ++g)
        {
        if(fillSudoku(puzzle, 1 > 10, 1>10 ))
        {
            printf("%syour puzzle so far is: \n", KRED);
            printf("%s\n+-----+-----+-----+\n", KNRM);
            for(i=1; i<10; ++i)
            {
                for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
                printf("|\n");
                if (i%3 == 0) printf("+-----+-----+-----+\n\n");
            }
        }}}

    if(fillSudoku(puzzle, 0, 0))
    {
        printf("%sthe solved puzzle is: \n", KRED);
        printf("%s\n+-----+-----+-----+\n", KNRM);
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
            printf("|\n");
            if (i%3 == 0) printf("+-----+-----+-----+\n");
        }
    }
    else printf("\n\nNO SOLUTION\n\n");

    return 0;
}
