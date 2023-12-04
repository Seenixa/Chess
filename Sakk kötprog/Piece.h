#include <iostream>
#pragma once
using namespace std;

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"

string getPossibleMoves(int xPosition, int yPosition, string table[8][8]){
    if (table[xPosition][yPosition].size() != 2){
        return "Hibas fuggvenyhibas!";
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
            return checkPossibleKnightMoves(table, xPosition, yPosition);
            break;
        case 'B':
            return checkPossibleBishopMoves(table, xPosition, yPosition);
            break;
        case 'Q':
            return checkPossibleRookMoves(table, xPosition, yPosition) + checkPossibleBishopMoves(table, xPosition, yPosition);
            break;
        case 'K':
            return checkPossibleKingMoves(table, xPosition, yPosition);
            break;
        default:
            return "Hibas fuggvenyhibas!";
            break;
    }
}
