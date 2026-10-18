#include "player.h"
#include <iostream>
using namespace std;


Player::Player(int x,int y){
    Playerx = x;
    Playery = y;
}
vector<Point2D> Player::PlayerVision(Map map,float fov,double deg){
    int curY = Playery;
    int curX = Playerx;
    
    float halfFov = fov / 2;

    int cols = map.c();
    int rows = map.r();
    const char* data = map.d();
    vector<Point2D> points;
    
    for(double degree = -halfFov; degree <= halfFov;degree+=(double)fov/deg){
        float i = 0;
        while(i < curY){
            float d = (tan(degree*M_PI/180)*(i));
            int shit = (int) d;

            if(data[(int)((curY-i))*cols+curX+shit] == '#' and curX+shit >= 0 and curX+shit < rows) {
                Point2D point = {d,i};
                points.push_back(point);
                break;
            }
            i+=0.1;
        }
        if(i>=curY){

            Point2D point = {0,0};
            points.push_back(point);
        }
    }
    return points;
} 

