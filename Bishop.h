#include <iostream>
using namespace std;
#pragma once
#include "HelperMethods.h"

string getaLineOfMoves(int rowMovement, int columnMovement, int xPosition, int yPosition ,string table[8][8]){
    string aLine = "";
    int i = xPosition;
    int j = yPosition;
    bool enemyPieceHit = false;
    char color = table[xPosition][yPosition][0];
    char piece = table[xPosition][yPosition][1];

    while (!enemyPieceHit && i + rowMovement < 8 && i + rowMovement >= 0 && j + columnMovement < 8 && j + columnMovement >= 0){
        i += rowMovement;
        j += columnMovement;
        if (table[i][j] == "--") {
            aLine += piece + convertNumberToPosition(i, true) + convertNumberToPosition(j, false) + " ";
        }
        if (table[i][j][0] != color && table[i][j] != "--"){
            aLine += piece;
            aLine += "x" + convertNumberToPosition(i, true) + convertNumberToPosition(j, false) + " ";
            enemyPieceHit = true;
        }
    }
    return aLine;
}

string checkPossibleBishopMoves(string table[8][8], int xPosition, int yPosition){
    string possibleMoves = "";
    char color = table[xPosition][yPosition][0];
    char piece = table[xPosition][yPosition][1];

    if (piece != 'B' && piece != 'Q'){
        return "Hibas fuggvenyhibas!";
    }

    possibleMoves += getaLineOfMoves(1, 1, xPosition, yPosition, table);
    possibleMoves += getaLineOfMoves(1, -1, xPosition, yPosition, table);
    possibleMoves += getaLineOfMoves(-1, 1, xPosition, yPosition, table);
    possibleMoves += getaLineOfMoves(-1, -1, xPosition, yPosition, table);

    return possibleMoves;
}