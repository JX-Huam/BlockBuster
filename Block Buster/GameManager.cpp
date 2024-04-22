#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>

#include "GameManager.hpp"

using namespace std;

GameManager::GameManager(){}
GameManager::~GameManager(){}

bool GameManager::getCross() const {return checkCross;}
void GameManager::setCross(bool cross) {checkCross = cross;}

void GameManager::drawBoard(int _score, int _bulletleft, int _bulletshot)
{
    setcolor(15);
    rectangle(50,85,605,750);
    rectangle(645,85,975,220);
    rectangle(645,230,975,628);
    rectangle(645,638,975,750);

    line(50,638,605,638);

    int x = 650;
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);

    string text = "Score: " + to_string(_score);
    outtextxy(x, 95, (char*)text.c_str());

    text = "Bullet remaining: " + to_string(_bulletleft);
    outtextxy(x, 145, (char*)text.c_str());

    text = "Line drop after " + to_string(5 - _bulletshot) + " shots";
    outtextxy(x, 195, (char*)text.c_str());

    instruction();

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);

    text = "Bullets reload later:";
    outtextxy(x, 645, (char*)text.c_str());
}

void GameManager::drawTile(Enemy **enemy){
    for(int r = 0; r < 11; r++){
        for(int c = 0; c < 10; c++){
            enemy[r][c].draw();
        }
    }
}

void GameManager::clearTile(Enemy **enemy){
    for(int r = 0; r < 11; r++){
        for(int c = 0; c < 10; c++){
            enemy[r][c].undraw();
        }
    }
}


void GameManager::reload(Bullet bullet[], Cannon cannon){
    int size = 4;
    for(int i = 0; i < size; i++){
        if(i == 0){
            bullet[i] = bullet[i + 1];
            bullet[i].setPosition(cannon.getX(), cannon.getY() - 55);
            bullet[i].setTilePosition(cannon.getR() - 1, cannon.getC());
        }
        else if(i == 3){
            bullet[i] = bullet[i].create();
        }
        else if(i == 2){
            bullet[i] = bullet[i + 1];
            bullet[i].setPosition(bullet[i].getX() - 55, bullet[i].getY());
        }
        else if(i == 1){
            bullet[i] = bullet[i + 1];
            bullet[i].setPosition(bullet[i].getX() - 55, bullet[i].getY());
        }
        
    }
}

bool GameManager::checkLose(Enemy **tiles, int bulletRemain, int _score){
    for(int col = 0; col < 10; col++){
        if(tiles[10][col].getColor() != BLACK){
            setCross(true);
            break;
        }else{
            setCross(false);
        }
    }

    if(bulletRemain == 0){
        return true;
    }else if(checkCross == true){
        return true;    
    }else{
        return false;
    }
}

void GameManager::replace(Enemy **tiles, Bullet bullet[]){
    tiles[bullet[0].getR()][bullet[0].getC()].setPosition(bullet[0].getX(), bullet[0].getY());
    tiles[bullet[0].getR()][bullet[0].getC()].setColor(bullet[0].getColor());
    tiles[bullet[0].getR()][bullet[0].getC()].setTilePosition(bullet[0].getR(), bullet[0].getC());
    tiles[bullet[0].getR()][bullet[0].getC()].setValid(bullet[0].getValid());
}

void GameManager::instruction(){
    int x = 650;

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);

    string text = "How to play:";
    outtextxy(x, 235, (char*)text.c_str());

    text = "Press left right button to";
    outtextxy(x, 255, (char*)text.c_str());

    text = "move the cannon";
    outtextxy(x, 275, (char*)text.c_str());

    text = "Press spacebar to shoot";
    outtextxy(x, 305, (char*)text.c_str());

    text = "the bullet";
    outtextxy(x, 325, (char*)text.c_str());

    text = "If 2 or more enemy are";
    outtextxy(x, 355, (char*)text.c_str());

    text = "same colour with bullet,";
    outtextxy(x, 375, (char*)text.c_str());

    text = "all of them will";
    outtextxy(x, 395, (char*)text.c_str());

    text = "be destroyed";
    outtextxy(x, 415, (char*)text.c_str());

    text = "Each destroyed block and";
    outtextxy(x, 445, (char*)text.c_str());

    text = "bullet will gives 10 scores";
    outtextxy(x, 465, (char*)text.c_str());

}
