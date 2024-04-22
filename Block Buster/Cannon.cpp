#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "Cannon.hpp"
using namespace std;

Cannon::Cannon(int _x, int _y, int _color, int _r, int _c){
    setPosition(_x,_y);
    setTilePosition(_r, _c);
    setColor(_color);
    draw();
}
Cannon::~Cannon(){}

int Cannon::getX(){return x;}
int Cannon::getY(){return y;}
int Cannon::getColor(){return color;}
int Cannon::getR() {return r;}
int Cannon::getC() {return c;}

void Cannon::setX(int _x) {x = _x;}
void Cannon::setY(int _y) {y = _y;}
void Cannon::setColor(int _color) {color = _color;}
void Cannon::setR(int _r) {r = _r;}
void Cannon::setC(int _c) {c = _c;}

void Cannon::setPosition(int _x, int _y){
    setX(_x);
    setY(_y);
}
void Cannon::setTilePosition(int _r, int _c){
    r = _r;
    c = _c;
}

void Cannon::_draw(int _color){
    setcolor(_color);
    rectangle(x, y, x+50, y+50);
}

void Cannon::draw(){ _draw(color);}
void Cannon::undraw(){ _draw(BLACK);}

void Cannon::moveLeft(){
    if(x > 55){
        undraw();
        setPosition(x - 55, y);
        setC(getC() - 1);
        draw();
    }
}

void Cannon::moveRight(){
    if(x < 550){
        undraw();
        setPosition(x + 55, y);
        setC(getC() + 1);
        draw();
    }
}
