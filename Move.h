#include <iostream>
using namespace std;

void movePiece (string table[8][8], int originalXposition, int originalYposition, int newXposition, int newYposition){
    string piece = table[originalXposition][originalYposition];
    table[newXposition][newYposition] = piece;
    table[originalXposition][originalYposition] = "--";
    return;
}