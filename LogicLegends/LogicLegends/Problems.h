#ifndef PROBLEMS_H
#define PROBLEMS_H

#include "Types.h"

void generateProblem(int difficultyLevel, std::string& questionText, int& correctAnswer, bool& trapHere, bool& givesLife, bool& givesBonusPoints);
void configForDifficulty(int difficultyLevel, int& gridSize, int& startingLives, int& minPointsPerQuestion, int& maxPointsPerQuestion, bool& hasLifeBonusCells, bool& hasBonusPointCells, bool& hasTrapCells);
void buildGrid(std::string cellQuestions[][MAX_GRID], int cellAnswers[][MAX_GRID], bool cellIsTrap[][MAX_GRID], bool cellGivesLife[][MAX_GRID], bool cellBonusPoints[][MAX_GRID], int gridSize, int difficultyLevel, bool hasLifeBonusCells, bool hasBonusPointCells, bool hasTrapCells);
int randomInRange(int low, int high);

#endif // PROBLEMS_H
