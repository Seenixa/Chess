#include <iostream>
using namespace std;

void printTable(string table[8][8]) {
    for(int i=0; i < 8; i++){

        for(int j=0; j < 8; j++){
            cout << "|" << table[j][i];
        }

        cout << "|" << endl;
    }
}

void printPossiblePawnMoves(string pawnMoves) {
    cout << "Possible pawn moves: " << pawnMoves << endl;
}

void printPossibleKingMoves(string kingMoves) {
    cout << "Possible King moves: " << kingMoves << endl;
}