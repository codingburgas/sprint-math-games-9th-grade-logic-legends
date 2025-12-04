#include <iostream>
using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

int selectMainMenu()
{
    clearScreen();
    cout << "Main Menu\n" << endl;
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
    cout << "\nEnter your choice (1-3): ";

    int choice;
    cin >> choice;
    return choice;
}

void printHowToPlay()
{
    clearScreen();
    cout << "How to Play:\n" << endl;
    cout << "Select a difficulty level." << endl;
    cout << "A grid will be generated based on the selected difficulty." << endl;
    cout << "\nPress Enter to continue.";
    cin.ignore();
    cin.get();
}

void startGame()
{
    int difficultyChoice = selectDifficultyMenu();

    switch (difficultyChoice)
    {
        case 1:
            cout << "You chose Easy (4x4 grid)." << endl;
            break;
        case 2:
            cout << "You chose Normal (5x5 grid)." << endl;
            break;
        case 3:
            cout << "You chose Hard (7x7 grid)." << endl;
            break;
        default:
            cout << "Invalid difficulty choice!" << endl;
            return;
    }
    cout << "Generating grid..." << endl;

    cin.ignore();
    cin.get();
}

int main()
{
    bool exitProgram = false;

    while (!exitProgram)
    {
        int mainChoice = selectMainMenu();

        switch (mainChoice)
        {
            case 1:
                startGame();
                break;

            case 2:
                printHowToPlay();
                break;

            case 3:
                cout << "Exiting program..." << endl;
                exitProgram = true;
                break;

            default:
                cout << "Invalid choice. Please select 1, 2, or 3.\n";
                cin.ignore();
                cin.get();
                break;
        }
    }

    return 0;
}

