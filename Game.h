#include <iostream>
using namespace std;
#pragma once
#include "TableSetup.h"
#include "Printer.h"
#include "Piece.h"
#include "move.h"


void playTheGame(int mode) {
    bool mate = false;
    string table[8][8];
    string possibleMoves[128];
    startingSetup(table);
    while (!mate && mode > 0 && mode <= 2){
        printTable(table);
        movePiece(table, 1, 0, 6, 4);
        movePiece(table, 2, 0, 6, 4);
        movePiece(table, 3, 0, 6, 3);
        printTable(table);

        printPossibleMoves(getPossibleMoves(6,3,table));
        mate = true;
    }
}