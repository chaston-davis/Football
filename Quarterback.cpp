#include "Quarterback.h"
#include <cstdlib>

Quarterback::Quarterback(std::string firstName, std::string lastName) {
    setPlayerName(firstName, lastName);
    hasBall = true;
}

void Quarterback::throwBallPower(Offense* target, bool ballThrownShort, bool ballThrownMedium, bool ballThrownLong) {
    target_ = target;
    this->ballThrownShort = ballThrownShort;
    this->ballThrownMedium = ballThrownMedium;
    this->ballThrownLong = ballThrownLong;

    if (target == nullptr) {
        std::cout << getLastName() << " throws it away out of bounds!" << std::endl;
        std::cout << getLastName() << " searching for anybody open, but he's just going to have to throw that out of bounds" << std::endl;
        std::cout << getLastName() << " 's ball flies straight out of bounds" << std::endl;
        return;
    }

    if (ballThrownShort == true) {
        std::cout << getLastName() << "'s dumping it off." << std::endl;
    }
    if (ballThrownMedium == true) {
        std::cout << getLastName() << "'s ripping it over the middle!!" << std::endl;
    }
    if (ballThrownLong == true) {
        std::cout << getLastName() << "'s entering in the launch codes! LOOKING LONG!" << std::endl;
    }
}

void Quarterback::passToReceiver(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded) {
    if (target_ == nullptr) {
        std::cout << "Incomplete pass!" << std::endl;
        return;
    }

    hasBall = false;
    target_->catchBall(catchBallLow, catchBallChest, catchBallHigh, catchBallOneHanded);
}

int Quarterback::calculatePassYards() {
    if (target_ == nullptr || target_->hasBall == false) {
        return 0;
    }

    int roll = std::rand() % 100 + 1;
    int yards = 0;

    if (ballThrownShort == true) {
        if (roll <= 15) {
            yards = -(std::rand() % 4 + 1); // -1 to -4 yards
        } else if (roll <= 75) {
            yards = std::rand() % 6;        // 0 to 5 yards
        } else if (roll <= 90) {
            yards = std::rand() % 10 + 6;   // 6 to 15 yards
        } else if (roll <= 98) {
            yards = std::rand() % 25 + 16;  // 16 to 40 yards
        } else {
            yards = std::rand() % 60 + 41;  // 41 to 100 yards
        }
    }
    else if (ballThrownMedium == true) {
        if (roll <= 5) {
            yards = std::rand() % 5;        // 0 to 4 yards
        } else if (roll <= 60) {
            yards = std::rand() % 11 + 5;   // 5 to 15 yards
        } else if (roll <= 85) {
            yards = std::rand() % 15 + 16;  // 16 to 30 yards
        } else if (roll <= 95) {
            yards = std::rand() % 30 + 31;  // 31 to 60 yards
        } else {
            yards = std::rand() % 40 + 61;  // 61 to 100 yards
        }
    }
    else if (ballThrownLong == true) {
        if (roll <= 10) {
            yards = std::rand() % 10 + 10;  // 10 to 19 yards
        } else if (roll <= 60) {
            yards = std::rand() % 21 + 20;  // 20 to 40 yards
        } else if (roll <= 85) {
            yards = std::rand() % 30 + 41;  // 41 to 70 yards
        } else {
            yards = std::rand() % 30 + 71;  // 71 to 100 yards
        }
    }

    if (yards < 0) {
        std::cout << "Tackled behind the line for a loss of " << -yards << " yards!" << std::endl;
    } else if (yards == 0) {
        std::cout << "Tackled right away for 0 yards." << std::endl;
    } else if (yards <= 15) {
        std::cout << "Gain of " << yards << " yards on the play." << std::endl;
    } else if (yards <= 40) {
        std::cout << "Big play! Pickup of " << yards << " yards!" << std::endl;
    } else {
        std::cout << "HUGE BREAKAWAY! Goes for " << yards << " yards!!" << std::endl;
    }

    return yards;
}

void Quarterback::passPlay(Offense* target, Defense& defense, Football& football) {
    int randomPlay = std::rand() % 3 + 1;
    if (randomPlay == 1) {
        std::cout << "Play Called: Mesh Concept" << std::endl;
    } else if (randomPlay == 2) {
        std::cout << "Play Called: Four Verticals" << std::endl;
    } else {
        std::cout << "Play Called: Flood Concept" << std::endl;
    }

    std::cout << "Choose a route to throw to:" << std::endl;
    std::cout << "1. Short Drag Route " << defense.getCoverageText(defense.shortCoverage) << std::endl;
    std::cout << "2. Medium Dig Route " << defense.getCoverageText(defense.mediumCoverage) << std::endl;
    std::cout << "3. Deep Streak Route " << defense.getCoverageText(defense.deepCoverage) << std::endl;
    std::cout << "4. Throw Ball Away" << std::endl;
    std::cout << "Choice: ";

    int routeChoice = 1;
    std::cin >> routeChoice;

    std::cout << "Defense was in: " << defense.playName << std::endl;

    int chosenCoverage = 1;
    if (routeChoice == 1) {
        chosenCoverage = defense.shortCoverage;
        throwBallPower(target, true, false, false);
    } else if (routeChoice == 2) {
        chosenCoverage = defense.mediumCoverage;
        throwBallPower(target, false, true, false);
    } else if (routeChoice == 3) {
        chosenCoverage = defense.deepCoverage;
        throwBallPower(target, false, false, true);
    } else {
        throwBallPower(nullptr, false, false, false);
        football.updatePlay(0, 6);
        return;
    }

    if (defense.intercept(chosenCoverage) == true) {
        football.turnover();
        return;
    }
    if (defense.swatBall(chosenCoverage) == true) {
        football.updatePlay(0, 6);
        return;
    }

    int catchType = std::rand() % 4 + 1;
    if (catchType == 1) {
        passToReceiver(true, false, false, false);
    } else if (catchType == 2) {
        passToReceiver(false, true, false, false);
    } else if (catchType == 3) {
        passToReceiver(false, false, true, false);
    } else {
        passToReceiver(false, false, false, true);
    }

    int yards = calculatePassYards();

    if (defense.causeFumble(football.isWet()) == true) {
        football.turnover();
        return;
    }
    defense.tackle();
    football.updatePlay(yards, 30);
}

void Quarterback::runPlay(RunningBack& runningBack, Defense& defense, Football& football) {
    int randomRun = std::rand() % 3 + 1;
    if (randomRun == 1) {
        std::cout << "Play Called: Inside Zone Run" << std::endl;
    } else if (randomRun == 2) {
        std::cout << "Play Called: Outside Toss Sweep" << std::endl;
    } else {
        std::cout << "Play Called: HB Dive" << std::endl;
    }

    int roll = std::rand() % 100 + 1;
    int yards = 0;

    if (roll <= 15) {
        yards = -(std::rand() % 3 + 1); // -1 to -3 yards
    } else if (roll <= 75) {
        yards = std::rand() % 6;        // 0 to 5 yards
    } else if (roll <= 95) {
        yards = std::rand() % 10 + 6;   // 6 to 15 yards
    } else {
        yards = std::rand() % 40 + 16;  // Big run!
    }

    runningBack.breakTackle();

    if (defense.causeFumble(football.isWet()) == true) {
        football.turnover();
        return;
    }
    defense.tackle();
    std::cout << runningBack.getLastName() << " carries the ball for " << yards << " yards." << std::endl;
    football.updatePlay(yards, 35);
}

void Quarterback::rpoPlay(Offense* target, RunningBack& runningBack, Defense& defense, Football& football) {
    std::cout << "Play Called: RPO (Run-Pass Option)" << std::endl;
    std::cout << "Read the defense and choose:" << std::endl;
    std::cout << "1. Hand the ball off to " << runningBack.getLastName() << " (Run)" << std::endl;
    std::cout << "2. Throw Short Bubble Screen " << defense.getCoverageText(defense.shortCoverage) << std::endl;
    std::cout << "3. Throw Medium Slant Route " << defense.getCoverageText(defense.mediumCoverage) << std::endl;
    std::cout << "Choice: ";

    int choice = 1;
    std::cin >> choice;

    if (choice == 1) {
        runPlay(runningBack, defense, football);
        return;
    }

    int chosenCoverage = defense.shortCoverage;
    if (choice == 2) {
        chosenCoverage = defense.shortCoverage;
        throwBallPower(target, true, false, false);
    } else {
        chosenCoverage = defense.mediumCoverage;
        throwBallPower(target, false, true, false);
    }

    if (defense.intercept(chosenCoverage) == true) {
        football.turnover();
        return;
    }
    if (defense.swatBall(chosenCoverage) == true) {
        football.updatePlay(0, 6);
        return;
    }

    passToReceiver(false, true, false, false);
    int yards = calculatePassYards();

    if (defense.causeFumble(football.isWet()) == true) {
        football.turnover();
        return;
    }
    defense.tackle();
    football.updatePlay(yards, 30);
}

void Quarterback::playActionPlay(Offense* target, Defense& defense, Football& football) {
    std::cout << "Play Called: Play Action Pass! " << getLastName() << " fakes the handoff!" << std::endl;
    passPlay(target, defense, football);
}

void Quarterback::timeManagementPlay(Football& football) {
    std::cout << "Choose a Time Management Play:" << std::endl;
    std::cout << "1. QB Kneel (-1 yard, runs clock)" << std::endl;
    std::cout << "2. QB Spike (0 yards, stops clock)" << std::endl;
    std::cout << "Choice: ";

    int choice = 1;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << getLastName() << " takes a knee for -1 yard." << std::endl;
        football.updatePlay(-1, 40);
    } else {
        std::cout << getLastName() << " spikes the ball to stop the clock!" << std::endl;
        football.updatePlay(0, 3);
    }
}

void Quarterback::callPlay(Offense* target, RunningBack& runningBack, Center& center, Defense& defense, Football& football) {
    football.showStatus();

    std::cout << "Choose a play type:" << std::endl;
    std::cout << "1. Pass Play" << std::endl;
    std::cout << "2. Run Play" << std::endl;
    std::cout << "3. RPO (Run-Pass Option)" << std::endl;
    std::cout << "4. Play Action" << std::endl;
    std::cout << "5. Time Management (QB Kneel / Spike)" << std::endl;
    std::cout << "6. Special Teams (Field Goal / Punt)" << std::endl;
    std::cout << "7. Quit Game" << std::endl;
    std::cout << "Choice: ";

    int playChoice = 1;
    if (!(std::cin >> playChoice)) {
        return;
    }

    if (playChoice == 7) {
        std::cout << "Thanks for playing!" << std::endl;
        std::exit(0);
    }

    if (playChoice == 6) {
        std::cout << "1. Kick Field Goal" << std::endl;
        std::cout << "2. Punt" << std::endl;
        std::cout << "Choice: ";
        int kickChoice = 1;
        std::cin >> kickChoice;
        if (kickChoice == 1) {
            football.kickFieldGoal();
        } else {
            football.punt();
        }
        return;
    }

    if (playChoice == 5) {
        timeManagementPlay(football);
        return;
    }

    defense.callDefensivePlay();

    bool cleanSnap = center.snapBall(this, football.isWet());
    if (cleanSnap == false) {
        football.updatePlay(-4, 25);
        return;
    }

    if (playChoice == 1) {
        passPlay(target, defense, football);
    } else if (playChoice == 2) {
        runPlay(runningBack, defense, football);
    } else if (playChoice == 3) {
        rpoPlay(target, runningBack, defense, football);
    } else if (playChoice == 4) {
        playActionPlay(target, defense, football);
    } else {
        passPlay(target, defense, football);
    }
}
