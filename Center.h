#ifndef CENTER_H
#define CENTER_H

#include "Offense.h"
#include <iostream>
#include <string>

class Center : public Offense {
public:
    Center() {}
    Center(std::string firstName, std::string lastName);
    virtual ~Center() {}

    std::string getPosition() const override { return "Center"; }

    bool snapBall(Offense* qb, bool wet);

private:
    bool ballSnapped = false;  // private: only the Center touches this
};

#endif
