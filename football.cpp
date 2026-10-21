#include "football.h"
#include <cstdlib>
#include <ctime>

Football::Football() {
    yardLine_ = 35;
    wet_ = true;
    down_ = 1;
    yardsToGo_ = 10;
    quarter_ = 1;
    quarterLength_ = 180; // 3 minutes per quarter
    secondsLeft_ = 180;
    userHasBallFirst_ = true;
    userGotBallFirst_ = true;
    gameOver_ = false;
    userTeam_ = "Bears";
    aiTeam_ = "Packers";
    gameImportance_ = "Regular Season";
    userScore_ = 0;
    aiScore_ = 0;
}

Football::Football(int yardLine, bool wet) {
    yardLine_ = yardLine;
    wet_ = wet;
    down_ = 1;
    yardsToGo_ = 10;
    quarter_ = 1;
    quarterLength_ = 180;
    secondsLeft_ = 180;
    userHasBallFirst_ = true;
    userGotBallFirst_ = true;
    gameOver_ = false;
    userTeam_ = "Bears";
    aiTeam_ = "Packers";
    gameImportance_ = "Regular Season";
    userScore_ = 0;
    aiScore_ = 0;
}

Football::~Football() {
}

void Football::setupGame() {
    std::cout << "Enter your team name: ";
    std::getline(std::cin >> std::ws, userTeam_);

    std::cout << "Enter the AI team name: ";
    std::getline(std::cin >> std::ws, aiTeam_);

    std::cout << "Choose game importance (1 = Regular Season, 2 = Playoff Game, 3 = Super Bowl): ";
    int impChoice = 1;
    std::cin >> impChoice;
    if (impChoice == 2) {
        gameImportance_ = "Playoff Game";
    } else if (impChoice == 3) {
        gameImportance_ = "Super Bowl";
    } else {
        gameImportance_ = "Regular Season";
    }

    std::cout << "Is it raining today? (1 for Yes, 0 for No): ";
    int rainChoice = 1;
    std::cin >> rainChoice;
    if (rainChoice == 1) {
        wet_ = true;
        std::cout << "\n" << userTeam_ << " vs " << aiTeam_ << " (" << gameImportance_
                  << "). It's raining and we are ready for kickoff!" << std::endl;
    } else {
        wet_ = false;
        std::cout << "\n" << userTeam_ << " vs " << aiTeam_ << " (" << gameImportance_
                  << "). Clear skies today and we are ready for kickoff!" << std::endl;
    }

    getWetness();
}

void Football::coinFlip() {
    std::cout << "--- Coin Flip ---" << std::endl;
    std::cout << "Pick 1 for Heads or 2 for Tails: ";
    int userCall = 1;
    std::cin >> userCall;

    int flipResult = std::rand() % 2 + 1;
    if (flipResult == 1) {
        std::cout << "The coin landed on Heads!" << std::endl;
    } else {
        std::cout << "The coin landed on Tails!" << std::endl;
    }

    if (userCall == flipResult) {
        userHasBallFirst_ = true;
        userGotBallFirst_ = true;
        std::cout << userTeam_ << " won the coin flip and will get the ball first!" << std::endl;
        yardLine_ = 35;
        down_ = 1;
        yardsToGo_ = 10;
    } else {
        userHasBallFirst_ = false;
        userGotBallFirst_ = false;
        std::cout << aiTeam_ << " won the coin flip and gets the ball first!" << std::endl;
        aiDrive();
    }
}

void Football::getYardLine() {
    std::cout << "The ball is on the " << yardLine_ << " yard line." << std::endl;
}

void Football::getWetness() {
    if (wet_ == true) {
        int dialogueChoice = std::rand() % 10 + 1;

        if (dialogueChoice == 1) {
            std::cout << "The ball looks a bit slick there! It will be hard to handle in this kind of weather!" << std::endl;
        }
        if (dialogueChoice == 2) {
            std::cout << "The rain is making the ball tough to grip for the QB!" << std::endl;
        }
        if (dialogueChoice == 3) {
            std::cout << "The ball is so wet, the receivers will have a hard time catching it!" << std::endl;
        }
        if (dialogueChoice == 4) {
            std::cout << "You have to really focus to handle the ball in these conditions!" << std::endl;
        }
        if (dialogueChoice == 5) {
            std::cout << "The quarterback will really need to grip this ball tight!" << std::endl;
        }
        if (dialogueChoice == 6) {
            std::cout << "The referees keep trying to dry off the ball!" << std::endl;
        }
        if (dialogueChoice == 7) {
            std::cout << "Wet conditions could make that snap unpredictable!" << std::endl;
        }
        if (dialogueChoice == 8) {
            std::cout << "This rain will test everyone's carrying!" << std::endl;
        }
        if (dialogueChoice == 9) {
            std::cout << "There is a higher likelihood of a fumble in these condtions!" << std::endl;
        }
        if (dialogueChoice == 10) {
            std::cout << "I expect there to be a ton of mistakes this game because the ball is so unpredictable!" << std::endl;
        }
    }
}

bool Football::isWet() {
    return wet_;
}

void Football::showStatus() {
    int minutes = secondsLeft_ / 60;
    int seconds = secondsLeft_ % 60;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Score: " << userTeam_ << " " << userScore_ << " - " << aiTeam_ << " " << aiScore_ << std::endl;
    if (quarter_ <= 4) {
        std::cout << "Quarter: " << quarter_;
    } else {
        std::cout << "Quarter: OVERTIME";
    }
    std::cout << " | Time Left: " << minutes << ":";
    if (seconds < 10) {
        std::cout << "0";
    }
    std::cout << seconds << std::endl;
    std::cout << "Down: " << down_ << " | Yards to Go: " << yardsToGo_ << " | Ball on: " << yardLine_ << " yard line" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void Football::advanceClock(int secondsUsed) {
    if (gameOver_ == true) {
        return;
    }

    secondsLeft_ -= secondsUsed;

    if (secondsLeft_ <= 0) {
        if (quarter_ == 1) {
            std::cout << "\n=== END OF 1ST QUARTER ===" << std::endl;
            quarter_ = 2;
            secondsLeft_ = quarterLength_;
        }
        else if (quarter_ == 2) {
            std::cout << "=== HALFTIME ===" << std::endl;
            std::cout << "Halftime Score: " << userTeam_ << " " << userScore_ << " - " << aiTeam_ << " " << aiScore_ << std::endl;
            quarter_ = 3;
            secondsLeft_ = quarterLength_;

            // Whoever didn't get the ball first in Q1 gets it to start the 2nd half!
            if (userHasBallFirst_ == true) {
                std::cout << aiTeam_ << " receives the 2nd half kickoff!" << std::endl;
                aiDrive();
            } else {
                std::cout << userTeam_ << " receives the 2nd half kickoff at the 35 yard line!" << std::endl;
                yardLine_ = 35;
                down_ = 1;
                yardsToGo_ = 10;
            }
        }
        else if (quarter_ == 3) {
            std::cout << "=== END OF 3RD QUARTER ===" << std::endl;
            quarter_ = 4;
            secondsLeft_ = quarterLength_;
        }
        else if (quarter_ == 4 && userScore_ == aiScore_) {
            std::cout << "=== END OF 4TH QUARTER - TIED GAME! HEADING TO OVERTIME! ===" << std::endl;
            quarter_ = 5;
            secondsLeft_ = quarterLength_;
            yardLine_ = 35;
            down_ = 1;
            yardsToGo_ = 10;
        }
        else {
            secondsLeft_ = 0;
            gameOver_ = true;
            std::cout << "========================================" << std::endl;
            std::cout << "              GAME OVER!                " << std::endl;
            std::cout << "Final Score: " << userTeam_ << " " << userScore_ << " - " << aiTeam_ << " " << aiScore_ << std::endl;
            if (userScore_ > aiScore_) {
                std::cout << userTeam_ << " WINS THE " << gameImportance_ << "!!" << std::endl;
            } else if (aiScore_ > userScore_) {
                std::cout << aiTeam_ << " wins the game!" << std::endl;
            } else {
                std::cout << "The game ends in a tie!" << std::endl;
            }
            std::cout << "========================================" << std::endl;
        }
    }
}

void Football::updatePlay(int yardsGained, int secondsUsed) {
    yardLine_ += yardsGained;
    if (yardLine_ < 1) {
        yardLine_ = 1;
    }

    if (yardLine_ >= 100) {
        std::cout << "\n*** TOUCHDOWN " << userTeam_ << "!! (+7 points) ***" << std::endl;
        userScore_ += 7;
        advanceClock(secondsUsed);
        if (gameOver_ == false) {
            std::cout << userTeam_ << " kicks off to " << aiTeam_ << "." << std::endl;
            aiDrive();
        }
        return;
    }

    yardsToGo_ -= yardsGained;
    if (yardsToGo_ <= 0) {
        std::cout << "FIRST DOWN! Moving the chains!" << std::endl;
        down_ = 1;
        yardsToGo_ = 10;
        advanceClock(secondsUsed);
    } else {
        down_++;
        advanceClock(secondsUsed);
        if (down_ > 4 && gameOver_ == false) {
            std::cout << "TURNOVER ON DOWNS! You failed to convert on 4th down." << std::endl;
            turnover();
        }
    }
}

void Football::aiDrive() {
    if (gameOver_ == true) {
        return;
    }

    std::cout << "\n--- " << aiTeam_ << " Offensive Drive ---" << std::endl;
    int aiPlay = std::rand() % 100 + 1;
    if (aiPlay <= 30) {
        std::cout << aiTeam_ << " marches down the field and scores a Touchdown! (+7)" << std::endl;
        aiScore_ += 7;
    } else if (aiPlay <= 55) {
        std::cout << aiTeam_ << " gets into range and kicks a Field Goal! (+3)" << std::endl;
        aiScore_ += 3;
    } else if (aiPlay <= 75) {
        std::cout << "Your defense forces a turnover! " << userTeam_ << " gets the ball back!" << std::endl;
    } else {
        std::cout << "Your defense holds strong and forces " << aiTeam_ << " to punt!" << std::endl;
    }

    yardLine_ = 35;
    down_ = 1;
    yardsToGo_ = 10;
    advanceClock(45);
}

void Football::turnover() {
    if (gameOver_ == true) {
        return;
    }
    std::cout << aiTeam_ << " takes over possession!" << std::endl;
    aiDrive();
}

void Football::kickFieldGoal() {
    int distance = (100 - yardLine_) + 17;
    std::cout << "Attempting a " << distance << "-yard Field Goal..." << std::endl;

    int roll = std::rand() % 100 + 1;
    if (distance <= 55 && roll <= 75) {
        std::cout << "IT'S GOOD! " << userTeam_ << " adds 3 points!" << std::endl;
        userScore_ += 3;
    } else {
        std::cout << "NO GOOD! The kick misses wide!" << std::endl;
    }

    advanceClock(10);
    if (gameOver_ == false) {
        aiDrive();
    }
}

void Football::punt() {
    std::cout << userTeam_ << " punts the ball away to " << aiTeam_ << "." << std::endl;
    advanceClock(10);
    if (gameOver_ == false) {
        aiDrive();
    }
}

bool Football::isGameOver() {
    return gameOver_;
}
