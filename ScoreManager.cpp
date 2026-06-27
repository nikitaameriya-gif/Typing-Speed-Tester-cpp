#include "ScoreManager.h"
#include <fstream>

void ScoreManager::saveScore(string name, double wpm, double accuracy) {
    ofstream file("scores.txt", ios::app);
    file << name << " " << wpm << " " << accuracy << endl;
    file.close();
}

void ScoreManager::showScores() {
    ifstream file("scores.txt");

    string name;
    double wpm, acc;

    cout << "\n===== LEADERBOARD =====\n";

    while (file >> name >> wpm >> acc) {
        cout << "Name: " << name
             << " | WPM: " << wpm
             << " | Accuracy: " << acc << "%\n";
    }

    file.close();
}
