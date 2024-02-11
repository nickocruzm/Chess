#include "Input.h"

using namespace std;

void Input::move() {

    bool isValid = false;
    while (!isValid) {
        cout << "Enter the position of the piece that you would like to move: ";
        string coords;
        cin >> coords;
    char pos1 = coords[0];
        int first = coords[0] - 'a';
        int sec = coords[1] - '0';

        if (pos1 >= 'a' && pos1 <= 'h' && sec >= 1 && sec <= 8) {
            isValid = true;
            initialX = first + 1; 
            initialY = sec;

        } else {
            cout << "Invalid Input, please enter the position of the piece again." << endl;
        }
    }
    isValid = false;
    while (!isValid) {
        cout << "Enter the final position of the piece you would like to move to: ";
        string coords;
        cin >> coords;
        char pos1 = coords[0];
        int first = coords[0] - 'a';
        int sec = coords[1] - '0';

        if (pos1 >= 'a' && pos1 <= 'h' && sec >= 1 && sec <= 8) {
            isValid = true;
            finalX = first + 1;
            finalY = sec;
        } else {
            cout << "Invalid Input, please enter the position again." << endl;
        }
    }

}

bool Input::moveTest(string input) {
    
        cout << "Enter the position of the piece that you would like to move: " << endl;
        string coords = input;
        char pos1 = (tolower(coords[0]));
        int first = coords[0] - 'a';
        int sec = coords[1] - '0';
        int size = coords.length();
        if (pos1 >= 'a' && pos1 <= 'h' && sec >= 1 && sec <= 8 && size == 2) {
            
            
            return true;
        }
        else {
            return false;
        }
    }
    




