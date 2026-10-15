#include "player.h"
#include <iostream>
using namespace std;


Player::Player(int x,int y){
    Playerx = x;
    Playery = y;
}
vector<Point2D> Player::PlayerVision(Map map,int fov,int deg){
    int curY = Playery;
    int curX = Playerx;
    
    int halfFov = fov / 2;

    int cols = map.c();
    const char* data = map.d();
    vector<Point2D> points;
    
    for(int degree = -halfFov; degree <= halfFov;degree+=fov/deg){
        float i = 0;
        while(i < curY){
            float d = (tan(degree*M_PI/180)*(i));
            int shit = (int) d;

            if(data[(int)((curY-i))*cols+curX+shit] == '#') {
                Point2D point = {d,i};
                points.push_back(point);
                break;
            }
            i+=0.1;
        }
    }
    return points;
} 

