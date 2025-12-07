#include "Game.h"
#include "Problems.h"
 
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

// Clear the console.
void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}
 
// Core game loop for one difficulty setting.
void runGame(int difficultyLevel)
{
    srand(static_cast<unsigned int>(time(nullptr)));
 
    int gridSize, livesLeft, minPointsPerQuestion, maxPointsPerQuestion;
    bool hasLifeBonusCells, hasBonusPointCells, hasTrapCells;
    configForDifficulty(difficultyLevel, gridSize, livesLeft, minPointsPerQuestion, maxPointsPerQuestion, hasLifeBonusCells, hasBonusPointCells, hasTrapCells);
 
    string cellQuestions[MAX_GRID][MAX_GRID];
    int cellAnswers[MAX_GRID][MAX_GRID];
    bool cellIsTrap[MAX_GRID][MAX_GRID];
    bool cellGivesLife[MAX_GRID][MAX_GRID];
    bool cellBonusPoints[MAX_GRID][MAX_GRID];
    bool cellVisited[MAX_GRID][MAX_GRID] = {};
    cellVisited[0][0] = true;
    buildGrid(cellQuestions, cellAnswers, cellIsTrap, cellGivesLife, cellBonusPoints, gridSize, difficultyLevel, hasLifeBonusCells, hasBonusPointCells, hasTrapCells);
 
    int playerRow = 0;
    int playerCol = 0;
    int score = 0;
 
    // Loop through turns until you win or run out of lives.
    while (true)
    {
        // Check loss.
        if (livesLeft <= 0)
        {
            clearScreen();
            cout << "You ran out of lives. Game over.\n";
            waitForEnter();
            return;
        }
        // Check win.
        if (playerRow == gridSize - 1 && playerCol == gridSize - 1)
        {
            clearScreen();
            cout << "You reached the goal! Final score: " << score << "\n";
            waitForEnter();
            return;
        }
 
        // Show HUD each turn.
        printStatus(playerRow, playerCol, gridSize, livesLeft, score, cellVisited);
 
        cout << "Enter direction: ";
        char dir;
        cin >> dir;
        if (dir == 'q' || dir == 'Q')
            return;
 
        dir = static_cast<char>(std::tolower(static_cast<unsigned char>(dir)));
        int rowChange, colChange;
        directionToPositionChange(dir, rowChange, colChange);
        int nextRow = playerRow + rowChange;
        int nextCol = playerCol + colChange;
 
        // Ignore invalid commands.
        if (rowChange == 0 && colChange == 0)
        {
            cout << "Use W/A/S/D to move.\n";
            waitForEnter();
            continue;
        }
 
        // Keep player inside the grid.
        if (nextRow < 0 || nextCol < 0 || nextRow >= gridSize || nextCol >= gridSize)
        {
            cout << "You cannot move outside the grid.\n";
            waitForEnter();
            continue;
        }
 
        // Already explored? Just move there without asking again.
        if (cellVisited[nextRow][nextCol])
        {
            playerRow = nextRow;
            playerCol = nextCol;
            cout << "You already solved this cell. Moving...\n";
            waitForEnter();
            continue;
        }

        // Ask the problem for the destination cell.
        bool correct = askQuestion(cellQuestions[nextRow][nextCol], cellAnswers[nextRow][nextCol]);
        if (!correct)
        {
            livesLeft -= 1;
            cout << "Wrong answer. You lost a life. Lives left: " << livesLeft << "\n";
            waitForEnter();
            continue;
        }

        // Handle traps (hard mode).
        if (cellIsTrap[nextRow][nextCol])
        {
            bool trapCleared = handleTrap(difficultyLevel, livesLeft);
            if (!trapCleared || livesLeft <= 0)
            {
                cout << "Lives left: " << livesLeft << "\n";
                waitForEnter();
                continue;
            }
        }

        // Add points and bonuses.
        int earned = randomInRange(minPointsPerQuestion, maxPointsPerQuestion);
        if (cellBonusPoints[nextRow][nextCol])
        {
            earned *= 2;
            cout << "Bonus cell! Points doubled.\n";
        }
        score += earned;
        if (cellGivesLife[nextRow][nextCol])
        {
            livesLeft += 1;
            cout << "Lucky cell! You gained +1 life.\n";
        }

        // Move the player.
        cout << "Correct! +" << earned << " points.\n";
        playerRow = nextRow;
        playerCol = nextCol;
        cellVisited[playerRow][playerCol] = true;
        waitForEnter();
    }
}
