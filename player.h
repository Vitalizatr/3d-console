#pragma once
#include "map.h"
#include <vector>


class Player{
    private:
        int PlayerX;
        int PlayerY;
        int direction;
        Map map;
    public:
    Player(int x,int y,int d,Map m);
    std::vector<float> PlayerVision(float fov,double deg);
    void Adddirection(int addDirection);
    void StepForward();
};
