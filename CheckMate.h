#include <iostream>

#pragma once
using namespace std;

#include "Piece.h"


bool isAttackedByRookOrQueen(const string table[8][8], int xPosition, int yPosition, char color){
    string opposingRook = "bR";
    string opposingQueen = "bQ";

    if (color == 'b'){
        opposingRook = "wR";
        opposingQueen = "wQ";
    }

    for (int i = 0; i < 8; i++){

        if (table[xPosition][i] == opposingRook || table[xPosition][i] == opposingQueen){
            for (int j = min(i, yPosition); j <= max(i, yPosition); j++){
                if (j == max(i, yPosition)){
                    return true;
                }
                if (table[xPosition][j] != "--" && table[xPosition][j] != opposingRook && 
                    table[xPosition][j] != table[xPosition][yPosition] && table[j][yPosition] != opposingQueen) {
                    break;
                } 
            }    
        }

        if (table[i][yPosition] == opposingRook || table[xPosition][i] == opposingRook){
            for (int j = min(i, xPosition); j <= max(i, xPosition); j++){
                if (j == max(i, xPosition)){
                    return true;
                }
                if (table[j][yPosition] != "--" && table[j][yPosition] != opposingRook && 
                    table[j][yPosition] != table[xPosition][yPosition] && table[j][yPosition] != opposingQueen) {
                    break;
                } 
            }
        }
    }

    return false;
}

bool isAttackedByBishopOrQueen(const string table[8][8], int xPosition, int yPosition, char color){
    string opposingBishop = "bB";
    string opposingQueen = "bQ";
    int checkingXPosition = xPosition;
    int checkingYPosition = yPosition;

    if (color == 'b'){
        opposingBishop = "wB";
        opposingQueen = "bQ";
    }

    while(xPosition < 8 && yPosition < 8 && xPosition){
        checkingXPosition++;
        checkingYPosition++;
        if (table[checkingXPosition][checkingYPosition] == opposingBishop || table[checkingXPosition][checkingYPosition] == opposingQueen){
            return true;
        }
        if (table[checkingXPosition][checkingYPosition] != "--"){
            break;
        }
    }
    checkingXPosition = xPosition;
    checkingYPosition = yPosition;

    while(xPosition >= 0 && yPosition < 8){
        checkingXPosition--;
        checkingYPosition++;
        if (table[checkingXPosition][checkingYPosition] == opposingBishop || table[checkingXPosition][checkingYPosition] == opposingQueen){
            return true;
        }
        if (table[checkingXPosition][checkingYPosition] != "--"){
            break;
        }
    }

    checkingXPosition = xPosition;
    checkingYPosition = yPosition;

    while(xPosition < 8 && yPosition >= 0){
        checkingXPosition++;
        checkingYPosition--;
        if (table[checkingXPosition][checkingYPosition] == opposingBishop || table[checkingXPosition][checkingYPosition] == opposingQueen){
            return true;
        }
        if (table[checkingXPosition][checkingYPosition] != "--"){
            break;
        }
    }

    checkingXPosition = xPosition;
    checkingYPosition = yPosition;

    while(xPosition >= 0 && yPosition >= 0){
        checkingXPosition--;
        checkingYPosition--;
        if (table[checkingXPosition][checkingYPosition] == opposingBishop || table[checkingXPosition][checkingYPosition] == opposingQueen){
            return true;
        }
        if (table[checkingXPosition][checkingYPosition] != "--"){
            break;
        }
    }

    checkingXPosition = xPosition;
    checkingYPosition = yPosition;

    return false;
}

bool isAttackedByPawn(const string table[8][8], int xPosition, int yPosition, char color){
    string opposingPawn = "bP";
    if (color = 'b'){
        opposingPawn = "wP";
    }

    if (color = 'w'){
        if ( (table[xPosition + 1][yPosition + 1] == "bP") && (table[xPosition - 1][yPosition + 1] == "bP")){
            return true;
        }
    }

    if (color = 'b'){
        if ( (table[xPosition - 1][yPosition - 1] == "bP") && (table[xPosition + 1][yPosition - 1] == "bP")){
            return true;
        }
    }

    return false;
}

bool isAttackedByKing(const string table[8][8], int xPosition, int yPosition, char color){
    string opposingKing = "bK";
    if (color = 'b'){
        opposingKing = "wK";
    }

    if (table[xPosition + 1][yPosition + 1] == opposingKing){
        return true;
    }
    if (table[xPosition + 1][yPosition] == opposingKing){
        return true;
    }
    if (table[xPosition + 1][yPosition - 1] == opposingKing){
        return true;
    }
    if (table[xPosition][yPosition + 1] == opposingKing){
        return true;
    }
    if (table[xPosition][yPosition - 1] == opposingKing){
        return true;
    }
    if (table[xPosition - 1][yPosition + 1] == opposingKing){
        return true;
    }
    if (table[xPosition - 1][yPosition] == opposingKing){
        return true;
    }
    if (table[xPosition - 1][yPosition - 1] == opposingKing){
        return true;
    } 

    return false;
}

bool isAttackedByKnight(const string table[8][8], int xPosition, int yPosition, char color){
    string opposingKnight = "bN";
    if (color = 'b'){
        opposingKnight = "wN";
    }

    if (table[xPosition + 2][yPosition + 1] == opposingKnight){
        return true;
    }
    if (table[xPosition + 2][yPosition - 1] == opposingKnight){
        return true;
    }
    if (table[xPosition - 2][yPosition + 1] == opposingKnight){
        return true;
    }
    if (table[xPosition - 2][yPosition - 1] == opposingKnight){
        return true;
    }
    if (table[xPosition + 1][yPosition + 2] == opposingKnight){
        return true;
    }
    if (table[xPosition + 1][yPosition - 2] == opposingKnight){
        return true;
    }
    if (table[xPosition - 1][yPosition + 2] == opposingKnight){
        return true;
    }
    if (table[xPosition - 1][yPosition - 2] == opposingKnight){
        return true;
    }

    return false;
}

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
    if(isAttackedByBishopOrQueen(table, kingXPosition, kingYPosition, color)){
        return true;   
    }
    if(isAttackedByRookOrQueen(table, kingXPosition, kingYPosition, color)){
        return true;   
    }
    if(isAttackedByKnight(table, kingXPosition, kingYPosition, color)){
        return true;   
    }
    if(isAttackedByPawn(table, kingXPosition, kingYPosition, color)){
        return true;   
    }
    if(isAttackedByKing(table, kingXPosition, kingYPosition, color)){
        return true;   
    }
    return false;
}

bool checkMate(const string table[8][8], int numberOfTries) {
    if (checkCheck && numberOfTries > 3) {
        return true;
    }
    return false;
}