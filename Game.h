#include <iostream>
using namespace std;
#pragma once
#include "TableSetup.h"
#include "Printer.h"
#include "Piece.h"


void playTheGame(int mode) {
    bool mate = false;
    string table[8][8];
    startingSetup(table);
    while (!mate && mode > 0 && mode <= 2){
        printTable(table);
        cout << table[1][6] << " " << getPossibleMoves(1,6, table) << endl;
        cout << table[1][1] << " " <<  getPossibleMoves(1,1, table) << endl;
        mate = true;
    }
}