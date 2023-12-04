#include <iostream>
using namespace std;

#pragma once
#include "CheckMate.h"
#include "Printer.h"

void movePiece (string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition){
    string piece = table[originalXposition][originalYposition];
    table[newXposition][newYposition] = piece;
    table[originalXposition][originalYposition] = "--";
    return;
}

bool tryMove (string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition){
    string tempOriginalSpace = table[originalXposition][originalYposition];
    string tempNewSpace = table[newXposition][newYposition];
    bool isValidMove = true;
    movePiece(table, originalXposition, originalYposition, newXposition, newYposition);
    isValidMove = !(checkCheck(table, tempOriginalSpace[0]));
    table[originalXposition][originalYposition] = tempOriginalSpace;
    table[newXposition][newYposition] = tempNewSpace;
    return isValidMove;

}