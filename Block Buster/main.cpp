#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "GameManager.hpp"
#include "Scene.hpp"

using namespace std;

int main(){
    int width = 1000;
    int height = 800;
    initwindow(width, height, "Block Buster");

    srand(time(NULL));

    Scene scene;

    int open = 1; //make window open
    int start = 1; //switch for start scene
    int end = 0; //switch for end scene
    int choice = 0; //indicate which button currently choose
    char input = 0;
    int score = 0; //calculate player's score

    scene.mainMenu(); //draw out main menu

    while (open == 1)
    {
        while(start == 1)
        {
            if (!kbhit())
                continue;
            input = getch();
            if (input == 27){  // 27 ==ESC key
                open = 0;
                break;
            }


            switch (input)
            {
                case KEY_UP:
                if(choice == 1){
                    choice -= 1;
                    scene.start.draw();
                    scene.exit.undraw();
                    scene.arrow.undraw();
                    scene.arrow.setY(400);
                    scene.arrow.draw();
                }
                break;

                case KEY_DOWN:
                if(choice == 0){
                    choice += 1;
                    scene.start.undraw();
                    scene.exit.draw();
                    scene.arrow.undraw();
                    scene.arrow.setY(533);
                    scene.arrow.draw();
                }
                break;

                case 'z':
                if(choice == 0){
                    cleardevice();

                    int bulletShot = 0; //number of bullets already shot
                    int bulletRemain = 50; //how many bullets remain
                    score = 0; //score

                    //create the objects
                    GameManager gameManager;
                    Cannon cannon(55, 695, WHITE, 11, 0);
                    Enemy enemy(0,0,BLACK,0,0,true);
                    Bullet bullet[4] = {Bullet(cannon.getX(),cannon.getY()-55,rand() % 4 + 1, 10, cannon.getC(),true),
                                        Bullet(800,695,rand() % 4 + 1,10,cannon.getC(),true),
                                        Bullet(855,695,rand() % 4 + 1,10,cannon.getC(),true),
                                        Bullet(910,695,rand() % 4 + 1,10,cannon.getC(),true)};
                    Enemy** tiles = new Enemy*[11];
                    for(int i = 0; i < 11; i++){
                        tiles[i] = new Enemy[10];
                    }

                    gameManager.drawBoard(score, bulletRemain, bulletShot); //draw the game board

                    //set enemies in the tiles and draw them
                    int x = 55, y = 90;
                    for(int row = 0; row < 3; row++){
                        for(int col = 0; col < 10; col++){
                        tiles[row][col] = Enemy(x,y,rand() % 4 + 1,row,col,false);
                            x += 55;
                        }
                        x = 55;
                        y += 55;
                    }
                    x = 55;
                    y = 255;
                    for(int row = 3; row < 11; row++){
                        for(int col = 0; col < 10; col++){
                        tiles[row][col] = Enemy(x,y,BLACK,row,col,true);
                            x += 55;
                        }
                        x = 55;
                        y += 55;
                    }
                    gameManager.drawTile(tiles);

                    //draw the bullets
                    for(int i = 0; i < 4; i++){
                        bullet[i].draw();
                    }

                    char key = 0;

                    while (true)
                    {
                        if (!kbhit())
                            continue;
                        key = getch();
                        if (input == 27){  // 27 ==ESC key
                            open = 0;
                            break;
                        }
                        //check if the player lose or not
                        if(gameManager.checkLose(tiles,bulletRemain,score) == true)
                            break;

                        switch (key)
                        {
                            case KEY_LEFT: //move cannon left
                                cannon.moveLeft();
                                bullet[0].moveLeft();
                                break;

                            case KEY_RIGHT: //move cannon right
                                cannon.moveRight();
                                bullet[0].moveRight();
                                break;
                            
                            case ' ': //shoot bullet
                                bullet[0].checkValid(tiles);
                                while(bullet[0].getValid() == true){
                                    bullet[0].moveUp();
                                    bullet[0].checkValid(tiles);
                                }
                                Beep(150,100);
                                gameManager.replace(tiles, bullet);
                                
                                //detech and destory all same colour block
                                int same = enemy.detectSame(tiles[bullet[0].getR()][bullet[0].getC()], tiles); 
                                enemy.destroySame(tiles, score, same);

                                gameManager.reload(bullet, cannon);

                                bulletShot++;
                                bulletRemain--;
                                //after 5 bullet shot, drop one line
                                if(bulletShot == 5){
                                    enemy.drop(tiles);
                                    enemy.spawnNewLine(tiles);
                                    bulletShot = 0;
                                }

                                //redraw the renew tiles
                                gameManager.clearTile(tiles);
                                gameManager.drawTile(tiles);
                                gameManager.drawBoard(score, bulletRemain, bulletShot); //update scores

                                //redraw bullet after a shot
                                for(int i = 0; i < 4; i++){
                                    bullet[i].draw();
                                }
                                break;
                        }
                    }
                    cleardevice();
                    scene.endMenu(score);
                    start = 0;
                    
                }else{
                    start = 0;
                    open = 0;
                }
                break;
            }
        }
        if(open == 0)
            break;

        end = 1;
        choice = 0;
        while(end == 1)
        {
            if (!kbhit())
                continue;
            input = getch();
            if (input == 27){  // 27 ==ESC key
                open = 0;
                break;
            }

            switch (input)
            {
                case KEY_UP:
                if(choice == 1){
                    choice -= 1;
                    scene.replay.draw();
                    scene.exit.undraw();
                    scene.arrow.undraw();
                    scene.arrow.setY(400);
                    scene.arrow.draw();
                }
                break;

                case KEY_DOWN:
                if(choice == 0){
                    choice += 1;
                    scene.replay.undraw();
                    scene.exit.draw();
                    scene.arrow.undraw();
                    scene.arrow.setY(533);
                    scene.arrow.draw();
                }
                break;

                case 'z':
                if(choice == 0){
                    end = 0;
                    start = 1;
                    cleardevice();

                    setcolor(15);
                    string text = "If black screen, press z to continue";
                    outtextxy(100, 400, (char*)text.c_str());
                    break;
                }else{
                    end = 0;
                    start = 0;
                    open = 0;
                }
                break;
            }
        }
    }
    return 0;
}
