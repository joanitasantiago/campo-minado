/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "playersettings.h"
#include "board.h"

int _main(int argc, char const *argv[])
{
    /* * *  Variables * 
    int gameDifficulty, maxBombs, maxRows, maxColumns, rowToBeOpened, columnToBeOpened, play = 1, gameOver = 0, gameWin = 0;
    srand(time(NULL));

    while (play == 1)
    {
        /* * *  Configuring player settings *
        gameDifficulty = playerDefinesGameDifficulty();
        defineRowsAndColumns(gameDifficulty, &maxRows, &maxColumns);
        maxBombs = defineAmountOfBombs(gameDifficulty);

        /* * *  Creating the board *

        Cell board[maxRows][maxColumns];

        // First user move
        printBoard(maxRows, maxColumns, board);
        playerTypesRowAndColumn(&rowToBeOpened, &columnToBeOpened);
        checkValidRowAndColumn(maxRows, maxColumns, &rowToBeOpened, &columnToBeOpened);
        checkIfCellIsAlreadyOpen(&rowToBeOpened, &columnToBeOpened, maxRows, maxColumns, board);
        openCellChosenbyPlayer(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board);
        distributeBombs(maxBombs, maxRows, maxColumns, board);
        incrementNeighbors(maxRows, maxColumns, board);
        openNeighbors(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board);
        //Game start 
        while (gameWin == 0 || gameOver == 0)
        {
            printBoard(maxRows, maxColumns, board);
            playerTypesRowAndColumn(&rowToBeOpened, &columnToBeOpened);
            checkValidRowAndColumn(maxRows, maxColumns, &rowToBeOpened, &columnToBeOpened);
            checkIfCellIsAlreadyOpen(&rowToBeOpened, &columnToBeOpened, maxRows, maxColumns, board);
            openCellChosenbyPlayer(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board);
            checkIfItsBomb(&gameOver, rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board);
            if (gameOver == 1)
            {
                playAgainOrClose(&play);
                break;
            }
            openNeighbors(rowToBeOpened, columnToBeOpened, maxRows, maxColumns, board);
            checkWin(&gameWin, maxRows, maxColumns, board);
            if (gameWin == 1)
            {
                printf("\nCongratulations! You won :)\n");
                playAgainOrClose(&play);
            }
        }
    }
    return 0;
}*/