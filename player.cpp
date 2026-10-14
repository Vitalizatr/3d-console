#include "player.h"
using namespace std;


Player::Player(int x,int y){
    Playerx = x;
    Playery = y;
}
vector<Point> Player::PlayerVision(Map map,int fov,int deg){
    int curY = Playery;
    int curX = Playerx;
    
    int halfFov = fov / 2;

    int cols = map.c();
    const char* data = map.d();
    vector<Point> points;
    
    for(int degree = -halfFov; degree <= halfFov;degree+=fov/deg){
        for(int i = 1; i < curY;i++){
            float d = (tan(degree*M_PI/180)*(i));
            int shit = (int) d;

            if(data[(curY-i)*cols+curX+shit] == '#') {
                Point point = {curX+d,(float)curY-i};
                points.push_back(point);
                break;
            }

        }
    }
    return points;
} 

