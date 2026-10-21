#ifndef RUNNINGBACK_H
#define RUNNINGBACK_H

#include "Offense.h"
#include <iostream>
#include <string>

class RunningBack : public Offense {
public:
    RunningBack() {}
    RunningBack(std::string firstName, std::string lastName);
    virtual ~RunningBack() {}

    std::string getPosition() const override { return "Running Back"; }

    bool breakTackle();
    void catchBall(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded) override;
};

#endif
