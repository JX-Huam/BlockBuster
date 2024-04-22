#include <graphics.h>
#include "UiButton.hpp"

using namespace std;

UiButton::UiButton(int _x, int _y, string _text): Button(_x,_y), text(_text){}
UiButton::~UiButton(){}

void UiButton::draw(){
    setcolor(14);
    settextstyle(9, HORIZ_DIR, 5);
    outtextxy(x, y, (char*)text.c_str());
}

void UiButton::undraw(){
    setcolor(15);
    settextstyle(9, HORIZ_DIR, 5);
    outtextxy(x, y, (char*)text.c_str());
}