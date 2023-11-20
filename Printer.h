#include <iostream>
using namespace std;

void printTable(string table[8][8]) {
    cout << "    A    B    C    D    E    F    G    H" << endl << endl;
    for(int i=7; i >= 0; i--){
        cout << i + 1 << " ";
        for(int j=0; j < 8; j++ ){
            cout << "| " << table[j][i] << " ";
        }

        cout << "| " << i + 1 << endl << endl;

    if (i == 0){
        cout << "    A    B    C    D    E    F    G    H" << endl;
    }
    }
}

void printPossibleMoves(string moves){
    cout << "Possible moves of this piece: " << moves << endl;
}