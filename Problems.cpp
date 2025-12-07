#include "Problems.h"
 
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
namespace
{
    // Easy: just plus or minus.
    void makeEasyProblem(string& questionText, int& correctAnswer)
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
    void makeNormalProblem(string& questionText, int& correctAnswer)
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
    void makeHardProblem(string& questionText, int& correctAnswer)
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
