// THIS FILE IS FOR INDIVIDUAL TESTS.

#include <stdio.h>
#include <stdlib.h>
// strcpy and strlen would need library string.h:
#include <string.h>

// conditions:
// || or, && and, ! not

#define ROWS 3
#define COLS 4

void stringReverseByCopy()
{
    // initial 8 characters
    char str[8] = "0123456";
    // declared reversed empty array
    char reverse[8];
    // len = 7 -- counts from 0
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        reverse[(len - 1) - i] = str[i];
        // len - 1 -- to ensure final value is always \0 and make sure starts from right to left
        // then goes 7-0, 7-1, 7,2 ...
        // Continues until all values from str assigned to reverse
        printf("Loop %d Reverse: %c\n", i, reverse[i]);
    }

    // assign to final position \0 which is 0 in ASCII
    reverse[len] = '\0';
    // copies allfrom reverse to str
    strcpy(str, reverse);
    printf("%s\n", str);
}

void stringReverseInPlace()
{
    // initial 8 characters
    char str[] = "0123456";
    // len = 7 -- counts from 0
    int len = strlen(str);
    // shorter loop to avoid swapping twice
    // directly swaps values from both ends

    // str[0] <-> str[len - 1 - 0]
    // str[1] <-> str[len - 1 - 1]
    // str[2] <-> str[len - 1 - 2]
    // etc ...

    for (int i = 0; i < len / 2; i++)
    {
        // value from left
        char swap = str[i];
        // value from right gets assigned to left
        str[i] = str[len - 1 - i];
        // value from left gets assigned to right
        str[len - 1 - i] = swap;
    }
    printf("%s\n", str);
}

void readingString()
{
    // when we scanf:
    // entering " hello you!" will set myString to "hello"

    // below is a way possible to read a string with spaces
    // enfing on \n

    char myString[100];
    printf("Enter string: ");
    int i = 0;
    do
    {
        // keeps assigning value to prevailing index
        myString[i] = getchar();
        i++;
    } while (myString[i - 1] != '\n');
    // final position is \0
    myString[i] = '\0';
}

void twoDArray()
{

    // in C a constant is a defined value as above not "const"
    int twod[ROWS][COLS];

    // init array with variables in 2d plane
    // requires double loop
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            twod[i][j] = (i + 1) * (j + 1);
        }
    }

    // print the array in 2d visual plane
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLS; column++)
            printf("%4d", twod[row][column]);
        printf("\n");
    }
}

void heapAndStack()
{
    // stack
    int a;

    // heap
    int *p;
    p = (int *)malloc(sizeof(int));
    *p = 10;
    free(p);
    p = NULL;
    frea(p);
    p = (int *)malloc(20 * sizeof(int));
}

int main(void)
{
    int choice;

    printf("Which program would you like to run? ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        stringReverseByCopy();
    }
    else if (choice == 2)
    {
        stringReverseInPlace();
    }
    else if (choice == 3)
    {
        readingString();
    }
    else if (choice == 4)
    {
        twoDArray();
    }
    else if (choice == 5)
    {
        heapAndStack();
    }
    else
    {
        printf("Invalid choice");
    }
}