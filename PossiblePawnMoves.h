#include <iostream>
using namespace std;
#pragma once
#include "HelperMethods.h"

string checkPossibleWhitePawnMoves(const string table[8][8]) {
    string possiblePawnMoves;
    for(int i = 0; i < 8; i++) {
        for( int j= 0; j < 8; j++) {
            if (table[i][j] == "wP"){
                if (table[i][j+1] == "--" && checkOutOfBounds(j + 1)) {
                    possiblePawnMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i][j+2] == "--" && checkOutOfBounds(j + 2)) {
                    possiblePawnMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j + 2, false) + " ";
                }
            }
        }
    }
    return possiblePawnMoves;
}

string checkPossibleBlackPawnMoves(const string table[8][8]) {
    string possiblePawnMoves;
    for(int i = 0; i < 8; i++) {
        for( int j= 0; j < 8; j++) {
            if (table[i][j] == "wP"){
                if (table[i][j+1] == "--" && checkOutOfBounds(j + 1)) {
                    possiblePawnMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i][j+2] == "--" && checkOutOfBounds(j + 2)) {
                    possiblePawnMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j + 2, false) + " ";
                }
            }
        }
    }
    return possiblePawnMoves;
}