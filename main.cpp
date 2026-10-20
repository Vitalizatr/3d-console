#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <locale>
#include <map>
#include "map.h"
#include "player.h"
#include "column.h"

using namespace std;

int main(){
    char map_digits[] = {
        '#','#','#','#','#','#','#','#',' ',
        '#',' ',' ',' ','P',' ','#',' ','#',
        '#','#','#','#',' ','#',' ',' ','#',
        '#',' ','#','#',' ','#','#',' ','#',
        '#',' ','#',' ',' ',' ','#',' ','#',
        '#',' ','#','#','#',' ','#',' ','#',
        '#',' ',' ',' ','#',' ',' ',' ','#',
        '#','#',' ','#',' ',' ','#','#','#',
        '#','#','#','#','#','#','#','#',' ',
    };
    Map mapa(9,9,(char*) map_digits);
    Player p = Player(3,1,0,mapa);
    
    int h = 40;
    map<int, string> nToG = {
        {0,  " "},   {1,  "."},
        {2,  ":"},   {3,  "-"},
        {4,  "="},   {5,  "+"},   
        {6,  "*"},   {7,  "░"},
        {8,  "▒"},   {9,  "▓"},
        {10, "█"}  
    };
    Camera camera = Camera(h);
    
    bool game = true;
    while(game){
        
        auto points = p.PlayerVision(120,100);
        camera.Vision(points,points.size(),nToG);
        char ch;
        cin>>ch;
        if(ch == 'q') {
            game = false;
            break;
        }
        else if(ch == 'd'){
            p.Adddirection(1);
        }
        else if(ch == 'a'){
            p.Adddirection(-1);
        }
        else if(ch == 'w'){
            p.StepForward();
        }
        system("clear");
    }
    
    
    return 0;
}