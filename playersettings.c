/* * * * * *  I N C L U D E S * * * * * */

#include <stdio.h>
#include <stdbool.h>
#include "playersettings.h"
#include "board.h"

/* * * * * *  F U N C T I O N S  * * * * * */

/* * * BOARD SETTINGS * * */

/*Returns a user-entered number that refers to the chosen game difficulty*/
int playerDefinesGameDifficulty()
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
void defineRowsAndColumns(int gameDifficulty, int *maxRows, int *maxColumns)
{
    switch (gameDifficulty)
    {
    case 1:
        *maxRows = 9;
        *maxColumns = 9;
        break;
    case 2:
        *maxRows = 16;
        *maxColumns = 16;
        break;
    case 3:
        *maxRows = 30;
        *maxColumns = 16;
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

/* Asks the user to enter a maxRows and maxColumns number */
void playerTypesRowAndColumn(int *rowToBeOpened, int *columnToBeOpened)
{
    int tempRow, tempColumn;
    printf("Type the [ROW] and [COLUMN] you want to open:\t");
    scanf(" %d %d", &tempRow, &tempColumn);
    *rowToBeOpened = tempRow;
    *columnToBeOpened = tempColumn;
}

/* Checks if the number entered is valid */
void checkValidRowAndColumn(int maxRows, int maxColumns, int *selectedRow, int *selectedColumn)
{
    int tempRow, tempColumn;
    while ((*selectedRow < 0) || (*selectedRow > maxRows) || (*selectedColumn < 0) || (*selectedColumn > maxColumns))
    {
        printf("Invalid option - try again:\t");
        scanf(" %d %d", &tempRow, &tempColumn);
        *selectedRow = tempRow;
        *selectedColumn = tempColumn;
    }
}

void checkIfCellIsAlreadyOpen(int *selectedRow, int *selectedColumn, int maxRows, int maxColumns, Cell board[maxRows][maxColumns])
{
    int tempRow, tempColumn;
    while (board[*selectedRow][*selectedColumn].isOpen == true)
    {
        printf("This cell it's already open - try again:\t");
        scanf(" %d %d", &tempRow, &tempColumn);
        *selectedRow = tempRow;
        *selectedColumn = tempColumn;
    }
}

void playAgainOrClose(int *play)
{
    int option;
    printf("\nEnter [1] to play again or [0] to close the game >>\t");
    scanf("%d", &option);
    while (option < 0 || option > 1)
    {
        printf("\nInvalid option - try again >>\t");
        scanf("%d", &option);
    }
    *play = option;
}