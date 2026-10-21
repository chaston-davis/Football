#include "WideReceiver.h"

WideReceiver::WideReceiver(std::string firstName, std::string lastName) {
    setPlayerName(firstName, lastName);
}

void WideReceiver::catchBall(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded) {
    this->catchBallLow = catchBallLow;
    this->catchBallChest = catchBallChest;
    this->catchBallHigh = catchBallHigh;
    this->catchBallOneHanded = catchBallOneHanded;

    if (catchBallLow == true) {
        hasBall = true;
        std::cout << "Ball was low, but it was hauled in by " << getLastName() << std::endl;
    }
    if (catchBallChest == true) {
        hasBall = true;
        std::cout << "Routine catch for " << getLastName() << std::endl;
    }
    if (catchBallHigh == true) {
        hasBall = true;
        std::cout << getLastName() << " pulls it down!" << std::endl;
    }
    if (catchBallOneHanded == true) {
        hasBall = true;
        std::cout << "Looking for " << getLastName() << "... Wait, did he catch that? WHAT A CATCH THAT IS UNREAL" << std::endl;
    }
}