#ifndef BOARD_H
#define BOARD_H

/* * *  S T R U C T S  * * */

typedef struct cell
{
    bool isBomb;
    bool isOpen;
    int bombsAround;
    struct cell *neighbors[10];
} Cell;

/* * *  F U N C T I O N S * * */

/* * * BOARD SETTINGS * * */

void settingBoard(int row, int column, Cell board[row][column]);
void assignNeighbors(int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
int generateRandomColumn(int maxBombs);
int generateRandomRow(int maxBombs);
void distributeBombs(int maxBombs, int row, int column, Cell board[row][column]);
void incrementNeighbors(int row, int column, Cell board[row][column]);


/* * * SCREEN INTERACTIONS * * */

void printBoard(int row, int column, Cell board[row][column]);
void printColumnPositions(int column);
void printRowPosition(int row);
void printLine(int column);

/* * * GAMEPLAY * * */

#endif