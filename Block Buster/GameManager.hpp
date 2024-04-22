#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Bullet.hpp"
#include "Cannon.hpp"
#include "Enemy.hpp"
#include "Block.hpp"

class GameManager
{
private:
    bool checkCross = false;

public:
    GameManager();
    ~GameManager();

    bool getCross() const;
    void setCross(bool cross);

    void startGame();
    void endGame();
    void instruction();

    void drawBoard(int _score, int _bulletleft, int _bulletshot);
    void drawTile(Enemy **enemy);
    void clearTile(Enemy **enemy);
    void reload(Bullet bullet[], Cannon cannon);
    bool checkLose(Enemy **tiles, int bulletRemain, int _score);
    void replace(Enemy **tiles, Bullet bullet[]);
};

#endif