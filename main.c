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

    while (play == 1)
    {
        /* * *  Configuring player settings * * */
        gameDifficulty = playerDefinesGameDifficulty();
        defineRowsAndColumns(gameDifficulty, &maxRows, &maxColumns);
        maxBombs = defineAmountOfBombs(gameDifficulty);

        /* * *  Creating the board * * */
        Board *board = createBoard(maxRows, maxColumns);

        /* * *  First user move  * * */
        printBoard(maxRows, maxColumns, board->cells);
        playerTypesRowAndColumn(&rowToBeOpened, &columnToBeOpened);
        checkValidRowAndColumn(maxRows, maxColumns, &rowToBeOpened, &columnToBeOpened);
        checkIfCellIsAlreadyOpen(&rowToBeOpened, &columnToBeOpened, maxRows, maxColumns, board->cells);
        openCellChosenbyPlayer(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board->cells);
        distributeBombs(maxBombs, maxRows, maxColumns, board->cells);
        incrementNeighbors(maxRows, maxColumns, board->cells);
        openNeighbors(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board->cells);

        /* * *  Game start * * */
        while (gameWin == 0 && gameOver == 0)
        {
            printBoard(maxRows, maxColumns, board->cells);
            playerTypesRowAndColumn(&rowToBeOpened, &columnToBeOpened);
            checkValidRowAndColumn(maxRows, maxColumns, &rowToBeOpened, &columnToBeOpened);
            checkIfCellIsAlreadyOpen(&rowToBeOpened, &columnToBeOpened, maxRows, maxColumns, board->cells);
            openCellChosenbyPlayer(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board->cells);
            checkIfItsBomb(&gameOver, rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board->cells);
            if (gameOver == 1)
            {
                playAgainOrClose(&play);
                break;
            }
            openNeighbors(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board->cells);
            checkWin(&gameWin, maxRows, maxColumns, board->cells);
            if (gameWin == 1)
            {
                printf("\nCongratulations! You won :)\n");
                playAgainOrClose(&play);
            }
        }

        freeBoard(board);
    }
    return 0;
}