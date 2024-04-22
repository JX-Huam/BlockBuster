#ifndef UIARROW_H
#define UIARROW_H

#include "Button.hpp"

class UiArrow : public Button
{   
    public:
        UiArrow(int _x, int _y);
        ~UiArrow();

        int getX() const;
        int getY() const;
        void setX(int _x);
        void setY(int _y);

        void draw();
        void undraw();
};

#endif