#include <iostream>
using namespace std;
#pragma once

#include "ValidMoveCheck.h"

bool isValidPiece(char characterToCheck){
    return (characterToCheck == 'R' || characterToCheck == 'N' || characterToCheck == 'B' || characterToCheck == 'K' || characterToCheck == 'Q');
}

bool isValidFile(char characterToCheck){
    return (characterToCheck >= 'a' && characterToCheck <= 'h');
}

bool isValidRank(char CharacterToCheck){
    return (CharacterToCheck >= 1 && CharacterToCheck <= 8);
}

bool checkInput(string inputString) {

    if (inputString.size() == 3) {
        if (isValidPiece(inputString[0]) && isValidFile(inputString[1]) && isValidRank(inputString[2])) {
            return true;
        }
    }

    if (inputString.size() == 2){
        if (isValidFile(inputString[0] && isValidRank(inputString[1]))){
            return true;
        }
    }

    return false;
}

bool isValidMove(string moveToCheck, string table[8][8], int startingXPosition, int startingYPosition, char color){
    char piece, newRank;
    int newFile;

    if ( !(checkInput(moveToCheck)) ){
        return false;
    }

    if (isValidPiece(moveToCheck[0])){
        piece = moveToCheck[0];
    } else {
        piece = 'P';
    }

    if (piece != 'P' && isValidFile(moveToCheck[1])){
        newFile = moveToCheck[1];
    } else if (piece == 'P' && isValidFile(moveToCheck[0])){
        newFile = moveToCheck[0];
    }

    if (piece != 'P' && isValidRank(moveToCheck[2])){
        newRank = moveToCheck[2];
    } else if (piece == 'P' && isValidRank(moveToCheck[1])){
        newRank = moveToCheck[1];
    }
    
    switch (piece){
        case 'P':
            return isValidPawnMove(table, startingXPosition, startingYPosition, newFile, newRank, color);
            break;
        case 'R':
            return isValidRookMove(table, startingXPosition, startingYPosition, newFile, newRank, color);
            break;
        case 'N':
            return isValidKnightMove(table, startingXPosition, startingYPosition, newFile, newRank, color);
            break;
        case 'B':
            return isValidBishopMove(table, startingXPosition, startingYPosition, newFile, newRank, color);
            break;
        case 'Q':
            return isValidQueenMove(table, startingXPosition, startingYPosition, newFile, newRank, color);
            break;
        case 'K':
            return isValidKingMove(table, startingXPosition, startingYPosition, newFile, newRank, color);
            break;
        default:
            return "Hibas fuggvenyhibas!";
            break;
    } 
}