#include <iostream>

#include "Game.h"

using namespace std;

namespace
{
    // Simple pause: clear leftover input and wait for Enter.
    void pauseForEnter()
    {
        cin.ignore(10000, '\n');
        cin.get();
    }

    // Main menu prompt.
    int selectMainMenu()
    {
        clearScreen();
        cout << "Math Maze\n\n";
        cout << "1. Start Game\n";
        cout << "2. How to Play\n";
        cout << "3. Exit\n";
        cout << "\nEnter choice (1-3): ";
        int choice;
        cin >> choice;
        return choice;
    }

    // Difficulty picker.
    int selectDifficultyMenu()
    {
        clearScreen();
        cout << "Choose Difficulty:\n\n";
        cout << "1. Easy (4x4, + / -)\n";
        cout << "2. Normal (5x5, + - x /, bonuses)\n";
        cout << "3. Hard (7x7, mixed, traps)\n";
        cout << "\nEnter choice (1-3): ";
        int choice;
        cin >> choice;
        return choice;
    }

    // Quick how-to screen.
    void showHowToPlay()
    {
        clearScreen();
        cout << "How to Play:\n\n";
        cout << "- Start at (0,0) and reach the bottom-right corner.\n";
        cout << "- Each move asks you to solve a math problem.\n";
        cout << "- Correct answer: you move and earn points.\n";
        cout << "- Wrong answer: you stay put and lose a life.\n";
        cout << "- W/A/S/D to move, q to leave the run.\n\n";
        cout << "Press Enter to return...";
        pauseForEnter();
    }
}

// Program entry: loop menus and start runs.
int main()
{
    bool exitProgram = false;
