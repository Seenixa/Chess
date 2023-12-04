#include <iostream>
using namespace std;
#pragma once
#include "TableSetup.h"
#include "Printer.h"
#include "Piece.h"
#include "move.h"
#include "CheckMate.h"
#include "InputCheck.h"
#include "HelperMethods.h"

void playTheGame(int mode) {
    bool mate = false;
    string table[8][8];
    string possibleMoves[128];
    string pickedUpPiecePosition;
    string spotToMoveTo;
    int moveFromX;
    int moveFromY;
    int moveToX;
    int moveToY;
    int numberOfTries;
    char colorTurn = 'w';

    startingSetup(table);

    while (!mate && mode > 0 && mode <= 2){
        printTable(table);
        cout << "White's turn. Pick up a piece" << endl;
        cin >> pickedUpPiecePosition;
        moveFromX = convertFileToNumber(pickedUpPiecePosition[0]);
        moveFromY = convertRankToNumber(pickedUpPiecePosition[1]);

        while (!checkInput(spotToMoveTo) || table[moveFromX][moveFromY][0] != colorTurn){
            cout << "Wrong input. Try again" << endl;
            printTable(table);
            cin >> pickedUpPiecePosition;
        }

        moveFromX = convertFileToNumber(pickedUpPiecePosition[0]);
        moveFromY = convertRankToNumber(pickedUpPiecePosition[1]);

        cout << "Where do you want to move?";
        cin >> spotToMoveTo;

        while (!checkInput(spotToMoveTo)){
            cout << "Wrong input. Try again" << endl;
            printTable(table);
            cin >> spotToMoveTo;
        }

        moveToX = convertFileToNumber(spotToMoveTo[0]);
        moveToY = convertRankToNumber(spotToMoveTo[1]);

        while (!isValidMove(spotToMoveTo, table, moveToX, moveToY, colorTurn)){
            cout << "The move you entered is invalid. Try again." << endl;
            printTable(table);
            cin >> spotToMoveTo;
            while (!checkInput(spotToMoveTo) || !tryMove(table, moveFromX, moveFromY, moveToX, moveToY)){
                cout << "Wrong input. Try again" << endl;
                printTable(table);
                cin >> spotToMoveTo;
                numberOfTries++;
            }
        }
        mate = checkMate(table, numberOfTries);
        numberOfTries = 0;
        colorTurn = 'b';
    }
}