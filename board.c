#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "board.h"
#include "playersettings.h"

/* * * F U N C T I O N S * * */

/* * * BOARD SETTINGS * * */

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
            board[i][j].cellrow = i;
            board[i][j].cellcolumn = j;
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
                    board[i][j].neighbors[3] = NULL;
                }
                else if (j >= 1 && j < (maxColumns - 1)) /*meio*/
                {
                    board[i][j].neighbors[0] = &board[i][j - 1];
                    board[i][j].neighbors[1] = &board[i][j + 1];
                    board[i][j].neighbors[2] = &board[i + 1][j - 1];
                    board[i][j].neighbors[3] = &board[i + 1][j];
                    board[i][j].neighbors[4] = &board[i + 1][j + 1];
                    board[i][j].neighbors[5] = NULL;
                }
                else if (j == (maxColumns - 1)) /* canto direito */
                {
                    board[i][j].neighbors[0] = &board[i][j - 1];
                    board[i][j].neighbors[1] = &board[i + 1][j - 1];
                    board[i][j].neighbors[2] = &board[i + 1][j];
                    board[i][j].neighbors[3] = NULL;
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
                    board[i][j].neighbors[5] = NULL;
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
                    board[i][j].neighbors[8] = NULL;
                }
                else if (j == (maxColumns - 1)) /*canto direito*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j];
                    board[i][j].neighbors[1] = &board[i - 1][j - 1];
                    board[i][j].neighbors[2] = &board[i][j - 1];
                    board[i][j].neighbors[3] = &board[i + 1][j - 1];
                    board[i][j].neighbors[4] = &board[i + 1][j];
                    board[i][j].neighbors[5] = NULL;
                }
            }
            if (i == (maxRows - 1)) /*inferior*/
            {
                if (j == 0) /*canto esquerdo*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j];
                    board[i][j].neighbors[1] = &board[i - 1][j + 1];
                    board[i][j].neighbors[2] = &board[i][j + 1];
                    board[i][j].neighbors[4] = NULL;
                }
                else if (j >= 1 && j < (maxColumns - 1)) /*meio*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j - 1];
                    board[i][j].neighbors[1] = &board[i - 1][j];
                    board[i][j].neighbors[2] = &board[i - 1][j + 1];
                    board[i][j].neighbors[3] = &board[i][j - 1];
                    board[i][j].neighbors[4] = &board[i][j + 1];
                    board[i][j].neighbors[5] = NULL;
                }
                else if (j == (maxColumns - 1)) /*canto direito*/
                {
                    board[i][j].neighbors[0] = &board[i - 1][j - 1];
                    board[i][j].neighbors[1] = &board[i - 1][j];
                    board[i][j].neighbors[2] = &board[i][j - 1];
                    board[i][j].neighbors[3] = NULL;
                }
            }
        }
    }
}

int generateRandomColumn(int maxBombs)
{
    int newColumn;
    switch (maxBombs)
    {
    case 10:
        newColumn = (rand() % 9);
        break;
    case 40:
        newColumn = (rand() % 16);
        break;
    case 3:
        newColumn = (rand() % 16);
        break;
    }
    return newColumn;
}

int generateRandomRow(int maxBombs)
{
    int newRow;
    switch (maxBombs)
    {
    case 10:

        newRow = (rand() % 9);
        break;
    case 40:
        newRow = (rand() % 16);
        break;
    case 3:
        newRow = (rand() % 30);
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

void incrementNeighbors(int row, int column, Cell board[row][column])
{
    int i, j, k = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (board[i][j].isBomb == true)
            {
                while (board[i][j].neighbors[k] != NULL)
                {
                    board[i][j].neighbors[k]->bombsAround++;
                    k++;
                }
                k = 0;
            }
        }
    }
}

/* * * SCREEN INTERACTIONS * * */

void printBoard(int row, int column, Cell board[row][column])
{
    printColumnPositions(column);
    printLine(column);
    for (int i = 0; i < row; i++)
    {
        printRowPosition(i);
        for (int j = 0; j < column; j++)
        {
            if (board[i][j].isOpen == false)
            {
                printf("|_|");
            }
            else
            {
                if (board[i][j].isBomb == true)
                {
                    printf("|*|");
                }
                else
                {
                    {
                        printf("|%d|", board[i][j].bombsAround);
                    }
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*Prints a top bar with column positions */
void printColumnPositions(int column)
{
    printf("\n\t");
    for (int i = 0; i < column; i++)
    {
        printf("[%d]", i); /* imprime uma barra superior com as posições X */
    }
    printf("\n\n");
}

/*Prints a sidebar with a single row position*/
void printRowPosition(int row)
{
    printf("[%d]\t", row);
}

void printLine(int column)
{
    printf("\t");
    for (int i = 0; i < column; i++)
    {
        printf(" _ ");
    }
    printf("\n");
}

/* * * GAMEPLAY * * */
void openCellChosenbyPlayer(int rowToBeOpened, int columnToBeOpened, int row, int column, Cell board[row][column])
{
    if (board[rowToBeOpened][columnToBeOpened].isOpen == true)
    {
        printf(" > IT'S ALREADY OPEN <");
    }
    else
    {
        board[rowToBeOpened][columnToBeOpened].isOpen = true;
    }
}

void openNeighbors(int selectedRow, int selectedColumn, int row, int column, Cell board[row][column])
{
    int k = 0;
    Cell atual = board[selectedRow][selectedColumn];
    if (atual.bombsAround == 0)
    {
        while (atual.neighbors[k] != NULL)
        {
            Cell *vizinho = atual.neighbors[k];
            if (vizinho->isBomb == false && vizinho->isOpen == false)
            {
                vizinho->isOpen = true;
                openNeighbors(vizinho->cellrow, vizinho->cellcolumn, row, column, board);
            }
            k++;
        }
    }
}