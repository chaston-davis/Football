#include "TightEnd.h"

TightEnd::TightEnd(std::string firstName, std::string lastName) {
    setPlayerName(firstName, lastName);
}

void TightEnd::block() {
    std::cout << "Tight End " << getLastName() << " seals the edge with a great block!" << std::endl;
}

void TightEnd::catchBall(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded) {
    hasBall = true;
    if (catchBallChest == true) {
        std::cout << "Tight End " << getLastName() << " boxes out the linebacker for the catch!" << std::endl;
    } else if (catchBallHigh == true) {
        std::cout << "Tight End " << getLastName() << " climbs the ladder and pulls it down!" << std::endl;
    } else if (catchBallLow == true) {
        std::cout << "Tight End " << getLastName() << " scoops it off the turf!" << std::endl;
    } else if (catchBallOneHanded == true) {
        std::cout << "Tight End " << getLastName() << " reels it in with one hand! Unreal catch by the TE!" << std::endl;
    } else {
        std::cout << "Tight End " << getLastName() << " secures the catch!" << std::endl;
    }
}
