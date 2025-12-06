#include "Game.h"
 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <limits>
 
using namespace std;
 
namespace
{
    // Pause so the player can read messages.
    void waitForEnter()
    {
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
 
    // Ask a math question and see if they got it.
    bool askQuestion(const string& questionText, int correctAnswer)
    {
        cout << "\nSolve: " << questionText << endl;
        int userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;
        return userAnswer == correctAnswer;
    }
 
    // Turn WASD into row/col changes.
    void directionToPositionChange(char dir, int& rowChange, int& colChange)
    {
        rowChange = 0;
        colChange = 0;
        switch (dir)
        {
            case 'w': rowChange = -1; colChange = 0; break;
            case 's': rowChange = 1; colChange = 0; break;
            case 'a': rowChange = 0; colChange = -1; break;
            case 'd': rowChange = 0; colChange = 1; break;
            default: break;
        }
    }
 
