#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include "map.h"
#include "player.h"

using namespace std;

int main(){
    Player p = Player(3,5);
    char map_digits[] = {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ','#',' ','#',' ',' ',' ',' ',
        ' ',' ',' ','#',' ',' ',' ',' ',' ',
        ' ',' ','#',' ','#',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ','P',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' '
    };
    Map map(9,9,(char*) map_digits);
    map.print();
    auto points = p.PlayerVision(map,100,20);
    
    for(auto point : points){
        cout<<"Point: "<< point.x<< " "<< point.y<<endl;
    }
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