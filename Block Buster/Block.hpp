#ifndef BLOCK_H
#define BLOCK_H

class Block
{
protected:
    int x, y;
    int color;
    int r, c;
    bool valid = true;
    bool same = false;

public:
    Block();
    Block(int _x, int _y, int _color, int _r, int _c, bool _valid);
    ~Block();

    int getX() const;
    int getY() const;
    int getColor() const;
    bool getValid() const;
    int getR() const;
    int getC() const;
    bool getSame() const;

    void setX(int _x);
    void setY(int _y);
    void setColor(int _color);
    void setValid(bool _valid);
    void setR(int _r);
    void setC(int _c);
    void setSame(bool _same);

    void setPosition(int _x, int _y);
    void setTilePosition(int _r, int _c);

    void _draw(int _color) const;
    void draw() const;
    void undraw() const;
    void destroy();
};
#endif