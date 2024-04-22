#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "Bullet.hpp"
#include "Cannon.hpp"
using namespace std;

Bullet::Bullet(int _x, int _y, int _color, int _r, int _c, bool _valid):Block(_x,_y,_color,_r,_c,_valid){}
Bullet::~Bullet(){}

Bullet Bullet::create(){
    Bullet x = Bullet(910,695,rand() % 4 + 1, 10, 0,true);
    return x;
}

void Bullet::moveLeft(){
    if(x > 55){
        undraw();
        setPosition(x - 55, y);
        setC(getC() - 1);
        draw();
    }
}

void Bullet::moveRight(){
    if(x < 550){
        undraw();
        setPosition(x + 55, y);
        setC(getC() + 1);
        draw();
    }
}

void Bullet::moveUp(){
    undraw();
    setPosition(x, y - 55);
    setR(getR() - 1);
    draw();
    delay(100);

}

void Bullet::checkValid(Enemy **tiles){
    if(getR() != 0){
        if(tiles[getR()-1][getC()].getValid() != true){
            setValid(false);
        }else{
            setValid(true);
        }
    }else{
        setValid(false);
    }
}

