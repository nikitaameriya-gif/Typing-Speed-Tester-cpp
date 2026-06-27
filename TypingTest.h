#ifndef TYPINGTEST_H
#define TYPINGTEST_H

#include <iostream>
#include <string>
using namespace std;

class TypingTest {
private:
    string referenceText;

public:
    void setDifficulty(int level);
    string getText();

    double calculateWPM(double time, int words);
    double calculateAccuracy(string userInput);
};

#endif
