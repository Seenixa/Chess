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
        if (newXposition == originalXposition && newYposition == (originalYposition + 1) && table[newXposition][newYposition] == "--" && originalXposition + 1 < 8){
            return true;
        }
        if (newXposition == originalXposition && newYposition == (originalYposition + 2) && originalYposition == 1 
            && table[originalXposition][originalYposition + 1] == "--" && table[originalXposition][originalYposition + 2] == "--"
            && originalYposition + 2 < 8){
            return true;
        }
        if (newXposition == originalXposition + 1 && newYposition == originalYposition + 1 && table[newXposition][newYposition][0] == 'b'
            && originalXposition + 1 < 8 && originalYposition + 1 < 8){
            return true;
        }
        if (newXposition == originalXposition - 1 && newYposition == originalYposition + 1 && table[newXposition][newYposition][0] == 'b'
            && originalXposition - 1 >= 0 && originalYposition + 1 < 8){
            return true;
        }
    }

    if (color == 'b'){
        if (newXposition == originalXposition && newYposition == (originalYposition - 1) 
            && table[newXposition][newYposition] == "--" && originalYposition - 1 >= 0){
            return true;
        }
        if (newXposition == originalXposition && newYposition == (originalYposition - 2) && originalYposition == 6
            && table[newXposition][originalYposition - 1] == "--" && table[originalXposition][originalYposition - 2] == "--"
            && originalYposition - 2 >= 0){
            return true;
        }
        if (newXposition == originalXposition + 1 && newYposition == originalYposition - 1 && table[newXposition][newYposition][0] == 'w'
            && originalXposition + 1 < 8 && originalYposition - 1 >= 0){
            return true;
        }
        if (newXposition == originalXposition - 1 && newYposition == originalYposition - 1 && table[newXposition][newYposition][0] == 'w'
            && originalXposition - 1 >= 0 && originalYposition >= 0){
            return true;
        }
    }
    return false;
}

bool isValidRookMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){
    if (originalXposition == newXposition || originalYposition == newYposition){
        if (table[newXposition][newYposition][0] == color){
            return false;
        }
        for (int i = min(originalXposition, newXposition); i < max(originalXposition, newXposition); i++){
            if (table[i][originalYposition] != "--" && table[i][originalYposition] != table[newXposition][newYposition] ){
                return false;
            }
        }

        for (int j = min(originalYposition, newYposition); j < max(originalYposition, newYposition); j++){
            if (table[originalXposition][j] != "--" && table[originalXposition][j] != table[newXposition][newYposition]){
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
    int checkingXPosition = originalXposition;
    int checkingYPosition = originalYposition;

    if (table[newXposition][newYposition][0] == color){
        return false;
    }

    while(checkingXPosition < 7 && checkingYPosition < 7){
        checkingXPosition++;
        checkingYPosition++;
        if (table[checkingXPosition][checkingYPosition] != "--" && table[checkingXPosition][checkingYPosition] != table[newXposition][newYposition]){
            break;
        }
        if (table[checkingXPosition][checkingYPosition] == table[newXposition][newYposition]){
            return true;
        }
    }

    checkingXPosition = originalXposition;
    checkingYPosition = originalYposition;

    while(checkingXPosition < 7 && checkingYPosition > 0){
        checkingXPosition++;
        checkingYPosition--;
        if (table[checkingXPosition][checkingYPosition] != "--" && table[checkingXPosition][checkingYPosition] != table[newXposition][newYposition]){
            break;
        }
        if (table[checkingXPosition][checkingYPosition] == table[newXposition][newYposition]){
            return true;
        }
    }

    checkingXPosition = originalXposition;
    checkingYPosition = originalYposition;

    while(checkingXPosition > 0 && checkingYPosition < 7){
        checkingXPosition--;
        checkingYPosition++;
        if (table[checkingXPosition][checkingYPosition] != "--" && table[checkingXPosition][checkingYPosition] != table[newXposition][newYposition]){
            break;
        }
        if (table[checkingXPosition][checkingYPosition] == table[newXposition][newYposition]){
            return true;
        }
    }

    checkingXPosition = originalXposition;
    checkingYPosition = originalYposition;

    while(checkingXPosition > 0 && checkingYPosition > 0){
        checkingXPosition--;
        checkingYPosition--;
        if (table[checkingXPosition][checkingYPosition] != "--" && table[checkingXPosition][checkingYPosition] != table[newXposition][newYposition]){
            break;
        }
        if (table[checkingXPosition][checkingYPosition] == table[newXposition][newYposition]){
            return true;
        }
    }

    checkingXPosition = originalXposition;
    checkingYPosition = originalYposition;

    return false;
}

bool isValidQueenMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){
    return isValidBishopMove(table, originalXposition, originalYposition, newXposition, newYposition, color) 
            || isValidRookMove(table, originalXposition, originalYposition, newXposition, newYposition, color);
}

bool isValidKingMove(string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition, char color){

    if (originalXposition + 1 == newXposition && originalYposition + 1 == newYposition && originalXposition + 1 < 8 && originalYposition + 1 < 8
        && table[newXposition][newYposition][0] != color){
        return true;
    }

    if (originalXposition + 1 == newXposition && originalYposition == newYposition && originalXposition + 1 < 8 && table[newXposition][newYposition][0] != color){
        return true;
    }

    if (originalXposition + 1 == newXposition && originalYposition - 1 == newYposition && originalXposition + 1 < 8 && originalYposition - 1 >= 0
        && table[newXposition][newYposition][0] != color){
        return true;
    }

    if (originalXposition == newXposition && originalYposition + 1 == newYposition && originalYposition + 1 < 8 && table[newXposition][newYposition][0] != color){
        return true;
    }

    if (originalXposition == newXposition && originalYposition - 1 == newYposition && originalYposition - 1 >= 0 && table[newXposition][newYposition][0] != color){
        return true;
    }

    if (originalXposition - 1 == newXposition && originalYposition + 1 == newYposition && originalXposition - 1 >= 0 && originalYposition + 1 < 8
        && table[newXposition][newYposition][0] != color){
        return true;
    }

    if (originalXposition - 1 == newXposition && originalYposition == newYposition && originalXposition - 1 >= 0 && table[newXposition][newYposition][0] != color){
        return true;
    }

    if (originalXposition - 1 == newXposition && originalYposition - 1 == newYposition && originalXposition - 1 >= 0 && originalYposition - 1 >= 0 
        && table[newXposition][newYposition][0] != color){
        return true;
    }

    return false;
}