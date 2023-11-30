#include <iostream>

#pragma once
using namespace std;

#include "Piece.h"


bool checkCheck(const string table[8][8], char color) {
    int kingXPosition;
    int kingYPosition;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (table[i][j] == "wK" && color == 'w'){
                kingXPosition = i;
                kingYPosition = j;
                break;
            }
            if (table[i][j] == "bK" && color == 'b'){
                kingXPosition = i;
                kingYPosition = j;
                break;
            }           
        }
    }
    return false;
}

bool checkMate(const string table[8][8]) {
    if (checkCheck) {
        
    }
    return false;
}