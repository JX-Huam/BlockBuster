#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "Button.hpp"

class UiButton : public Button
{   
    private:
        string text;

    public:
        UiButton(int _x, int _y, string _text);
        ~UiButton();

        void draw();
        void undraw();
};

#endif