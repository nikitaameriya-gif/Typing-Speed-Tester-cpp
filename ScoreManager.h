#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <iostream>
using namespace std;

class ScoreManager {
public:
    void saveScore(string name, double wpm, double accuracy);
    void showScores();
};

#endif
