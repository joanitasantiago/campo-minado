#ifndef PLAYERSETTINGS_H
#define PLAYERSETTINGS_H

/* * *  I N C L U D E S  * * */

#include <stdio.h>
#include <stdbool.h>
#include "board.h"


/* * *  F U N C T I O N S * * */

/* * * BOARD SETTINGS * * */

int PlayerDefinesGameDifficulty();
void defineRowsAndColumns(int gameDifficulty, int *row, int *column);
int defineAmountOfBombs(int gameDifficulty);


/* * * GAMEPLAY * * */

void playerTypesRowAndColumn(int *rowToBeOpened, int *columnToBeOpened);
void checkValidRowAndColumn(int row, int column, int *rowToBeChecked, int *columnToBeChecked);
void openCellChosenbyPlayer(int rowToBeOpened, int columnToBeOpened, int row, int column, Cell board[row][column]);

#endif