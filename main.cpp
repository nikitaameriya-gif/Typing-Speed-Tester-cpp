#include "TypingTest.h"
#include "ScoreManager.h"
#include <chrono>
#include <sstream>

int main() {
    TypingTest test;
    ScoreManager sm;

    string name;
    int choice, level;

    cout << "Enter your name: ";
    cin >> name;

    do {
        cout << "\n===== TYPING SPEED TESTER =====\n";
        cout << "1. Start Test\n";
        cout << "2. View Leaderboard\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "\nSelect Difficulty:\n1. Easy\n2. Medium\n3. Hard\nChoice: ";
            cin >> level;

            test.setDifficulty(level);

            cin.ignore();
            cout << "\nType this:\n";
            cout << test.getText() << "\n\nPress Enter to start...";
            cin.get();

            auto start = chrono::high_resolution_clock::now();

            string input;
            getline(cin, input);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;

            stringstream ss(input);
            int words = 0;
            string temp;

            while (ss >> temp) words++;

            double wpm = test.calculateWPM(time.count(), words);
            double acc = test.calculateAccuracy(input);

            cout << "\n----- RESULT -----\n";
            cout << "Time: " << time.count() << " sec\n";
            cout << "WPM: " << wpm << endl;
            cout << "Accuracy: " << acc << "%\n";

            sm.saveScore(name, wpm, acc);
        }

        else if (choice == 2) {
            sm.showScores();
        }

    } while (choice != 3);

    return 0;
}
