#ifndef CANNON_H
#define CANNON_H

class Cannon
{
    private:
    int x, y, color, r, c;

    public:
    Cannon(int _x, int _y, int _color, int _r, int _c);
    ~Cannon();

    int getX();
    int getY();
    int getColor();
    int getR();
    int getC();
    
    void setX(int x);
    void setY(int y);
    void setColor(int _color);
    void setR(int _r);
    void setC(int _c);
    
    void setPosition(int _x, int _y);
    void setTilePosition(int _r, int _c);

    void _draw(int _color);
    void draw();
    void undraw();
    
    void moveLeft();
    void moveRight();

};

#endif