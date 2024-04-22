#ifndef BUTTON_H
#define BUTTON_H

#include <string.h>

using namespace std;

class Button
{
    protected:
        int x, y;

    public:
        Button(int _x, int _y);
        virtual ~Button();

        virtual void draw() = 0;
        virtual void undraw() = 0;
};

#endif