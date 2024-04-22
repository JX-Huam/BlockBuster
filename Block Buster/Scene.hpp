#ifndef SCENE_H
#define SCENE_H

#include "UiButton.hpp"
#include "UiArrow.hpp"

class Scene
{
public:
    UiButton start, exit, replay;
    UiArrow arrow;

    Scene();
    ~Scene();

    void mainMenu();
    void endMenu(int _score);
    void showScore(int _score);
    void title();
};

#endif