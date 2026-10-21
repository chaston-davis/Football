#ifndef DEFENSE_H
#define DEFENSE_H

#include <iostream>
#include <string>

class Defense {
public:
    Defense();
    
    int shortCoverage;
    int mediumCoverage;
    int deepCoverage;
    std::string playName;

    void callDefensivePlay();
    std::string getCoverageText(int coverage);

    bool swatBall(int coverage);
    bool intercept(int coverage);
    bool causeFumble(bool wet);
    bool tackle();
    void run();
};

#endif
