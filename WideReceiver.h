#ifndef WIDERECEIVER_H
#define WIDERECEIVER_H

#include "Offense.h"
#include <iostream>
#include <string>

class WideReceiver : public Offense {
public:
    WideReceiver() {}  // Empty default constructor
    WideReceiver(std::string firstName, std::string lastName);
    virtual ~WideReceiver() {}

    std::string getPosition() const override { return "Wide Receiver"; }

    void catchBall(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded) override;

protected:
    bool catchBallLow = false;
    bool catchBallChest = false;
    bool catchBallHigh = false;
    bool catchBallOneHanded = false;
};

#endif
