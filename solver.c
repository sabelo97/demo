/* OK first thing this is a comment, anywhere you see /* that is the start of a comment and to end to comment its */ /* i had to start it again cause i just ended it, get the point? */
/* comments do not affect anything in the program, its just to see whats going on in the program, if you and some other programmer is working on 1 code, its good to leave comments to
kind of brief him/her on what you did and what blocks do what. also a side note, the spaces you see is called white space, we use this to read the code better and understand what goes to what block,
you can imagine how difficult it would be if there was no white space anywhere. Also always use tab to indent your code, it just makes everything line up better.*/



/*at the beginning of every c program there will be these include and define lines, these define what libraries you are using in your program.
its also good to add a comment stating what the hell this program does
if you want to manipulate string operations u need to put #include <stringlib> etc.

NOTE! that only libraries that are in the standard c lib is #include <whatever> if you want to include a 3rd party one like a one that you made its "#include whatever" without the <>*/
#include <stdio.h> /* you will most probably see the line below and all programs in C,  it is the standard lib*/
/* the defines bellow set the color of the text */
#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"

/* this is the start of the program every time you see a { it is the start of a "block" of code, and } is the end of a block of code
 notice that the line below is "int isAvailable" that is the start of a function, the function name is "isAvailable"
afte that you see (int puzzle[][9]) this is the deceleration of a integer with the name puzzle and it can hold up to 9 characters this is called memory management, some languages do it for you, C doesn't,
 after that the integers row, col and num are created. anything starting with int "name" is the deceleration of a integer.
intergars are just that, they only hold whole numbers (0123456789....) no decimal places and no other characters */

int isAvailable(int puzzle[][9], int row, int col, int num)
{
    /* below you see the deceleration of more integers, but this time with a =, this is called assignment, you are assigning a number to it,
     in this case it gets the value of the calculation row divided by 3 times 3. 
    NOTE! C always does calculations in order of operation, so 3+3x3 will equal 12, you have to write it like (3+3)x3 to get the result you want */
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i, j;
/* below you see the for command, this is a loop, it will keep looping over and over until the tests are false, in the brackets you put the tests, here you see i=0; i<9; ++i lets break this down
i=0; now if you read this its if i is equal to 0, but its not, the way its read is assign the number 0 to i, to test if the value of i is equal to a number you type i==0,
i<9; if the value of i is less then 9
++i; this is called incrementing, AKA add 1 to the value of i, so if the number of i is equal to 2, and we type ++i, the value of i is now 3, you can also decrement values with -- instead of ++
NOTE! this is the most used way to make a loop that never ends, it will keep running over and over cause all the tests are never false, if you look at it:
assign 0 to i 
is i less than 9
increment i
but if you read it again it assigns 0 to i as soon as the loop starts. so one test will always be false and the loop will run. */
    for(i=0; i<9; ++i)
    {
        /* these are tests */
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int puzzle[][9], int row, int col)
{
    int i;
    /* here you see a if within a if, this is called "nesting" if statements */
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return fillSudoku(puzzle, row, col+1);
            /* this is the first time you see else and else if, else: if the above tests are all false execute the code that fallows, else if, only execute to following code if these tests are true */
            else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
            /* "return 0/1" outputs 1 or 0, too see if the block of code ran with no issues or errors. */
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
/* this is the main function. when you compile and run your code, the program will always start with the main function. ALWAYS! */
int main()
{
    int i, j, g = 0;
    int VERBOSE = 0;
    /* bellow you see the deceleration and assignment of numbers, but alot of numbers, this is the creation of a array, an array is like a integer but it can hold alot more numbers,
     so why use integers if you can just use arrays?
    integers take less memory, everything you declare takes up space, so if you making a big program with 1000s of arrays, it will take alot of mem, that [9] is the memory to take, look at it as a box 
    the [9] is the size of the box. and the digits are stuff in the box*/
    int puzzle[9][9]={{0, 0, 8, 0, 9, 0, 0, 5, 0},
                      {0, 1, 0, 0, 6, 5, 0, 0, 4},
                      {4, 0, 5, 0, 0, 0, 2, 0, 9},
                      {7, 3, 0, 0, 5, 0, 1, 0, 8},
                      {5, 0, 2, 0, 0, 0, 4, 0, 7},
                      {1, 0, 4, 0, 3, 0, 0, 9, 6},
                      {8, 0, 1, 0, 0, 0, 7, 0, 2},
                      {3, 0, 0, 1, 8, 0, 0, 4, 0},
                      {0, 4, 0, 0, 2, 0, 3, 0, 0}};
/* the printf command is to print text out on the screen the \n is a command, \n means new line, if this was not there, the whole program will be on one line, there are others like \t is tab
 and the KRED is to specify the color, in this case its red. we defined these at the beggining of the code. */

    printf("%sDo you want  verbose output? (show all the tries I have made)\n\n 1 = yes\n 0 = no\n", KGRN);
    scanf("%d", &VERBOSE);

    /* the above is asking if the user want to see all the tries made or not and via the scanf command it assigns the number to VERBOSE that we declared earlier. the %s is to wait for string input that 
    is defined and the end of the line (, KGRN)
    and the %d is to wait for digit input, the scanf command pauses the program until the user inputs a value the & is used to tell the compiler that i want to assign what ever the user inputs to VERBOSE*/

    printf("%syour original unsolved puzzle is:\n\n", KRED);
    printf("%s\n+-----+-----+-----+\n", KNRM);

    for(i=1; i<10; ++i)
    { /* here you see %d this is like saying just hold up, ill tell you what you need to put there now now, at the end of this line you see , puzzle [i-1][j-1] the value of puzzle is then outputed in the place of %d*/
        for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);
        printf("|\n");
        if (i%3 == 0) printf("+-----+-----+-----+\n\n");
    }

    if (VERBOSE == 1)
    {

        for (g = 0; g < 10; ++g)
        {
        if(fillSudoku(puzzle, 1, 1));
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

/* if you didint get what this code does its a sudoku game solver, it takes the array of numbers in puzzle on line 98 nad works it out, Test yourself... go to the Un commented source code and try to read
AND understand it */
