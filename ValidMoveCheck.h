#include <iostream>
using namespace std;

#pragma once
#include "King.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"



bool isValidPawnMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){
    if (color == 'w'){
        if (newXposition == originalXposition && newYposition == (originalYposition + 1) && table[newXposition][newYposition] == "--"){
            return true;
        }
        if (newXposition == originalXposition && newYposition == (originalYposition + 2) 
            && table[newXposition][newYposition] == "--" && table[originalXposition][originalYposition + 1] == "--"){
            return true;
        }
        if (newXposition == originalXposition + 1 && newYposition == originalYposition + 1 && table[newXposition][newYposition][0] == 'b'){
            return true;
        }
        if (newXposition == originalXposition - 1 && newYposition == originalYposition + 1 && table[newXposition][newYposition][0] == 'b'){
            return true;
        }
    }

    if (color == 'b'){
        if (newXposition == originalXposition && newYposition == (originalYposition - 1) && table[newXposition][newYposition] == "--"){
            return true;
        }
        if (newXposition == originalXposition && newYposition == (originalYposition - 2) 
            && table[newXposition][newYposition] == "--" && table[originalXposition][originalYposition + 1] == "--"){
            return true;
        }
        if (newXposition == originalXposition + 1 && newYposition == originalYposition - 1 && table[newXposition][newYposition][0] == 'w'){
            return true;
        }
        if (newXposition == originalXposition - 1 && newYposition == originalYposition - 1 && table[newXposition][newYposition][0] == 'w'){
            return true;
        }
    }
    return false;
}

bool isValidRookMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){
    if (originalXposition == newXposition || originalYposition == newYposition){
        for (int i = min(originalXposition, newXposition); i < max(originalXposition, newXposition); i++){
            if (table[i][originalYposition] != "--"){
                return false;
            }
        }

        for (int j = min(originalYposition, newYposition); j < max(originalYposition, newYposition); j++){
            if (table[originalXposition][j] != "--"){
                return false;
            }
        }
        
        if (color == table[newXposition][newYposition][0]){
            return false;
        }

        return true;
    }
    return false;
}

bool isValidKnightMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){
    if (originalXposition + 2 == newXposition && originalYposition + 1 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition < 8 && newYposition < 8){
        return true;
    }
    if (originalXposition + 2 == newXposition && originalYposition - 1 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition < 8 && newYposition >= 0){
        return true;
    }
    if (originalXposition - 2 == newXposition && originalYposition + 1 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition >= 0 && newYposition < 8){
        return true;
    }
    if (originalXposition - 2 == newXposition && originalYposition - 1 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition >= 0 && newYposition >= 0){
        return true;
    }
    if (originalXposition + 1 == newXposition && originalYposition + 2 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition < 8 && newYposition < 8){
        return true;
    }
    if (originalXposition + 1 == newXposition && originalYposition - 2 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition < 8 && newYposition >= 0){
        return true;
    }
    if (originalXposition - 1 == newXposition && originalYposition + 2 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition >= 0 && newYposition < 8){
        return true;
    }
    if (originalXposition - 1 == newXposition && originalYposition - 2 == newYposition && table[newXposition][newYposition][0] != color &&
            newXposition >= 0 && newYposition >= 0){
        return true;
    }
    return false;
}

bool isValidBishopMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){

    return false;
}

bool isValidQueenMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){

    return false;
}

bool isValidKingMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){

    return false;
}