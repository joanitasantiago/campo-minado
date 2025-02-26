#ifndef BOARD_H
#define BOARD_H

/* * *  S T R U C T S  * * */

typedef struct cell
{
    bool isBomb;
    bool isOpen;
    int bombsAround;
    int cellrow;
    int cellcolumn;
    struct cell *neighbors[10];
} Cell;

typedef struct board
{
    int maxRows;
    int maxColumns;
    Cell **cells;
} Board;

/* * *  F U N C T I O N S * * */

Board* createBoard(int maxRows, int maxColumns);

/* * * SETTINGS * * */
void assignNeighbors(int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
int generateRandomColumn(int maxBombs);
int generateRandomRow(int maxBombs);
void distributeBombs(int maxBombs, int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
void incrementNeighbors(int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);


/* * * SCREEN INTERACTIONS * * */

void printBoard(int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
void printColumnPositions(int maxColumns);
void printRowPosition(int maxRows);
void printLine(int maxColumns);

/* * * GAMEPLAY * * */
void openCellChosenbyPlayer(int rowToBeOpened, int columnToBeOpened, int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
void openNeighbors(int selectedRow, int selectedColumn, int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
void checkIfItsBomb(int *gameover, int selectedRow, int selectedColumn, int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
void checkWin(int *gameWin, int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);

#endif