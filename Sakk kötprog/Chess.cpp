#include <iostream>
using namespace std;

#include "Game.h"

int main() {
    int mode = 0;
    while(mode < 1 || mode > 3){
        cout << "Main menu!" << endl << "1. Normal game" << endl << "2. Test game" << endl << "3. Quit" << endl;
        cin >> mode;
    }
    playTheGame(mode);
    return 0;
}