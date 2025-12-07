#include "Problems.h"

#include <cstdlib>
#include <ctime>

using namespace std;

namespace
{
    // Easy: just plus or minus.
    void makeEasyProblem(string &questionText, int &correctAnswer)
    {
        int a = randomInRange(1, 20);
        int b = randomInRange(1, 20);
        bool useAddition = (rand() % 2 == 0);

        if (useAddition)
        {
            questionText = to_string(a) + " + " + to_string(b) + " = ?";
            correctAnswer = a + b;
        }
        else
        {
            questionText = to_string(a) + " - " + to_string(b) + " = ?";
            correctAnswer = a - b;
        }
    }

    // Normal: plus, minus, times, divide.
    void makeNormalProblem(string &questionText, int &correctAnswer)
    {
        int choice = rand() % 4;

        switch (choice)
        {
        case 0: // addition
        {
            int a = randomInRange(1, 30);
            int b = randomInRange(1, 30);
            questionText = to_string(a) + " + " + to_string(b) + " = ?";
            correctAnswer = a + b;
            break;
        }
        case 1: // subtraction
        {
            int a = randomInRange(1, 30);
            int b = randomInRange(1, 30);
            questionText = to_string(a) + " - " + to_string(b) + " = ?";
            correctAnswer = a - b;
            break;
        }
        case 2: // multiplication up to 10x10
        {
            int a = randomInRange(1, 10);
            int b = randomInRange(1, 10);
            questionText = to_string(a) + " x " + to_string(b) + " = ?";
            correctAnswer = a * b;
            break;
        }
        case 3: // integer division
        default:
        {
            int divisor = randomInRange(1, 10);
            int multiplier = randomInRange(1, 10);
            int dividend = divisor * multiplier;
            questionText = to_string(dividend) + " / " + to_string(divisor) + " = ?";
            correctAnswer = dividend / divisor;
            break;
        }
        }
    }

    // Hard: mixed expressions and a few extras.
    void makeHardProblem(string &questionText, int &correctAnswer)
    {
        int choice = rand() % 6;

        switch (choice)
        {
        case 0: // base operations from normal
            makeNormalProblem(questionText, correctAnswer);
            return;
        case 1: // mixed expression: axb - c
        {
            int a = randomInRange(2, 12);
            int b = randomInRange(2, 12);
            int c = randomInRange(1, 15);
            questionText = to_string(a) + " x " + to_string(b) + " - " + to_string(c) + " = ?";
            correctAnswer = (a * b) - c;
            break;
        }
        case 2: // mixed expression: a + b x c
        {
            int a = randomInRange(1, 15);
            int b = randomInRange(2, 9);
            int c = randomInRange(2, 9);
            questionText = to_string(a) + " + " + to_string(b) + " x " + to_string(c) + " = ?";
            correctAnswer = a + (b * c);
            break;
        }
        case 3: // square
        {
            int a = randomInRange(3, 12);
            questionText = to_string(a) + "^2 = ?";
            correctAnswer = a * a;
            break;
        }
        case 4: // modulo
        {
            int b = randomInRange(2, 12);
            int a = randomInRange(b, b * 3); // ensure a >= b
            questionText = to_string(a) + " % " + to_string(b) + " = ?";
            correctAnswer = a % b;
            break;
        }
        case 5: // integer division large
        default:
        {
            int divisor = randomInRange(2, 12);
            int multiplier = randomInRange(2, 12);
            int dividend = divisor * multiplier;
            int add = randomInRange(1, 10);
            questionText = to_string(dividend) + " / " + to_string(divisor) + " + " + to_string(add) + " = ?";
            correctAnswer = (dividend / divisor) + add;
            break;
        }
        }
    }
}

// Basic random helper.
int randomInRange(int low, int high)
{
    return low + (rand() % (high - low + 1));
}

// Make a problem for the chosen difficulty.
void generateProblem(int difficultyLevel, string &questionText, int &correctAnswer, bool &trapHere, bool &givesLife, bool &givesBonusPoints)
{
    if (difficultyLevel == DIFF_EASY)
        makeEasyProblem(questionText, correctAnswer);
    else if (difficultyLevel == DIFF_NORMAL)
        makeNormalProblem(questionText, correctAnswer);
    else
        makeHardProblem(questionText, correctAnswer);

    trapHere = false;
    givesLife = false;
    givesBonusPoints = false;
}

// Set size, lives, and points for each difficulty.
void configForDifficulty(int difficultyLevel, int &gridSize, int &startingLives, int &minPointsPerQuestion, int &maxPointsPerQuestion, bool &hasLifeBonusCells, bool &hasBonusPointCells, bool &hasTrapCells)
{
    if (difficultyLevel == DIFF_EASY)
    {
        gridSize = 4;
        startingLives = 4;
        minPointsPerQuestion = 5;
        maxPointsPerQuestion = 10;
        hasLifeBonusCells = false;
        hasBonusPointCells = false;
        hasTrapCells = false;
        return;
    }
    if (difficultyLevel == DIFF_NORMAL)
    {
        gridSize = 5;
        startingLives = 3;
        minPointsPerQuestion = 8;
        maxPointsPerQuestion = 15;
        hasLifeBonusCells = true;
        hasBonusPointCells = true;
        hasTrapCells = false;
        return;
    }
    // Hard
    gridSize = 7;
    startingLives = 2;
    minPointsPerQuestion = 10;
    maxPointsPerQuestion = 25;
    hasLifeBonusCells = true;
    hasBonusPointCells = true;
    hasTrapCells = true;
}

// Fill the grid with questions and mark bonus/trap cells.
void buildGrid(string cellQuestions[][MAX_GRID], int cellAnswers[][MAX_GRID], bool cellIsTrap[][MAX_GRID], bool cellGivesLife[][MAX_GRID], bool cellBonusPoints[][MAX_GRID], int gridSize, int difficultyLevel, bool hasLifeBonusCells, bool hasBonusPointCells, bool hasTrapCells)
{
    for (int r = 0; r < gridSize; ++r)
    {
        for (int c = 0; c < gridSize; ++c)
        {
            generateProblem(difficultyLevel, cellQuestions[r][c], cellAnswers[r][c], cellIsTrap[r][c], cellGivesLife[r][c], cellBonusPoints[r][c]);
            if (hasLifeBonusCells && (rand() % 100) < 10 && !(r == 0 && c == 0))
                cellGivesLife[r][c] = true;
            if (hasBonusPointCells && (rand() % 100) < 15 && !(r == 0 && c == 0))
                cellBonusPoints[r][c] = true;
            if (hasTrapCells && (rand() % 100) < 12 && !(r == 0 && c == 0))
                cellIsTrap[r][c] = true;
        }
    }
}
