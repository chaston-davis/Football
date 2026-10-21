#ifndef FOOTBALL_H
#define FOOTBALL_H

#include <iostream>
#include <string>

class Football {
public:
    Football();
    Football(int yardLine, bool wet);
    ~Football();

    void setupGame();
    void coinFlip();

    void getYardLine();
    void getWetness();
    bool isWet();

    void showStatus();
    void updatePlay(int yardsGained, int secondsUsed);
    void advanceClock(int secondsUsed);
    void aiDrive();
    void turnover();
    void kickFieldGoal();
    void punt();
    bool isGameOver();

private:
    int yardLine_;
    bool wet_;
    int down_;
    int yardsToGo_;
    int quarter_;
    int quarterLength_;
    int secondsLeft_;
    bool userHasBallFirst_;
    bool userGotBallFirst_;
    bool gameOver_;

    std::string userTeam_;
    std::string aiTeam_;
    std::string gameImportance_;
    int userScore_;
    int aiScore_;
};

#endif