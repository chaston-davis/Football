#include "RunningBack.h"
#include <cstdlib>

RunningBack::RunningBack(std::string firstName, std::string lastName) {
    setPlayerName(firstName, lastName);
}

bool RunningBack::breakTackle() {
    int roll = std::rand() % 100 + 1;
    if (roll <= 30) {
        std::cout << getLastName() << " breaks a tackle and keeps his legs churning!" << std::endl;
        return true;
    }
    return false;
}

void RunningBack::catchBall(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded) {
    hasBall = true;
    if (catchBallChest == true) {
        std::cout << "Running Back " << getLastName() << " catches the checkdown pass in stride!" << std::endl;
    } else if (catchBallLow == true) {
        std::cout << "Running Back " << getLastName() << " reaches down and snags the low pass!" << std::endl;
    } else if (catchBallHigh == true) {
        std::cout << "Running Back " << getLastName() << " jumps to corral the high throw!" << std::endl;
    } else if (catchBallOneHanded == true) {
        std::cout << "Running Back " << getLastName() << " makes an incredible one-handed grab on the screen!" << std::endl;
    } else {
        std::cout << "Running Back " << getLastName() << " secures the reception out of the backfield!" << std::endl;
    }
}

