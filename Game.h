#include <iostream>
using namespace std;

#pragma once
#include "TableSetup.h"
#include "Printer.h"
#include "PossibleMoves.h"

void playTheGame(int mode) {
    bool mate = false;
    cout << endl << mode << endl;
    string table[8][8];
    startingSetup(table);
    while (!mate && mode > 0 && mode <= 2){
        printTable(table);
        printPossiblePawnMoves(checkPossibleWhitePawnMoves(table));
        printTable(table);
        printPossibleKingMoves(checkPossibleWhiteKingMoves(table));
        
        mate = true;
    }
}