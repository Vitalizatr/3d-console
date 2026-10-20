#include "player.h"
#include "map.h"
#include <iostream>
using namespace std;

bool NotOutOfBounds(float x,float y,int cols,int rows){
    return (x >= 0 and x < cols and y >= 0 and y < rows);
}
Player::Player(int x,int y,int d,Map m){
    PlayerX = x;
    PlayerY = y;
    direction = d;
    map = m;
}
vector<float> Player::PlayerVision(float fov,double deg){
    
    vector<float> points;
    int dir = direction*90;
    float halfFov = fov / 2;
    int cols = map.c(); 
    int rows = map.r();
    const char* data = map.d();
    for(double degree = dir-halfFov; degree <= dir+halfFov;degree+=(double)fov/(double)deg){
        float stepX = cos(degree*M_PI/180);
        float stepY = sin(degree*M_PI/180);
        float curX = PlayerX + 0.5;
        float curY = PlayerY + 0.5;
        
        bool hit = false;
        while(NotOutOfBounds(curX,curY,cols,rows)){
            curX+=stepX/100;
            curY+=stepY/100;

            if(data[(int)curY*cols+(int)curX] == '#'){
                float x = (float)PlayerX-curX+0.5;
                float y = (float)PlayerY-curY+0.5;
                float point = sqrt(x*x+y*y) * cos((degree-dir)*M_PI/180);
                hit = true;
                points.push_back(point);
                break;
            }

            
        }
        if(!hit){
            points.push_back(-1);
        }
    }
    return points;
} 
void Player::Adddirection(int addDirection){
    direction+=addDirection;
}
void Player::StepForward(){
    int curX = PlayerX;
    int curY = PlayerY;
    switch (direction%4){
        case 0:
            curX++;
            break;
        case 1: case -3:
            curY++;
            break;
        case 2: case -2:
            curX--;
            break;
        case 3: case -1:
            curY--;
            break;
    }
    int cols = map.c(); 
    int rows = map.r();
    auto data = map.d();
    if(NotOutOfBounds(curX,curY,cols,rows) and data[curY*cols+curX] != '#'){
        PlayerX = curX;
        PlayerY = curY;
    }
}
