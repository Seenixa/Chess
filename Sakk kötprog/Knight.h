#include <iostream>
using namespace std;
#pragma once
#include "HelperMethods.h"

/*
    Az adott pozícióban lévő ló, egy lépését adja vissza.
    input: Tábla, bábú pozíciója, melyik irányba mennyit lép. (2, 1, -2, -1 minden lehetséges kombinációja egy legális lólépés).
    return: A beadott adatok alapján egy lehetséges lólépés.
*/


string getaKnightMove(int rowMovement, int columnMovement, int xPosition, int yPosition, string table[8][8]){
    string aMove = "";
    char color = table[xPosition][yPosition][0];
    char piece = table[xPosition][yPosition][1];

    if (xPosition + rowMovement < 8 && yPosition + columnMovement < 8 && xPosition + rowMovement >= 0 && yPosition + columnMovement >= 0){
        if (table[xPosition + rowMovement][yPosition + columnMovement] == "--"){
            aMove += piece + convertNumberToPosition(xPosition + rowMovement, true) + convertNumberToPosition(yPosition + columnMovement, false) + " ";
        }
        if (table[xPosition + rowMovement][yPosition + columnMovement][0] != color && table[xPosition + rowMovement][yPosition + columnMovement] != "--"){
            aMove += piece;
            aMove += 'x' + convertNumberToPosition(xPosition + rowMovement, true) + convertNumberToPosition(yPosition + columnMovement, false) + " ";
        }
    }
    return aMove;
}

/*
    Lehetséges ló lépéseket visszaadó függvény.
    Input: A tábla, és egy bábú pozíciója.
    Return: egy string felsorolva benne szóközzel elválasztva a szabályos lépéseket.
*/

string checkPossibleKnightMoves(string table[8][8], int xPosition, int yPosition){
    string possibleMoves = "";
    char piece = table[xPosition][yPosition][1];

    if (piece != 'N'){
        return "Hibás függvényhívás";
    }

    possibleMoves += getaKnightMove(2, 1, xPosition, yPosition, table);
    possibleMoves += getaKnightMove(2, -1, xPosition, yPosition, table);
    possibleMoves += getaKnightMove(1, 2, xPosition, yPosition, table);
    possibleMoves += getaKnightMove(1, -2, xPosition, yPosition, table);
    possibleMoves += getaKnightMove(-2, 1, xPosition, yPosition, table);
    possibleMoves += getaKnightMove(-2, -1, xPosition, yPosition, table);
    possibleMoves += getaKnightMove(-1, 2, xPosition, yPosition, table);
    possibleMoves += getaKnightMove(-1, -2, xPosition, yPosition, table);

    return possibleMoves;
}

