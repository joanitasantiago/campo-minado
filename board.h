#ifndef BOARD_H
#define BOARD_H

/* * *  D E F I N E S * * */

#define MAX_NEIGHBORS 8

/* * *  S T R U C T S  * * */

typedef struct cell
{
    bool isBomb;
    bool isOpen;
    int bombsAround;
    struct cell *neighbors[10];
} Cell;

/* * *  F U N C T I O N S * * */

void defineRowsAndColumns(int gameDifficulty, int *row, int *column);
void settingBoard(int row, int column, Cell board[row][column]);
void assignNeighbors(int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);

#endif