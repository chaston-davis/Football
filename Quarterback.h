#ifndef QUARTERBACK_H
#define QUARTERBACK_H

#include "Offense.h"
#include "Center.h"
#include "RunningBack.h"
#include "Defense.h"
#include "football.h"
#include <iostream>
#include <string>

class Quarterback : public Offense {
public:
    Quarterback() { hasBall = true; }
    Quarterback(std::string firstName, std::string lastName);
    virtual ~Quarterback() {}

    std::string getPosition() const override { return "Quarterback"; }

    void throwBallPower(Offense* target, bool ballThrownShort, bool ballThrownMedium, bool ballThrownLong);
    void passToReceiver(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded);
    int calculatePassYards();

    void callPlay(Offense* target, RunningBack& runningBack, Center& center, Defense& defense, Football& football);
    void passPlay(Offense* target, Defense& defense, Football& football);
    void runPlay(RunningBack& runningBack, Defense& defense, Football& football);
    void rpoPlay(Offense* target, RunningBack& runningBack, Defense& defense, Football& football);
    void playActionPlay(Offense* target, Defense& defense, Football& football);
    void timeManagementPlay(Football& football);

private:
    Offense* target_ = nullptr;
    bool ballThrownShort = false;  // private: only the QB touches this
    bool ballThrownMedium = false;
    bool ballThrownLong = false;
};

#endif
