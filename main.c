#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "playersettings.h"
#include "board.h"

int main(int argc, char const *argv[])
{
    /* * *  Variables * * */
    int gameDifficulty, row, column;

    /* * *  Configuring player settings * * */
    gameDifficulty = defineDifficulty();
    defineRowsAndColumns(gameDifficulty, &row, &column);

    /* * *  Creating the board * * */
    Cell board[row][column];
    settingBoard(row, column, board);
    assignNeighbors(row, column, board);

    /* * *  First user move  * * */
    playerChooseCellToOpen(row, column, board);

    /* * * Setting the bombs * * */

    return 0;
}