#include <stdio.h>
#include <stdlib.h>
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
    system("cls");

    /* * *  First user move  * * */
    printBoard(row, column, board);
    playerChooseCellToOpen(row, column, board);

    /* * * Setting the bombs * * */
    distributeBombs(maxBombs, row, column, board);
    incrementNeighbors(row, column, board);
    system("cls");
    printBoard(row, column, board);
    system("pause");

    /* * * Gameplay * * */

    /* * * TESTE
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("-> POSIÇÃO [%d][%d]:", i, j);
            printf("BOMBAS PERTO: %d <-\n", board[i][j].bombsAround);
        }
        printf("\n");
    } * * */

    return 0;
}