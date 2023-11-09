#include <iostream>
using namespace std;

#include "TableSetup.h"
#include "Printer.h"
#include "PossibleMoves.h"

void playTheGame() {
    bool mate = false;
    string table[8][8];
    startingSetup(table);
    while (!mate){
        printTable(table);
        printPossiblePawnMoves(checkPossibleWhitePawnMoves(table));
        printTable(table);
        printPossibleKingMoves(checkPossibleWhiteKingMoves(table));
        
        mate = true;
    }
}