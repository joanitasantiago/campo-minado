#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "playersettings.h"
#include "board.h"

int main(int argc, char const *argv[])
{
    /* * *  Variables * * */
    int gameDifficulty, maxBombs, row, column;

    /* * *  Configuring player settings * * */
    gameDifficulty = defineDifficulty();
    maxBombs = defineAmountOfBombs(gameDifficulty);
    defineRowsAndColumns(gameDifficulty, &row, &column);

    /* * *  Creating the board * * */
    Cell board[row][column];
    settingBoard(row, column, board);
    assignNeighbors(row, column, board);

    /* * *  First user move  * * */
    playerChooseCellToOpen(row, column, board);

    /* * * Setting the bombs * * */
    distributeBombs(maxBombs, row, column, board);


    /* * * TESTE * * */
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("-> POSIÇÃO [%d][%d]:", i, j);
            printf("ABERTO?: %d | BOMBA?: %d <-\n", board[i][j].isOpen, board[i][j].isBomb);
        }
        
        printf("\n");
    }

    return 0;
}