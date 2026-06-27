#include "TypingTest.h"
#include <sstream>

void TypingTest::setDifficulty(int level) {
    if (level == 1) {
        referenceText = "The sky is blue and birds are flying";
    }
    else if (level == 2) {
        referenceText = "C++ is a powerful programming language used for system development";
    }
    else {
        referenceText = "Success is not final failure is not fatal it is the courage to continue that counts";
    }
}

string TypingTest::getText() {
    return referenceText;
}

double TypingTest::calculateWPM(double time, int words) {
    return (words / time) * 60;
}

double TypingTest::calculateAccuracy(string userInput) {
    stringstream ref(referenceText);
    stringstream user(userInput);

    string r, u;
    int correct = 0, total = 0;

    while (ref >> r) {
        if (user >> u && r == u)
            correct++;
        total++;
    }

    return (total == 0) ? 0 : ((double)correct / total) * 100;
}
