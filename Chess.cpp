#include <iostream>
using namespace std;

#include "Game.h"

int main() {
    int mode = 0;
    cout << "Main menu!" << endl << "1. Normal game" << endl << "2. Test game" << endl;
    cin >> mode;
    playTheGame(mode);
    return 0;
}