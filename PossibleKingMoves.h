#include <iostream>
using namespace std;
#pragma once
#include "HelperMethods.h"

string checkPossibleWhiteKingMoves(const string table[8][8]) {
    string possibleKingMoves;
    for(int i = 0; i < 8; i++) {
        for( int j = 0; j < 8; j++) {
            if (table[i][j] == "wK"){
                if (table[i][j+1] == "--" && checkOutOfBounds(j + 1)) {
                    possibleKingMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i][j-1] == "--" && checkOutOfBounds(j - 1)) {
                    possibleKingMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j - 1, false) + " ";
                }
                if (table[i+1][j+1] == "--" && checkOutOfBounds(j + 1) && checkOutOfBounds(i + 1) ) {
                    possibleKingMoves += convertNumberToPosition(i + 1, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i+1][j-1] == "--" && checkOutOfBounds(j - 1) && checkOutOfBounds(i + 1)) {
                    possibleKingMoves += convertNumberToPosition(i + 1, true) + convertNumberToPosition(j - 1, false) + " ";
                }
                if (table[i+1][j] == "--" && checkOutOfBounds(i + 1)) {
                    possibleKingMoves += convertNumberToPosition(i + 1, true) + convertNumberToPosition(j, false) + " ";
                }
                if (table[i-1][j] == "--" && checkOutOfBounds(i - 1)) {
                    possibleKingMoves += convertNumberToPosition(i - 1, true) + convertNumberToPosition(j, false) + " ";
                }
                if (table[i-1][j+1] == "--" && checkOutOfBounds(j + 1) && checkOutOfBounds(i - 1)) {
                    possibleKingMoves += convertNumberToPosition(i - 1, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i-1][j-1] == "--" && checkOutOfBounds(j - 1) && checkOutOfBounds(i - 1)) {
                    possibleKingMoves += convertNumberToPosition(i - 1, true) + convertNumberToPosition(j - 1, false) + " ";
                }
            }
        }
    }
    return possibleKingMoves;
}

string checkPossibleBlackKingMoves(const string table[8][8]) {
    string possibleKingMoves;
    for(int i = 0; i < 8; i++) {
        for( int j = 0; j < 8; j++) {
            if (table[i][j] == "bK"){
                if (table[i][j+1] == "--" && checkOutOfBounds(j + 1)) {
                    possibleKingMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i][j-1] == "--" && checkOutOfBounds(j - 1)) {
                    possibleKingMoves += convertNumberToPosition(i, true) + convertNumberToPosition(j - 1, false) + " ";
                }
                if (table[i+1][j+1] == "--" && checkOutOfBounds(j + 1) && checkOutOfBounds(i + 1) ) {
                    possibleKingMoves += convertNumberToPosition(i + 1, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i+1][j-1] == "--" && checkOutOfBounds(j - 1) && checkOutOfBounds(i + 1)) {
                    possibleKingMoves += convertNumberToPosition(i + 1, true) + convertNumberToPosition(j - 1, false) + " ";
                }
                if (table[i+1][j] == "--" && checkOutOfBounds(i + 1)) {
                    possibleKingMoves += convertNumberToPosition(i + 1, true) + convertNumberToPosition(j, false) + " ";
                }
                if (table[i-1][j] == "--" && checkOutOfBounds(i - 1)) {
                    possibleKingMoves += convertNumberToPosition(i - 1, true) + convertNumberToPosition(j, false) + " ";
                }
                if (table[i-1][j+1] == "--" && checkOutOfBounds(j + 1) && checkOutOfBounds(i - 1)) {
                    possibleKingMoves += convertNumberToPosition(i - 1, true) + convertNumberToPosition(j + 1, false) + " ";
                }
                if (table[i-1][j-1] == "--" && checkOutOfBounds(j - 1) && checkOutOfBounds(i - 1)) {
                    possibleKingMoves += convertNumberToPosition(i - 1, true) + convertNumberToPosition(j - 1, false) + " ";
                }
            }
        }
    }
    return possibleKingMoves;
}