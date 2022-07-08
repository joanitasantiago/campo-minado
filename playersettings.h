#ifndef PLAYERSETTINGS_H
#define PLAYERSETTINGS_H

/* * *  I N C L U D E S  * * */

#include <stdio.h>
#include <stdbool.h>
#include "board.h"


/* * *  F U N C T I O N S * * */

int defineDifficulty();
void playerChooseCellToOpen(int row, int column, Cell board[row][column]);
void checkValidRowAndColumn(int row, int column, int *selectedRow, int *selectedColumn);


#endif