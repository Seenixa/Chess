#include <iostream>
using namespace std;
#pragma once
#include "HelperMethods.h"

string getaKingMove(int rowMovement, int columnMovement, int xPosition, int yPosition, string table[8][8]){
    string aMove = "";
    char color = table[xPosition][yPosition][0];
    char piece = table[xPosition][yPosition][1];

    if (checkOutOfBounds(xPosition + rowMovement, yPosition + columnMovement)){
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
    A lehetséges király mozdulatokat visszaadó függvény.
    Input: a tábla, és a bábú pozíciója.
    Return: egy string felsorolva benne szóközzel elválasztva a szabályos lépéseket.
*/

string checkPossibleKingMoves(string table[8][8], int xPosition, int yPosition){
    string possibleMoves = "";
    char piece = table[xPosition][yPosition][1];

    if (piece != 'K'){
        return "Hibás függvényhívás";
    }

    possibleMoves += getaKingMove(-1, 1, xPosition, yPosition, table);  //balra-fel
    possibleMoves += getaKingMove(-1, 0, xPosition, yPosition, table);  //balra
    possibleMoves += getaKingMove(-1, -1, xPosition, yPosition, table); //balra-le
    possibleMoves += getaKingMove(0, 1, xPosition, yPosition, table);   //fel
    possibleMoves += getaKingMove(0, -1, xPosition, yPosition, table);  //le
    possibleMoves += getaKingMove(1, 1, xPosition, yPosition, table);   //jobbra-fel
    possibleMoves += getaKingMove(1, 0, xPosition, yPosition, table);   //jobbra
    possibleMoves += getaKingMove(1, -1, xPosition, yPosition, table);  //jobbra-le
    
    
    
    

    return possibleMoves;
}

