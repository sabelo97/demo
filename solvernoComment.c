#include <stdio.h> 
#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#include <time.h>


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
int out()
{
    int i, j, g = 0;
    int VERBOSE = 0;

    int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};


    printf("%sDo you want  verbose output? (show all the tries I have made)\n\n 1 = yes\n 0 = no\n\n ", KGRN);
    scanf("%d", &VERBOSE);

    printf("%syour original unsolved puzzle is:\n\n", KRED);
    printf("%s\n+-----+-----+-----+\n", KNRM);

    for(i=1; i<10; ++i)
    { 
        for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
        printf("|\n");
        if (i%3 == 0) printf("+-----+-----+-----+\n");
        if (i%9 == 0) printf("\n");
    }

    if (VERBOSE == 1)
    {

        for (g = 0; g < 10; ++g)
        {
        if(fillSudoku(puzzle, 1, 1));
        {
            printf("%syour puzzle so far is: \n", KRED);
            printf("%s\n+-----+-----+-----+ \n", KNRM);
            for(i=1; i<10; ++i)
            {
                for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
                printf("|\n");
                if (i%3 == 0) printf("+-----+-----+-----+\n");
                if (i%9 == 0) printf("\n");
            }
        }}}
    if(fillSudoku(puzzle, 0, 0))
    {
        printf("%sDONE!!!! The solved puzzle is: \n", KRED);
        printf("%s\n+-----+-----+-----+\n", KNRM);
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
            printf("|\n");
            if (i%3 == 0) printf("+-----+-----+-----+\n");
            if (i%9 == 0) printf("\n");
        }
    }
    else printf("\n\nNO SOLUTION\n\n");

    return 0;
}

int main()
{
    clock_t t;
    t = clock();
    out();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
 
    printf("%sI took took %f seconds to execute, I'm getting rusty\n\n",KRED, time_taken);
    return 0;
}

