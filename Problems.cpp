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
}
