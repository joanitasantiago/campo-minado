#ifndef PLAYERSETTINGS_H
#define PLAYERSETTINGS_H

/* * *  I N C L U D E S  * * */

#include <stdio.h>
#include <stdbool.h>
#include "board.h"


/* * *  F U N C T I O N S * * */

/* * * BOARD SETTINGS * * */

int playerDefinesGameDifficulty();
void defineRowsAndColumns(int gameDifficulty, int *row, int *column);
int defineAmountOfBombs(int gameDifficulty);


/* * * GAMEPLAY * * */

void playerTypesRowAndColumn(int *rowToBeOpened, int *columnToBeOpened);
void checkValidRowAndColumn(int maxRows, int maxColumns, int *selectedRow, int *selectedColumn);
void checkIfCellIsAlreadyOpen(int *selectedRow, int *selectedColumn, int maxRows, int maxColumns, Cell board[maxRows][maxColumns]);
void playAgainOrClose(int *play);

#endif