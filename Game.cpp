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
 
// Draw a simple ASCII grid with player/start/goal markers.
    void drawGrid(int gridSize, int playerRow, int playerCol, bool visited[][MAX_GRID])
    {
        cout << "\n";
        for (int r = 0; r < gridSize; ++r)
        {
            cout << " ";
            for (int c = 0; c < gridSize; ++c) cout << "+---";
            cout << "+\n ";
 
            for (int c = 0; c < gridSize; ++c)
            {
                char symbol = '.';
                if (r == 0 && c == 0 && !(playerRow == 0 && playerCol == 0))
                    symbol = 'S'; // start
                if (r == gridSize - 1 && c == gridSize - 1)
                    symbol = 'G'; // goal
                if (r == playerRow && c == playerCol)
                    symbol = 'P'; // player
                else if (visited[r][c])
                    symbol = ' '; // explored cells show empty
                cout << "| " << symbol << " ";
            }
            cout << "|\n";
        }
        cout << " ";
        for (int c = 0; c < gridSize; ++c) cout << "+---";
        cout << "+\n";
        cout << "   P = you   S = start   G = goal   . = unexplored\n";
    }
 
    // Quick visual for lives using stars.
    string livesBar(int livesLeft)
    {
        string bar;
        for (int i = 0; i < livesLeft; ++i) bar += "*";
        if (bar.empty()) bar = "-";
        return bar;
    }

  // Show where you are and your stats.
    void printStatus(int playerRow, int playerCol, int gridSize, int livesLeft, int score, bool visited[][MAX_GRID])
    {
        clearScreen();
        cout << "Math Maze (" << gridSize << "x" << gridSize << ")\n";
        cout << "Reach (" << gridSize - 1 << "," << gridSize - 1 << ")\n";
        cout << "Position: (" << playerRow << "," << playerCol << ")  Lives: " << livesLeft << "  Points: " << score << endl;
        cout << "Lives left: [" << livesBar(livesLeft) << "]\n";
        cout << "Move with W/A/S/D then Enter. Type q to quit to menu.\n";
        drawGrid(gridSize, playerRow, playerCol, visited);
    }

// Traps ask a bonus question; miss it and lose 2 lives.
    bool handleTrap(int difficultyLevel, int& livesLeft)
    {
        cout << "\nTrap! Solve the extra problem to escape." << endl;
        string trapQuestion;
        int trapAnswer;
        bool trapFlag, lifeFlag, bonusFlag;
        generateProblem(difficultyLevel, trapQuestion, trapAnswer, trapFlag, lifeFlag, bonusFlag);
        bool ok = askQuestion(trapQuestion, trapAnswer);
        if (!ok)
        {
            livesLeft -= 2;
            cout << "Wrong! You lost 2 lives.\n";
            return false;
        }
        cout << "Nice! You cleared the trap.\n";
        return true;
    }
}
 
