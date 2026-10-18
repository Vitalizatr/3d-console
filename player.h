#pragma once
#include "point.h"
#include "map.h"
#include <vector>


class Player{
    private:
    int Playerx;
    int Playery;
    public:
    Player(int x,int y);
    std::vector<Point2D> PlayerVision(Map map,float fov,double deg);
};
