#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

// --------------------- MENUS ---------------------

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

// --------------------- GRID GENERATION ---------------------

void generateGrid(int size)
{
    clearScreen();
    srand(time(0)); // seed RNG

    cout << "\nGenerated Grid (" << size << "x" << size << "):\n\n";

    // Print column numbers
    cout << "    ";
    for (int col = 1; col <= size; col++)
        cout << col << "   ";
    cout << "\n";

    // Print rows with row numbers
    for (int row = 1; row <= size; row++)
    {
        cout << row << " | ";
        for (int col = 1; col <= size; col++)
        {
            int randomNumber = rand() % 10;
            cout << randomNumber << "   ";
        }
        cout << "\n";
    }
    cout << endl;
}

// --------------------- START GAME ---------------------

void startGame()
{
    clearScreen();
    int difficultyChoice = selectDifficultyMenu();
    int size = 0;
    switch (difficultyChoice)
    {
        case 1: size = 4; break;
        case 2: size = 5; break;
        case 3: size = 7; break;
        default:
            cout << "Invalid choice.\n";
            cin.ignore();
            cin.get();
            return;
    }
    generateGrid(size);
    cout << "Press Enter to return to menu...";
    cin.ignore();
    cin.get();
}

// --------------------- MAIN ---------------------

int main()
{
    clearScreen();
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
                cout << "Invalid choice. Press Enter...";
                cin.ignore();
                cin.get();
                break;
        }
    }

    return 0;
}
