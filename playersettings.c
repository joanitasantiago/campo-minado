/* * * * * *  I N C L U D E S * * * * * */

#include <stdio.h>
#include <stdbool.h>
#include "playersettings.h"
#include "board.h"


/* * * * * *  F U N C T I O N S  * * * * * */

/* * * BOARD SETTINGS * * */

/*Returns a user-entered number that refers to the chosen game difficulty*/
int PlayerDefinesGameDifficulty()
{
    int difficulty;
    printf("Choose the board level:\n<1> EASY\n<2> INTERMEDIATE\n<3> EXPERT\n");
    printf(">>:\t");
    scanf(" %d", &difficulty);
    while ((difficulty < 1) || (difficulty > 3))
    {
        printf("Invalid option - try again:\t");
        scanf(" %d", &difficulty);
    }
    return difficulty;
}

/*Define the number of rows and columns that will form the board based on the difficulty chosen by the user*/
void defineRowsAndColumns(int gameDifficulty, int *row, int *column)
{
    switch (gameDifficulty)
    {
    case 1:
        *row = 9;
        *column = 9;
        break;
    case 2:
        *row = 16;
        *column = 16;
        break;
    case 3:
        *row = 30;
        *column = 16;
        break;
    }
}

/*Set the amount of bombs on the board based on the chosen difficulty*/
int defineAmountOfBombs(int gameDifficulty)
{
    int maxBombs;
    switch (gameDifficulty)
    {
    case 1:
        maxBombs = 10;
        break;
    case 2:
        maxBombs = 40;
        break;
    case 3:
        maxBombs = 99;
        break;
    }
    return maxBombs;
}


/* * * GAMEPLAY * * */

/* Asks the user to enter a row and column number */
void playerTypesRowAndColumn(int *rowToBeOpened, int *columnToBeOpened)
{
    int tempRow, tempColumn;
    printf("Type the [ROW] and [COLUMN] you want to open:\t");
    scanf(" %d %d", &tempRow, &tempColumn);
    *rowToBeOpened = tempRow;
    *columnToBeOpened = tempColumn;
}

/* Checks if the number entered is valid */
void checkValidRowAndColumn(int row, int column, int *rowToBeChecked, int *columnToBeChecked)
{
    int tempRow, tempColumn;
    while ((*rowToBeChecked < 0) || (*rowToBeChecked > row) || (*columnToBeChecked < 0) || (*columnToBeChecked > column))
    {
        printf("Invalid option - try again:\t");
        scanf(" %d %d", &tempRow, &tempColumn);
        *rowToBeChecked = tempRow;
        *columnToBeChecked = tempColumn;
    }
}