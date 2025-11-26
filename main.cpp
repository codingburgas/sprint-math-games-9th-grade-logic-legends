#include <iostream>
using namespace std;

int main() {
     int difficultyLevel = 0;
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
}