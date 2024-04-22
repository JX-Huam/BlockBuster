#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "Block.hpp"
using namespace std;

Block::Block(){}
Block::Block(int _x, int _y, int _color, int _r, int _c, bool _valid){
    setPosition(_x, _y);
    setTilePosition(_r, _c);
    setColor(_color);
    setValid(_valid);
}
Block::~Block(){}


int Block::getX() const {return x;}
int Block::getY() const {return y;}
int Block::getColor() const {return color;}
bool Block::getValid() const {return valid;}
int Block::getR() const {return r;}
int Block::getC() const {return c;}
bool Block::getSame() const {return same;}

void Block::setX(int _x) {_x = x;}
void Block::setY(int _y) {_y = y;}
void Block::setColor(int _color) {color = _color;}
void Block::setValid(bool _valid) {valid = _valid;}
void Block::setR(int _r) {r = _r;}
void Block::setC(int _c) {c = _c;}
void Block::setSame(bool _same) {same = _same;}

void Block::setPosition(int _x, int _y){
    x = _x;
    y = _y;
}

void Block::setTilePosition(int _r, int _c){
    r = _r;
    c = _c;
}

void Block::_draw(int _color) const {
    setcolor(_color);
    setfillstyle(SOLID_FILL, _color);
    rectangle(x, y, x+50, y+50);
    floodfill(x+1, y+1, _color);
}

void Block::draw() const {_draw(color);}
void Block::undraw() const {_draw(BLACK);}

void Block::destroy(){
    setColor(BLACK);
    setValid(true);
    setSame(false);
}