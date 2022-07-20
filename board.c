#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "board.h"
#include "playersettings.h"

/* * *  F U N C T I O N S * * */

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

/*Set default settings on the board*/
void settingBoard(int row, int column, Cell board[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            board[i][j].isBomb = false;
            board[i][j].isOpen = false;
            board[i][j].bombsAround = 0;
        }
    }
}

/*Assigns the neighbors of each cell on the board and stores them in an array.*/
void assignNeighbors(int maxRows, int maxColumns, Cell board[maxRows][maxColumns])
{
    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxColumns; j++)
        {
            if (i == 0) /*superior*/
            {
                if (j == 0) /* canto esquerdo */
                {
                    board[i][j].neighbors[0] = &board[i][j + 1];
                    board[i][j].neighbors[1] = &board[i + 1][j];
                    board[i][j].neighbors[2] = &board[i + 1][j + 1];
                }
                else if (j >= 1 && j < (maxColumns - 1)) /*meio*/
                {
                    board[i][j].neighbors[0] = &board[i][j - 1];
                    board[i][j].neighbors[1] = &board[i][j + 1];
                    board[i][j].neighbors[2] = &board[i + 1][j - 1];
                    board[i][j].neighbors[3] = &board[i + 1][j];
                    board[i][j].neighbors[4] = &board[i + 1][j + 1];
                }
                else if (j == (maxColumns - 1)) /* canto direito */
                {
                    board[i][j].neighbors[0] = &board[i][j - 1];
                    board[i][j].neighbors[1] = &board[i + 1][j - 1];
                    board[i][j].neighbors[2] = &board[i + 1][j];
                }
            }
            if (i >= 1 && i < (maxRows - 1)) /*meio*/
            {
                if (j == 0) /*canto esquerdo*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j];
                    board[i][j].neighbors[1] = &board[i - 1][j + 1];
                    board[i][j].neighbors[2] = &board[i][j + 1];
                    board[i][j].neighbors[3] = &board[i + 1][j];
                    board[i][j].neighbors[4] = &board[i + 1][j + 1];
                }
                else if (j >= 1 && j < (maxColumns - 1)) /*meio*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j - 1];
                    board[i][j].neighbors[1] = &board[i - 1][j];
                    board[i][j].neighbors[2] = &board[i - 1][j + 1];
                    board[i][j].neighbors[3] = &board[i][j - 1];
                    board[i][j].neighbors[4] = &board[i][j + 1];
                    board[i][j].neighbors[5] = &board[i + 1][j - 1];
                    board[i][j].neighbors[6] = &board[i + 1][j];
                    board[i][j].neighbors[7] = &board[i + 1][j + 1];
                }
                else if (j == (maxColumns - 1)) /*canto direito*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j];
                    board[i][j].neighbors[1] = &board[i - 1][j - 1];
                    board[i][j].neighbors[2] = &board[i][j - 1];
                    board[i][j].neighbors[3] = &board[i + 1][j - 1];
                    board[i][j].neighbors[4] = &board[i + 1][j];
                }
            }
            if (i == (maxRows - 1)) /*inferior*/
            {
                if (j == 0) /*canto esquerdo*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j];
                    board[i][j].neighbors[1] = &board[i - 1][j + 1];
                    board[i][j].neighbors[2] = &board[i][j + 1];
                }
                else if (j >= 1 && j < (maxColumns - 1)) /*meio*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j - 1];
                    board[i][j].neighbors[1] = &board[i - 1][j];
                    board[i][j].neighbors[2] = &board[i - 1][j + 1];
                    board[i][j].neighbors[3] = &board[i][j - 1];
                    board[i][j].neighbors[4] = &board[i][j + 1];
                }
                else if (j == (maxColumns - 1)) /*canto direito*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j - 1];
                    board[i][j].neighbors[1] = &board[i - 1][j];
                    board[i][j].neighbors[2] = &board[i][j - 1];
                }
            }
        }
    }
}

int generateRandomColumn(int maxBombs)
{
    srand(time(NULL));
    int newColumn;
    switch (maxBombs)
    {
    case 10:

        newColumn = 1 + (rand() % 9);
        break;
    case 40:
        newColumn = 1 + (rand() % 16);
        break;
    case 3:
        newColumn = 1 + (rand() % 16);
        break;
    }
    return newColumn;
}

int generateRandomRow(int maxBombs)
{
    srand(time(NULL));
    int newRow;
    switch (maxBombs)
    {
    case 10:

        newRow = 1 + (rand() % 9);
        break;
    case 40:
        newRow = 1 + (rand() % 16);
        break;
    case 3:
        newRow = 1 + (rand() % 30);
        break;
    }
    return newRow;
}

void distributeBombs(int maxBombs, int row, int column, Cell board[row][column])
{
    int newRow, newColumn, i = 0;
    while (i <= maxBombs)
    {
        newRow = generateRandomRow(maxBombs);
        newColumn = generateRandomColumn(maxBombs);
        if (board[newRow][newColumn].isOpen == false && board[newRow][newColumn].isBomb == false)
        {
            board[newRow][newColumn].isBomb = true;
            i++;
        }
    }
}