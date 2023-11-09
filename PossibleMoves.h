#include <iostream>
using namespace std;

#pragma once
#include "possiblePawnMoves.h"
#include "possibleKingMoves.h"
#include "possibleBishopMoves.h"
#include "possibleRookMoves.h"
#include "possibleKnightMoves.h"
#include "possibleQueenMoves.h"

string possiblePawnMoves(const string table[8][8]) {
    return checkPossibleWhitePawnMoves(table);
}

string possibleKingMoves(const string table[8][8]) {
    return checkPossibleWhiteKingMoves(table);
}