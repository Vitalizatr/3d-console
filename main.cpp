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
int normalize(int num,int start,int end){
    if(num < start) return start;
    if(num > end) return end;
    return num;
}
int main(){
    Player p = Player(3,6);
    char map_digits[] = {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ','#',' ','#',' ',' ',' ',' ',
        ' ',' ',' ','#',' ',' ',' ',' ',' ',
        ' ',' ','#',' ','#',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' '
    };
    Map mapa(9,9,(char*) map_digits);
    auto points = p.PlayerVision(mapa,140,60);
    const int h = 40;
    int maxY =0;
    vector<vector<int>> cols;
    for (auto point : points){
        int rY = round(point.y*10);
        if(rY > maxY) maxY =rY;
    }
    for(auto point : points){
        if(point.y == 0){
            vector<int> nums;
            for (size_t i = 0; i < h; i++)
            {

                nums.push_back(0);
            }
            cols.push_back(nums);
            continue;
        }
        vector<int> nums;

        int k =0;
        int p = round(h/point.y);
        for(int i = 0; i < p/2;i++){
            k++;
            nums.push_back(0);
        }
        for(int i = 0; i < p;i++){
            k++;
            int rY = round(point.y*10);
            nums.push_back(normalize(maxY-rY+1,0,10));
        }
        while(k<h){
            k++;
            nums.push_back(0);
        }
        cols.push_back(nums);

    }

    map<int, string> nToG = {
        {0,  " "},   {1,  "."},
        {2,  ":"},   {3,  "-"},
        {4,  "="},   {5,  "+"},   
        {6,  "*"},   {7,  "░"},
        {8,  "▒"},   {9,  "▓"},
        {10, "█"}  
    };
    Camera camera = Camera(h,points.size(),nToG);
    camera.Vision(cols);
    /*

    int i = 0;
    auto now = chrono::steady_clock::now();
    while (true) {
        auto curtime = chrono::steady_clock::now();
        chrono::milliseconds diff = chrono::duration_cast<chrono::milliseconds>(curtime - now);
        if (diff.count() >= 33) {
            now = chrono::steady_clock::now();

            cout<<i<<endl;
            i++;
        }
        
    }
    */
    
    
    
    return 0;
}