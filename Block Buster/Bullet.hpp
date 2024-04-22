#ifndef BULLET_H
#define BULLET_H

#include "Block.hpp"
#include "Enemy.hpp"

class Bullet: public Block
{
    private:

    public:
        Bullet(int _x, int _y, int _color, int _r, int _c, bool _valid);
        ~Bullet();

        Bullet create();
        void moveLeft();
        void moveRight();
        void moveUp();
        void checkValid(Enemy **tiles);
};
#endif