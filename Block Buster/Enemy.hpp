#ifndef ENEMY_H
#define ENEMY_H

#include "Block.hpp"

class Enemy: public Block
{
    public:
        Enemy();
        Enemy(int _x, int _y, int _color, int _r, int _c, bool _valid);
        ~Enemy();

        void spawnNewLine(Enemy **tiles);
        void drop(Enemy **tiles);
        void detectUpSame(Enemy current, Enemy **tiles);
        void detectLeftSame(Enemy current, Enemy **tiles);
        void detectRightSame(Enemy current, Enemy **tiles);
        void detectDownSame(Enemy current, Enemy **tiles);
        int detectSame(Enemy current, Enemy **tiles);
        void destroySame(Enemy **tiles, int &_score, int same);

};
#endif