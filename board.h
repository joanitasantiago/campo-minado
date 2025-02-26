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
    struct cell* neighbors[10];
} Cell;

typedef struct board
{
    int maxRows;
    int maxColumns;
    Cell **cells;
} Board;

/* * *  F U N C T I O N S * * */

Board* createBoard(int maxRows, int maxColumns);
void freeBoard(Board *board);

/* * * SETTINGS * * */
void assignNeighbors(int maxRows, int maxColumns, Cell **board);
int generateRandomColumn(int maxBombs);
int generateRandomRow(int maxBombs);
void distributeBombs(int maxBombs, int maxRows, int maxColumns, Cell **board);
void incrementNeighbors(int maxRows, int maxColumns, Cell **board);


/* * * SCREEN INTERACTIONS * * */

void printBoard(int maxRows, int maxColumns, Cell **board);
void printColumnPositions(int maxColumns);
void printRowPosition(int maxRows);
void printLine(int maxColumns);

/* * * GAMEPLAY * * */
void openCellChosenbyPlayer(int rowToBeOpened, int columnToBeOpened, int maxRows, int maxColumns, Cell **board);
void openNeighbors(int selectedRow, int selectedColumn, int maxRows, int maxColumns, Cell **board);
void checkIfItsBomb(int *gameover, int selectedRow, int selectedColumn, int maxRows, int maxColumns, Cell **board);
void checkWin(int *gameWin, int maxRows, int maxColumns, Cell **board);

#endif