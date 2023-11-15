#include <iostream>
#pragma once
using namespace std;

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"




string getPossibleMoves(int xPosition, int yPosition, string table[8][8]){
    if (table[xPosition][yPosition].size() != 2){
        return "Nem letezo babu.";
    }
    char piece = table[xPosition][yPosition][1];

    switch (piece){
        case 'P':
            return checkPossiblePawnMoves(table, xPosition, yPosition);
            break;
        case 'R':
            return checkPossibleRookMoves(table, xPosition, yPosition);
            break;
        case 'N':
            return "Lovag lesz majd.";
            break;
        case 'B':
            return "Futó lesz majd.";
            break;
        case 'Q':
            return "Királynő lesz majd.";
            break;
        case 'K':
            return "Király lesz majd.";
            break;
        default:
            return "Nem letezo babu.";
            break;
    }
}
