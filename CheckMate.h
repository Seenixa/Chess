#include <iostream>
using namespace std;


bool checkCheck(const string table[8][8], char color) {
    int kingXPosition;
    int kingYPosition;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (table[i][j] == "wK" && color == 'w'){
                kingXPosition = i;
                kingYPosition = j;
            }
            if (table[i][j] == "bK" && color == 'b'){
                kingXPosition = i;
                kingYPosition = j;
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