#include <iostream>
using namespace std;

    /*  
    A tábla kezdőpozícióba állítása. A tábla egy 8*8-as két dimenziós array.
    Első értéke az oszlop. (0->a, 1-b, 2-c, 3-d, 4-e, 5-f 6-g 7-h)
    Második értéke a sor.
    A második sorba wP(white pawn) kerül a hetedikbe pedig bP(black pawn).
    Az első sorba wR-wN-wB-wQ-wK-wB-wN-wR (white Rook, kNight, Bishop, Queen, King Bishop, kNight, Rook)
    A nyolcadik sorba bR-bN-bB-bQ-bK-bB-bN-bR (black Rook, kNight, Bishop, Queen, King Bishop, kNight, Rook)
    A tábla maradék részét "--" -el töltöm fel.
    */

void startingSetup(string table[8][8]) {
    for (int i = 2; i < 6; i++) {          // A tábla üres részei.
        for (int j = 0; j < 8; j++ ) {
            table[j][i] = "--";
        }
    }

    for (int j = 0; j < 8; j++) {           // Fehér parasztok
        table[j][1] = "wP";
    }

    for (int j = 0; j < 8; j++) {           // Fekete parasztok
        table[j][6] = "bP";
    }

    table[0][0] = table[7][0] = "wR";       //Fehér Bástyák
    table[1][0] = table[6][0] = "wN";       //Fehér Lovak
    table[2][0] = table[5][0] = "wB";       //Fehér Futók
    table[3][0] = "wQ";                     //Fehér Királynő
    table[4][0] = "wK";                     //Fehér Király

    table[0][7] = table[7][7] = "bR";       //Fekete Bástyák
    table[1][7] = table[6][7] = "bN";       //Fekete Lovak
    table[2][7] = table[5][7] = "bB";       //Fekete Futók
    table[3][7] = "bK";                     //Fekete Király
    table[4][7] = "bQ";                     //Fekete Királynő
}