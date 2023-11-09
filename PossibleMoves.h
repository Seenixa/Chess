#include <iostream>
using namespace std;

bool checkOutOfBounds(int position) {
    return 0 < position && position < 8;
}

string convertNumberToPosition(int number, bool isRow){
    if (isRow){
        switch (number)
        {
        case 0:
            return "a";
            break;

        case 1:
            return "b";
            break;    
        
        case 2:
            return "c";
            break;

        case 3:
            return "d";
            break;

        case 4:
            return "e";
            break;

        case 5:
            return "f";
            break;

        case 6:
            return "g";
            break;

        case 7:
            return "h";
            break;

        default:
            break;
        }
    }
    return to_string(number + 1);
  }


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

string checkPossibleWhiteKingMoves(const string table[8][8]) {
    string possibleKingMoves;
    for(int i = 0; i < 8; i++) {
        for( int j= 0; j < 8; j++) {
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

