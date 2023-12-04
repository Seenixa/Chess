#include <iostream>
using namespace std;
#pragma once
#include "HelperMethods.h"

/*
    Lehetséges bástya mozdulatokat visszaadó függvény.
    A királynőre is ez a függvény van használva, a futóéval együtt.
    Input: A tábla, és egy bábú pozíciója.
    Return: egy string felsorolva benne szóközzel elválasztva a szabályos lépéseket.
*/

string checkPossibleRookMoves(string table[8][8], int xPosition, int yPosition) {
    string possibleMoves = "";
    char color = table[xPosition][yPosition][0];        //"w" vagy "b" értékeket vehet fel. A függvénybe belépő bábú első karaktere.
    char piece = table[xPosition][yPosition][1];        //"R" vagy "Q" értékeket vehet fel. A függvénybe belépő bábút azonosító karakter.

    // Ha nem bástya vagy királynő hívta a függvényt, lépjen ki.
    if (piece != 'R' && piece != 'Q'){
        return "Hibas fuggvenyhivas!";
    }

    //Jobbra lépések
    for (int i = xPosition; i < 8; i++){
        if (i + 1 < 8 && color != table[i + 1][yPosition][0] && table[i + 1][yPosition] != "--"){
            possibleMoves += piece;
            possibleMoves += "x" + convertNumberToPosition(i + 1, true) + convertNumberToPosition(yPosition, false) + " ";
            break;
        }
        if (i + 1 < 8 && table[i + 1][yPosition] == "--"){
            possibleMoves += piece + convertNumberToPosition(i + 1, true) + convertNumberToPosition(yPosition, false) + " ";
            if (table[i + 1][yPosition][0] == color){
                break;
            }
        }
        
    }

    //balra lépések
    for (int i = xPosition; i >= 0; i--){
        if (i - 1 >= 0 && color != table[i - 1][yPosition][0] && table[i - 1][yPosition] != "--"){
            possibleMoves += piece;
            possibleMoves += "x" + convertNumberToPosition(i - 1, true) + convertNumberToPosition(yPosition, false) + " ";
            break;
        }
        if (i - 1 >= 0 && table[i - 1][yPosition] == "--"){
            possibleMoves += piece + convertNumberToPosition(i - 1, true) + convertNumberToPosition(yPosition, false) + " ";
            if (table[i - 1][yPosition][0] == color){
                break;
            }
        }
    }

    //Felfelé lépések
    for (int i = yPosition; i < 8; i++){
        if (i + 1 < 8 && color != table[xPosition][i + 1][0] && table[xPosition][i + 1] != "--"){
            possibleMoves += piece;
            possibleMoves += "x" + convertNumberToPosition(xPosition, true) + convertNumberToPosition(i + 1, false) + " ";
            break;
        }
        if (i + 1 < 8 && table[xPosition][i + 1] == "--"){
            possibleMoves += piece + convertNumberToPosition(xPosition, true) + convertNumberToPosition(i + 1, false) + " ";
            if (table[xPosition][i + 1][0] == color){
                break;
            }
        }
    }

    //Lefelé lépések.
    for (int i = yPosition; i >= 0; i--){
        if (i - 1 >= 0 && color != table[xPosition][i - 1][0] && table[xPosition][i - 1] != "--"){
            possibleMoves += piece;
            possibleMoves += "x" + convertNumberToPosition(xPosition, true) + convertNumberToPosition(i - 1, false) + " ";
            break;
        }
        if (i - 1 >= 0 && table[xPosition][i - 1] == "--"){
            possibleMoves += piece + convertNumberToPosition(xPosition, true) + convertNumberToPosition(i - 1, false) + " ";
            if (table[xPosition][i - 1][0] == color){
                break;
            }
        }
    }
    
    return possibleMoves;
}
