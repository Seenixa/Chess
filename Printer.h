#include <iostream>
using namespace std;

void printTable(string table[8][8]) {
    for(int i=7; i >= 0; i--){
        cout << i + 1 << " ";
        for(int j=0; j < 8; j++ ){
            cout << "|" << table[j][i];
        }

        cout << "|  " << endl;

    if (i == 0){
        cout << "   A  B  C  D  E  F  G  H" << endl;
    }
    }
}

void printPossiblePawnMoves(string pawnMoves) {
    cout << "Possible pawn moves: " << pawnMoves << endl;
}

void printPossibleKingMoves(string kingMoves) {
    cout << "Possible King moves: " << kingMoves << endl;
}