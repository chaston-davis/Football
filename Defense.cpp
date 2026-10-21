#include "Defense.h"
#include <cstdlib>

Defense::Defense() {
    shortCoverage = 2;
    mediumCoverage = 2;
    deepCoverage = 3;
    playName = "Cover 2 Zone";
}

void Defense::callDefensivePlay() {
    int playChoice = std::rand() % 4 + 1;

    if (playChoice == 1) {
        playName = "Cover 1 Man";
        shortCoverage = std::rand() % 3 + 1;
        mediumCoverage = std::rand() % 2 + 2;
        deepCoverage = std::rand() % 2 + 2;
    }
    else if (playChoice == 2) {
        playName = "Cover 2 Zone";
        shortCoverage = std::rand() % 2 + 2;
        mediumCoverage = std::rand() % 2 + 1;
        deepCoverage = 3;
    }
    else if (playChoice == 3) {
        playName = "Cover 3 Sky";
        shortCoverage = 1;
        mediumCoverage = std::rand() % 2 + 2;
        deepCoverage = 3;
    }
    else {
        playName = "All-Out Lockdown Blitz";
        shortCoverage = std::rand() % 3 + 1;
        mediumCoverage = std::rand() % 3 + 1;
        deepCoverage = std::rand() % 3 + 1;
    }
}

std::string Defense::getCoverageText(int coverage) {
    if (coverage == 1) {
        return "(Wide Open - No defender near)";
    }
    if (coverage == 2) {
        return "(Defender lurking nearby)";
    }
    return "(Covered - Defender all over route)";
}

bool Defense::swatBall(int coverage) {
    int roll = std::rand() % 100 + 1;

    if (coverage == 1 && roll <= 5) {
        std::cout << "A defender dives at the last second and swats the ball away!" << std::endl;
        return true;
    }
    if (coverage == 2 && roll <= 35) {
        std::cout << "The lurking defender closes in and swats the ball away! Incomplete!" << std::endl;
        return true;
    }
    if (coverage == 3 && roll <= 55) {
        std::cout << "The defender is all over the receiver and swats the pass to the ground!" << std::endl;
        return true;
    }
    return false;
}

bool Defense::intercept(int coverage) {
    int roll = std::rand() % 100 + 1;

    if (coverage == 2 && roll <= 10) {
        std::cout << "INTERCEPTED! The lurking defender jumped the route and picked it off!" << std::endl;
        return true;
    }
    if (coverage == 3 && roll <= 25) {
        std::cout << "INTERCEPTED! Thrown right into tight coverage and the defender catches it!" << std::endl;
        return true;
    }
    return false;
}

bool Defense::causeFumble(bool wet) {
    int roll = std::rand() % 100 + 1;
    int fumbleChance = 5;

    if (wet == true) {
        fumbleChance = 15;
    }

    if (roll <= fumbleChance) {
        std::cout << "FUMBLE! The defender punches the ball out and the defense recovers it!" << std::endl;
        return true;
    }
    return false;
}

bool Defense::tackle() {
    std::cout << "The defender wraps up the ball carrier and makes the tackle." << std::endl;
    return true;
}

void Defense::run() {
    std::cout << "The defense pursues the ball carrier." << std::endl;
}
