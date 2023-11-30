#include <iostream>
using namespace std;

bool isValidPiece(char characterToCheck){
    return (characterToCheck == 'R' || characterToCheck == 'N' || characterToCheck == 'B' || characterToCheck == 'K' || characterToCheck == 'Q');
}

bool isValidFile(char characterToCheck) {
    return (characterToCheck >= 'a' && characterToCheck <= 'h');
}

bool isValidRank(char CharacterToCheck) {
    return (CharacterToCheck >= 1 && CharacterToCheck <= 8);
}

bool checkInput(string inputString) {

    if (inputString.size() >= 3) {
        if (isValidPiece(inputString[0]) && isValidFile(inputString[1]) && isValidRank(inputString[2])) {
            return true;
        }
    }

    if (inputString.size() >= 2){
        if (isValidFile(inputString[0] && isValidRank(inputString[1]))){
            return true;
        }
    }

    return false;
}