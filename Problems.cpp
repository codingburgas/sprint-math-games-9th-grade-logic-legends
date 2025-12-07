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
}
