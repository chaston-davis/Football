#include "Center.h"
#include <cstdlib>

Center::Center(std::string firstName, std::string lastName) {
    setPlayerName(firstName, lastName);
}

bool Center::snapBall(Offense* qb, bool wet) {
    ballSnapped = true;
    int roll = std::rand() % 100 + 1;

    if (wet == true && roll <= 10) {
        std::cout << "Bad snap from Center " << getLastName() << "! The wet ball slips on the ground and the QB dives on it for a loss!" << std::endl;
        if (qb != nullptr) {
            qb->hasBall = false;
        }
        return false;
    }

    if (qb != nullptr) {
        qb->hasBall = true;
    }
    std::cout << "Center " << getLastName() << " snaps the ball cleanly to the Quarterback." << std::endl;
    return true;
}
