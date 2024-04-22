#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "Enemy.hpp"
using namespace std;

Enemy::Enemy(){}
Enemy::Enemy(int _x, int _y, int _color, int _r, int _c, bool _valid):Block(_x,_y,_color,_r,_c,_valid){}
Enemy::~Enemy(){}

void Enemy::spawnNewLine(Enemy **tiles){
    int x = 55, y = 90;
    for(int col = 0; col < 10; col++){
        tiles[0][col] = Enemy(x,y,rand() % 4 + 1,0,col,false);
        x += 55;
    }
}

void Enemy::drop(Enemy **tiles){
    for(int r = 10; r > 0; r--){
        for(int c = 0; c < 10; c++){
            tiles[r][c].setPosition(tiles[r-1][c].getX(),tiles[r-1][c].getY() + 55);
            tiles[r][c].setTilePosition(tiles[r-1][c].getR() + 1,tiles[r-1][c].getC());
            tiles[r][c].setColor(tiles[r-1][c].getColor());
            tiles[r][c].setValid(tiles[r-1][c].getValid());
        }
    }
}

//provide current checking enemy and enemy array
void Enemy::detectUpSame(Enemy current ,Enemy **tiles){
    if(current.getR() > 0){
        if(current.getColor() == tiles[current.getR() - 1][current.getC()].getColor()){
            tiles[current.getR()][current.getC()].setSame(true);
            tiles[current.getR() - 1][current.getC()].setSame(true);
            detectLeftSame(tiles[current.getR() - 1][current.getC()], tiles);
            detectRightSame(tiles[current.getR() - 1][current.getC()], tiles);
            detectUpSame(tiles[current.getR() - 1][current.getC()], tiles);
        }else{
            return;
        }
    }
}

void Enemy::detectLeftSame(Enemy current ,Enemy **tiles){
    if(current.getC() > 0){
        if(current.getColor() == tiles[current.getR()][current.getC() - 1].getColor()){
            tiles[current.getR()][current.getC()].setSame(true);
            tiles[current.getR()][current.getC() - 1].setSame(true);
            detectUpSame(tiles[current.getR()][current.getC() - 1], tiles);
            detectDownSame(tiles[current.getR()][current.getC() - 1], tiles);
            detectLeftSame(tiles[current.getR()][current.getC() - 1], tiles);
        }else{
            return;
        }
    }
}

void Enemy::detectRightSame(Enemy current ,Enemy **tiles){
    if(current.getC() < 10){
        if(current.getColor() == tiles[current.getR()][current.getC() + 1].getColor()){
            tiles[current.getR()][current.getC()].setSame(true);
            tiles[current.getR()][current.getC() + 1].setSame(true);
            detectUpSame(tiles[current.getR()][current.getC() + 1], tiles);
            detectDownSame(tiles[current.getR()][current.getC() + 1], tiles);
            detectRightSame(tiles[current.getR()][current.getC() + 1], tiles);
        }else{
            return;
        }
    }
}

void Enemy::detectDownSame(Enemy current ,Enemy **tiles){
    if(current.getR() < 10){
        if(current.getColor() == tiles[current.getR() + 1][current.getC()].getColor()){
            tiles[current.getR()][current.getC()].setSame(true);
            tiles[current.getR() + 1][current.getC()].setSame(true);
            detectDownSame(tiles[current.getR() + 1][current.getC()], tiles);
        }else{
            return;
        }
    }
}

int Enemy::detectSame(Enemy current ,Enemy **tiles){
    int same = 0;
    detectUpSame(current ,tiles);
    detectLeftSame(current ,tiles);
    detectRightSame(current ,tiles);

    for(int r = 0; r < 10; r++){
        for(int c = 0; c < 10; c++){
            if(tiles[r][c].getSame() == true){
                same++;
            }
        }
    }

    return same;
}   


void Enemy::destroySame(Enemy **tiles, int &_score, int same){
    bool sound = false;
    if(same > 2){
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 10; c++){
                if(tiles[r][c].getSame() == true){
                    tiles[r][c].destroy();
                    _score += 10;
                    if(sound == false){
                        Beep(250,100);
                        Beep(350,100);
                        Beep(450,100);
                        sound = true;
                    }
                }
            }
        }
    }else{
        for(int r = 0; r < 10; r++){
            for(int c = 0; c < 10; c++){
                tiles[r][c].setSame(false);
            }
        }
    }
    
    
}

