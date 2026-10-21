#ifndef TIGHTEND_H
#define TIGHTEND_H

#include "Offense.h"
#include <iostream>
#include <string>

class TightEnd : public Offense {
public:
    TightEnd() {}  // Empty default constructor
    TightEnd(std::string firstName, std::string lastName);
    virtual ~TightEnd() {}

    std::string getPosition() const override { return "Tight End"; }

    void block();
    void catchBall(bool catchBallLow, bool catchBallChest, bool catchBallHigh, bool catchBallOneHanded) override;
};

#endif
