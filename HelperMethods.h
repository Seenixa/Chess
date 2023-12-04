#include <iostream>
using namespace std;
#pragma once

bool checkOutOfBounds(int xPosition, int yPosition) {
    return 0 <= xPosition && xPosition < 8 && 0 <= yPosition && yPosition < 8;
}

int convertRankToNumber(char rank){
    switch (rank){
        case '1':
            return 0;
            break;
        case '2':
            return 1;
            break;
        case '3':
            return 2;
            break;
        case '4':
            return 3;
            break;
        case '5':
            return 4;
            break;
        case '6':
            return 5;
            break;
        case '7':
            return 6;
            break;
        case '8':
            return 7;
            break;
        default:
            break;
    }

    return -1;
}

int convertFileToNumber(char file){
    switch (file){
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 3;
            break;
        case 'e':
            return 4;
            break;
        case 'f':
            return 5;
            break;
        case 'g':
            return 6;
            break;
        case 'h':
            return 7;
            break;
        default:
            break;
    }

    return -1;
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
