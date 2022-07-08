/* * * * * *  I N C L U D E S * * * * * */

#include <stdio.h>
#include <stdbool.h>
#include "playersettings.h"
#include "board.h"


/* * * * * *  F U N C T I O N S  * * * * * */

/*Returns a user-entered number that refers to the chosen game difficulty*/
int defineDifficulty()
{
    int difficulty;
    printf("Choose the board configuration:\n<1> EASY\n<2> INTERMEDIATE\n<3> EXPERT\n");
    printf("Type here:\t");
    scanf(" %d", &difficulty);
    while ((difficulty < 1) || (difficulty > 3))
    {
        printf("Invalid option - try again:\t");
        scanf(" %d", &difficulty);
    }
    return difficulty;
}

/*Open a cell according to the number entered by the user */
void playerChooseCellToOpen(int row, int column, Cell board[row][column])
{
    int selectedRow, selectedColumn;
    printf("Type the cell you want to open:\t");
    scanf(" %d %d", &selectedRow, &selectedColumn);
    checkValidRowAndColumn(row, column,&selectedRow,&selectedColumn);
    board[selectedRow][selectedColumn].isOpen = true;
}

/*Checks if the number entered is valid*/
void checkValidRowAndColumn(int row, int column, int *selectedRow, int *selectedColumn)
{
    while ((*selectedRow < 0) || (*selectedRow >= row) || (*selectedColumn < 0) || (*selectedColumn >= column))
    {
        printf("Invalid option - try again:\t");
        scanf(" %d %d", &selectedRow, &selectedColumn);
    }
}