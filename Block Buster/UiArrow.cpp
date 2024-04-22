#include <graphics.h>
#include "UiArrow.hpp"

using namespace std;

UiArrow::UiArrow(int _x, int _y): Button(_x,_y) {}
UiArrow::~UiArrow(){}

int UiArrow::getX() const{return x;}
int UiArrow::getY() const{return y;}
void UiArrow::setX(int _x){x = _x;}
void UiArrow::setY(int _y){y = _y;}

void UiArrow::draw(){
    int points[8] = {x, y, x+40, y+20, x, y+40, x, y};
    setcolor(14);
    drawpoly(4, points);
    setfillstyle(SOLID_FILL, 14);
    fillpoly(4, points);
}

void UiArrow::undraw(){
    int points[8] = {x, y, x+40, y+20, x, y+40, x, y};
    setcolor(0);
    drawpoly(4, points);
    setfillstyle(SOLID_FILL, 0);
    fillpoly(4, points);
}