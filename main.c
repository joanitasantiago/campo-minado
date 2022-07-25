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

    /* * * Setting the bombs * * */
    distributeBombs(maxBombs, row, column, board);
    incrementNeighbors(row, column, board);
    
    /* * *  Game start * * */
    printBoard(row, column, board);

    return 0;
}