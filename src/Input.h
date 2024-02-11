#ifndef __INPUT_H__
#define __INPUT_H__

#include <iostream>

using namespace std;
class Input {
    public:
        int initialX = 0;
        int initialY = 0;
        int finalX = 0;
        int finalY = 0;

    public:
        bool moveTest(string input);
        void move();
};

#endif 