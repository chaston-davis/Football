#ifndef OFFENSE_H
#define OFFENSE_H

#include <iostream>
#include <string>

class Offense {
public:
    bool hasBall = false;  // public: anyone on offense can hold the ball

    Offense() {}
    virtual ~Offense() {}

    // Virtual methods for player names and positions
    virtual std::string getPosition() const { return "Offense"; }

    virtual std::string getFirstName() const {
        if (firstName_.empty()) {
            return getPosition();
        }
        return firstName_;
    }

    virtual std::string getLastName() const {
        if (lastName_.empty()) {
            return getPosition();
        }
        return lastName_;
    }

    virtual std::string getFullName() const {
        if (firstName_.empty() && lastName_.empty()) {
            return getPosition();
        }
        return firstName_ + " " + lastName_;
    }

    virtual void setPlayerName(std::string first, std::string last) {
        firstName_ = first;
        lastName_ = last;
    }

    // Virtual method to prompt user for player name
    virtual void promptPlayerName() {
        std::cout << "Enter " << getPosition() << " First and Last name: ";
        std::cin >> firstName_ >> lastName_;
    }

    void runBall();
    virtual void catchBall(bool, bool, bool, bool) {}

    void getPoints();

protected:
    std::string firstName_ = "";
    std::string lastName_ = "";
};

#endif
