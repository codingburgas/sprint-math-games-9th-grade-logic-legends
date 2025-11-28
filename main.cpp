#include <iostream>
using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

int selectMainMenu()
{
    clearScreen();
    cout << "Main Menu\n"
         << endl;
    cout << "1. Start Game" << endl;
    cout << "2. How to Play" << endl;
    cout << "3. Exit" << endl;
    cout << "\nPlease enter your choice (1-3): ";
    int choice;
    cin >> choice;
    return choice;
}

int selectDifficultyMenu()
{
    clearScreen();
    cout << "Select Difficulty Level:\n" << endl;
    cout << "1. Easy (4x4 grid)" << endl;
    cout << "2. Normal (5x5 grid)" << endl;
    cout << "3. Hard (7x7 grid)" << endl;
    int choice;
    cin >> choice;
    return choice;
}

void printHowToPlay()
{
    clearScreen();
    cout << "How to Play:\n"
         << endl;
    cout << "Select a difficulty level." << endl;
    cout << "A grid will be generated based on the selected difficulty." << endl;
    cout << "Press enter to continue." << endl;

    cin.get();
    cin.get();
}

string getDifficultyName(int level)
{
    switch (level)
    {
    case 1:
        return "Easy";
    case 2:
        return "Normal";
    case 3:
        return "Hard";
    default:
        return "Unknown";
    }
}

void switchMainMenuChoice(int mainMenuChoice)
{
    switch (mainMenuChoice)
    {
    case 1:
        cout << "Starting Game..." << endl;
        selectDifficultyMenu();
        break;
    case 2:
        printHowToPlay();
        break;
    case 3:
        cout << "Exiting the game. Goodbye!" << endl;
        exit(0);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}
int main()
{
    int difficultyLevel = 0;
    int gridSize = 0;
    int mainMenuChoice = 0;
    bool exitProgram = false;

    while (!exitProgram)
    {
        while (mainMenuChoice != 1 && mainMenuChoice != 2 && mainMenuChoice != 3)
        {
            mainMenuChoice = selectMainMenu();
            switchMainMenuChoice(mainMenuChoice);
            if (mainMenuChoice != 1 && mainMenuChoice != 2 && mainMenuChoice != 3)
            {
                cout << "Invalid choice. Please select 1, 2, or 3." << endl;
            }
            mainMenuChoice = 0;
        }
    }
}
