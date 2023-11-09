#include <iostream>
using namespace std;
#pragma once

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