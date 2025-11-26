#include <iostream>
using namespace std;
string getDifficultyName(int level) {
    switch(level) {
        case 1: return "Easy";
        case 2: return "Normal";
        case 3: return "Hard";
        default: return "Unknown";
    }
}

int main() {
     int difficultyLevel = 0;
     int gridSize = 0;
    cout << "Choose Difficulty" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Normal" << endl;
    cout << "3. Hard" << endl;
    while(difficultyLevel != 1 && difficultyLevel != 2 && difficultyLevel != 3) {
    cin >> difficultyLevel;
    if(difficultyLevel != 1 && difficultyLevel != 2 && difficultyLevel != 3) {
        cout << "Invalid choice. Please select 1, 2, or 3." << endl;
    }
}
switch(difficultyLevel) {
    case 1:
        gridSize = 4;
        break;
    case 2:
        gridSize = 5;
        break;
    case 3:
        gridSize = 7;
        break;
}
cout << "You selected difficulty " << getDifficultyName(difficultyLevel) << " with grid size " << gridSize << "x" << gridSize << "." << endl;
    return 0;
}

