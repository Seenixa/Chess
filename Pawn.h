#include <iostream>
using namespace std;
#pragma once
#include "HelperMethods.h"

/* 
    A lehetséges paraszt mozdulatokat visszaadó függvény.
    Input: a tábla, és a bábú pozíciója.
    Return: egy string felsorolva benne szóközzel elválasztva a szabályos lépéseket.
*/

string checkPossiblePawnMoves(string table[8][8], int xPosition, int yPosition) {
    string possibleMoves = "";
    char color = table[xPosition][yPosition][0];
    

    //Fehér paraszt lépések
    if (color == 'w'){
        //Egyet előre lépés
        if (table[xPosition][yPosition + 1] == "--"){
            possibleMoves += convertNumberToPosition(xPosition, true) + convertNumberToPosition(yPosition + 1, false) + " ";
            //Ha a kezdő pozíciójában van kettőt előre lépés.
            if (table[xPosition][yPosition + 2] == "--" && yPosition == 1){
                possibleMoves += convertNumberToPosition(xPosition, true) + convertNumberToPosition(yPosition + 2, false) + " ";
            }
        }

        //Jobbra srégen ütés
        if (table[xPosition + 1][yPosition + 1] != "--" && checkOutOfBounds(xPosition + 1, yPosition + 1)){
            possibleMoves += convertNumberToPosition(xPosition, true) + "x" +  convertNumberToPosition(xPosition + 1, true) + 
                convertNumberToPosition(yPosition + 1, false) + " ";
        }

        //Balra srégen ütés
        if (table[xPosition - 1][yPosition + 1] != "--" && checkOutOfBounds(xPosition - 1, yPosition + 1)){
            possibleMoves += convertNumberToPosition(xPosition, true) + "x" + convertNumberToPosition(xPosition - 1, true) + 
                convertNumberToPosition(yPosition + 1, false) + " ";
        }
    }

    //Fekete paraszt lépések
    if (color == 'b'){

        //Egyet előre lépés
        if (table[xPosition][yPosition - 1] == "--"){
            possibleMoves += convertNumberToPosition(xPosition, true) + convertNumberToPosition(yPosition - 1, false) + " ";
            //Kezdő pozícióról kettőt előrelépés
            if (table[xPosition][yPosition - 2] == "--" && yPosition == 6){
                possibleMoves += convertNumberToPosition(xPosition, true) + convertNumberToPosition(yPosition - 2, false) + " ";
            }
        }

        //Balra srégen ütés
        if (table[xPosition - 1][yPosition - 1] != "--" && checkOutOfBounds(xPosition - 1, yPosition - 1)){
            possibleMoves += convertNumberToPosition(xPosition, true) + "x" +  convertNumberToPosition(xPosition - 1, true) +
                convertNumberToPosition(yPosition - 1, false) + " ";
        }

        //Jobbra srégen ütés
        if (table[xPosition + 1][yPosition - 1] != "--" && checkOutOfBounds(xPosition + 1, yPosition - 1)){
            possibleMoves += convertNumberToPosition(xPosition, true) + "x" + convertNumberToPosition(xPosition + 1, true) + 
                convertNumberToPosition(yPosition - 1, false) + " ";
        }
    }
    return possibleMoves;
}



