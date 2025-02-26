#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "playersettings.h"
#include "board.h"

int main(int argc, char const *argv[])
{
    /* * *  Variables * * */
    int gameDifficulty, maxBombs, maxRows, maxColumns, rowToBeOpened, columnToBeOpened, play = 1, gameOver = 0, gameWin = 0;
    srand(time(NULL));

    /* * *  Configuring player settings * * */
    gameDifficulty = playerDefinesGameDifficulty();
    defineRowsAndColumns(gameDifficulty, &maxRows, &maxColumns);
    maxBombs = defineAmountOfBombs(gameDifficulty);

    /*  Creating the board */
    Board *gameBoard = createBoard(maxRows, maxColumns);

    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxColumns; j++)
        {
           printf("[ %d | %d ] ", gameBoard->cells[i][j].cellrow, gameBoard->cells[i][j].cellcolumn);
        }
        printf("\n");
    }
    

    

    return 0;
}