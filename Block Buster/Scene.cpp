#include <graphics.h>
#include <string.h>
#include "Scene.hpp"

using namespace std;

Scene::Scene() : start(260, 400, "START"), exit(260, 533, "EXIT"), replay(260, 400, "REPLAY"), arrow(200, 400){}
Scene::~Scene(){}

void Scene::mainMenu(){
    title();
    start.draw();
    exit.undraw();
    arrow.draw();

    setcolor(15);
    string text = "Press Z to select";
    outtextxy(500, 700, (char*)text.c_str());
}

void Scene::endMenu(int _score){
    showScore(_score);
    replay.draw();
    exit.undraw();
    arrow.draw();

    setcolor(15);
    string text = "Press Z to select";
    outtextxy(500, 700, (char*)text.c_str());
}

void Scene::showScore(int _score){
    string text = "YOUR SCORES: " + to_string(_score);
    setcolor(15);
    settextstyle(3, HORIZ_DIR, 9);
    outtextxy(50, 120, (char*)text.c_str());
}

void Scene::title(){
    string text = "BLOCK BUSTER";
    setcolor(15);
    settextstyle(10, HORIZ_DIR, 9);
    outtextxy(166, 133, (char*)text.c_str());
}