#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "playersettings.h"
#include "board.h"

int main(int argc, char const *argv[])
{
    /* * *  Variables * * */
    int gameDifficulty, maxBombs, row, column, rowToBeOpened, columnToBeOpened;
    srand(time(NULL));

    /* * *  Configuring player settings * * */
    gameDifficulty = PlayerDefinesGameDifficulty();
    defineRowsAndColumns(gameDifficulty, &row, &column);
    maxBombs = defineAmountOfBombs(gameDifficulty);

    /* * *  Creating the board * * */
    Cell board[row][column];
    settingBoard(row, column, board);
    assignNeighbors(row, column, board);

    /* * *  First user move  * * */
    printBoard(row, column, board);
    playerTypesRowAndColumn(&rowToBeOpened, &columnToBeOpened);
    checkValidRowAndColumn(row, column, &rowToBeOpened, &columnToBeOpened);
    openCellChosenbyPlayer(rowToBeOpened, columnToBeOpened, row, column, board);
    distributeBombs(maxBombs, row, column, board);
    incrementNeighbors(row, column, board);
    openNeighbors(rowToBeOpened, columnToBeOpened, row, column, board);

    /*TESTE
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            printf("CELULA [%d] [%d]:\n", i, j);
            while (board[i][j].neighbors[k] != NULL)
            {
                printf("VIZINHO %d > ", k);
                printf("isBomb: %d | ", board[i][j].neighbors[k]->isBomb);
                printf("isOpen: %d | ", board[i][j].neighbors[k]->isOpen);
                printf("bombsAround: %d | ", board[i][j].neighbors[k]->bombsAround);
                printf("cellrow: %d | ", board[i][j].neighbors[k]->cellrow);
                printf("cellcolumn: %d |\n", board[i][j].neighbors[k]->cellcolumn);
                k++;
            }
            k = 0;
            printf("\n");
        }
    }*/
    
    /* * *  Game start * * */
    do
    {
        printBoard(row, column, board);
        playerTypesRowAndColumn(&rowToBeOpened, &columnToBeOpened);
        checkValidRowAndColumn(row, column, &rowToBeOpened, &columnToBeOpened);
        openCellChosenbyPlayer(rowToBeOpened, columnToBeOpened, row, column, board);
        openNeighbors(rowToBeOpened, columnToBeOpened, row, column, board);
        printf("FIIIIMMMMMM");
    } while (1);
    

    return 0;
}