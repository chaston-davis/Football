#include "football.h"
#include "Quarterback.h"
#include "WideReceiver.h"
#include "TightEnd.h"
#include "RunningBack.h"
#include "Center.h"
#include "Defense.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Welcome to Football++! Designed by Chaston Davis." << std::endl;

    Football football;
    football.setupGame();
    football.coinFlip();

    Quarterback quarterback;
    WideReceiver wideReceiver;
    TightEnd tightEnd;
    RunningBack runningBack;
    Center center;
    Defense defense;

    std::cout << "--- Enter Player Names ---" << std::endl;
    quarterback.promptPlayerName();
    runningBack.promptPlayerName();
    wideReceiver.promptPlayerName();
    tightEnd.promptPlayerName();
    center.promptPlayerName();

    std::cout << "Starting Offensive Lineup:" << std::endl;
    std::cout << "QB: " << quarterback.getFullName() << std::endl;
    std::cout << "RB: " << runningBack.getFullName() << std::endl;
    std::cout << "WR: " << wideReceiver.getFullName() << std::endl;
    std::cout << "TE: " << tightEnd.getFullName() << std::endl;
    std::cout << "C:  " << center.getFullName() << std::endl;

    while (football.isGameOver() == false && std::cin.good()) {
        quarterback.callPlay(&wideReceiver, runningBack, center, defense, football);
    }

    return 0;
}
