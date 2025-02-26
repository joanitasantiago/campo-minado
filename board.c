#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "board.h"
#include "playersettings.h"

/* * * F U N C T I O N S * * */

/* * * SETTINGS * * */

/*Set default settings on board and call function to assign neighbors*/
Board* createBoard(int maxRows, int maxColumns)
{   
    Board *gameBoard = malloc(sizeof(Board));
    gameBoard->maxRows = maxRows;
    gameBoard->maxColumns = maxColumns;
    gameBoard->cells = malloc(maxRows * sizeof(Cell*));
    
    for (int i = 0; i < maxRows; i++)
    {
        gameBoard->cells[i] = malloc(maxColumns * sizeof(Cell));
    }
    
    Cell **cells = gameBoard->cells;
    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxColumns; j++)
        {
            cells[i][j].cellcolumn = j;
            cells[i][j].cellrow = i;
            cells[i][j].isBomb = false;
            cells[i][j].isOpen = false;
            cells[i][j].bombsAround = 0;
        }
    }

    assignNeighbors(maxRows, maxColumns, cells);

    return gameBoard;
}

/* Free the allocated memory for the board */
void freeBoard(Board *board)
{
    for (int i = 0; i < board->maxRows; i++)
    {
        free(board->cells[i]);
    }
    free(board->cells);
    free(board);
}

/*Assigns the neighbors of each cell on the board and stores them in an array.*/
void assignNeighbors(int maxRows, int maxColumns, Cell **board)
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
    case 99:
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
    case 99:
        newRow = (rand() % 30);
        break;
    }
    return newRow;
}

void distributeBombs(int maxBombs, int maxRows, int maxColumns, Cell **board)
{
    int newRow, newColumn, i = 1;
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

void incrementNeighbors(int maxRows, int maxColumns, Cell **board)
{
    int i, j, k;
    for (i = 0; i < maxRows; i++)
    {
        for (j = 0; j < maxColumns; j++)
        {
            if (board[i][j].isBomb == true)
            {
                k = 0;
                while (board[i][j].neighbors[k] != NULL)
                {
                    board[i][j].neighbors[k]->bombsAround++;
                    k++;
                }
            }
        }
    }
}

/* * * SCREEN INTERACTIONS * * */

void printBoard(int maxRows, int maxColumns, Cell **board)
{
    printColumnPositions(maxColumns);
    printLine(maxColumns);
    for (int i = 0; i < maxRows; i++)
    {
        printRowPosition(i);
        for (int j = 0; j < maxColumns; j++)
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

/*Prints a top bar with maxColumns positions */
void printColumnPositions(int maxColumns)
{
    printf("\n\t");
    for (int i = 0; i < maxColumns; i++)
    {
        printf("[%d]", i); /* imprime uma barra superior com as posições X */
    }
    printf("\n\n");
}

/*Prints a sidebar with a single maxRows position*/
void printRowPosition(int maxRows)
{
    printf("[%d]\t", maxRows);
}

void printLine(int maxColumns)
{
    printf("\t");
    for (int i = 0; i < maxColumns; i++)
    {
        printf(" _ ");
    }
    printf("\n");
}

/* * * GAMEPLAY * * */

void openCellChosenbyPlayer(int rowToBeOpened, int columnToBeOpened, int maxRows, int maxColumns, Cell **board)
{
    board[rowToBeOpened][columnToBeOpened].isOpen = true;
}

void openNeighbors(int selectedRow, int selectedColumn, int maxRows, int maxColumns, Cell **board)
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
                openNeighbors(vizinho->cellrow, vizinho->cellcolumn, maxRows, maxColumns, board);
            }
            k++;
        }
    }
}

void checkIfItsBomb(int *gameOver, int selectedRow, int selectedColumn, int maxRows, int maxColumns, Cell **board)
{
    if (board[selectedRow][selectedColumn].isBomb == true)
    {
        for (int i = 0; i < maxRows; i++)
        {
            for (int j = 0; j < maxColumns; j++)
            {
                board[i][j].isOpen = true;
            }
        }
        printBoard(maxRows, maxColumns, board);
        printf("* * BOOOOM!!! * *\nGame over! :(");
        *gameOver = 1;
    }
}

void checkWin(int *gameWin, int maxRows, int maxColumns, Cell **board)
{
    *gameWin = 1;
    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxColumns; j++)
        {
            if (board[i][j].isBomb == false && board[i][j].isOpen == false)
            {
                *gameWin = 0;
            }
        }
    }
}