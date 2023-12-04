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
    bool repick = false;
    bool pieceMoved;
    int logId = 1;
    string log = "";
    string table[8][8];
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
        pieceMoved = false;
        printTable(table);
        if (colorTurn == 'w'){
            cout << "White's turn. Pick up a piece!" << endl;
        }
        if (colorTurn == 'b'){
            cout << "Black's turn. Pick up a piece!" << endl;
        }
        if (checkCheck(table, colorTurn)){
            cout << "Check!" << endl;
        }
        
        cin >> pickedUpPiecePosition;
        
        moveFromX = convertFileToNumber(pickedUpPiecePosition[0]);
        moveFromY = convertRankToNumber(pickedUpPiecePosition[1]);
        if (mode == 2){
            printPossibleMoves(getPossibleMoves(moveFromX, moveFromY, table));
        }

        while(!checkInput(spotToMoveTo) || !pieceMoved){
            
            while (!checkInput(pickedUpPiecePosition) || table[moveFromX][moveFromY][0] != colorTurn || repick){
                repick = false;
                cout << "Pick up a piece!" << endl;
                printTable(table);
                cin >> pickedUpPiecePosition;
                moveFromX = convertFileToNumber(pickedUpPiecePosition[0]);
                moveFromY = convertRankToNumber(pickedUpPiecePosition[1]);
                if (mode == 2){
                    printPossibleMoves(getPossibleMoves(moveFromX, moveFromY, table));
                }              
            }


            cout << "Where do you want to move?" << endl;
            cin >> spotToMoveTo;
            if (spotToMoveTo == "repick"){
                    repick = true;
                    continue;;
            }


            while (!checkInput(spotToMoveTo) && !repick){
                cout << "Wrong input. Where do you want to move?" << endl;
                printTable(table);
                cin >> spotToMoveTo;
                moveToX = convertFileToNumber(spotToMoveTo[0]);
                moveToY = convertRankToNumber(spotToMoveTo[1]);
                if (spotToMoveTo == "repick"){
                    repick = true;
                    break;
                }
            }

            if (repick){
                continue;
            }

            moveToX = convertFileToNumber(spotToMoveTo[0]);
            moveToY = convertRankToNumber(spotToMoveTo[1]);
            
            while (!isValidMove(spotToMoveTo, table, moveFromX, moveFromY, colorTurn) && !repick) {
                cout << "Invalid move. Where do you want to move?" << endl;
                printTable(table);
                cin >> spotToMoveTo;
                moveToX = convertFileToNumber(spotToMoveTo[0]);
                moveToY = convertRankToNumber(spotToMoveTo[1]);
                if (spotToMoveTo == "repick"){
                    repick = true;
                    break;
                }
            }
            
            if (repick){
                continue;
            }

            moveToX = convertFileToNumber(spotToMoveTo[0]);
            moveToY = convertRankToNumber(spotToMoveTo[1]);

            while(!tryMove(table, moveFromX, moveFromY, moveToX, moveToY) && !repick){
                cout << "Check!" << endl;
                printTable(table);
                cin >> spotToMoveTo;
                moveToX = convertFileToNumber(spotToMoveTo[0]);
                moveToY = convertRankToNumber(spotToMoveTo[1]);
                numberOfTries++;
                if(checkMate(table, numberOfTries, colorTurn)){
                    cout << "Mate!";
                    mate = true;
                    if (colorTurn == 'w'){
                        cout << endl << "Black has won!" << endl;
                    }
                    if (colorTurn == 'b'){
                        cout << endl << "White has won!" << endl;
                    }
                    break;
                }
                if (spotToMoveTo == "repick"){
                    repick = true;
                    break;
                }
            }
            
            if (repick){
                continue;
            }
            
            pieceMoved = true;
            movePiece(table, moveFromX, moveFromY, moveToX, moveToY);
            if (colorTurn == 'w'){
                log += to_string(logId) + ",  ";
                if (table[moveToX][moveToY][1] != 'P'){
                    log += table[moveToX][moveToY][1];
                }
                log += spotToMoveTo + "   ";
            }
            if (colorTurn == 'b'){
                if (table[moveToX][moveToY][1] != 'P'){
                    log += table[moveToX][moveToY][1];
                }
                log += spotToMoveTo + "\n";
                logId++;
            }
            
        }

        numberOfTries = 0;
        if (colorTurn == 'w'){
            colorTurn = 'b';
        } else if (colorTurn == 'b'){
            colorTurn = 'w';
        }
        pickedUpPiecePosition = "";
        spotToMoveTo = "";
   }
   cout << endl << endl <<log;
   return;
}