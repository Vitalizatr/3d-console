#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <locale>
#include "map.h"
#include "player.h"
#include "column.h"

using namespace std;
int main(){
    cout << "Полоса загрузки: ██████▒▒▒▒" << std::endl;
    Player p = Player(3,6);
    char map_digits[] = {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ','#',' ','#',' ',' ',' ',' ',
        ' ',' ',' ','#',' ',' ',' ',' ',' ',
        ' ',' ','#',' ','#',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ','P',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' '
    };
    Map map(9,9,(char*) map_digits);
    map.print();
    auto points = p.PlayerVision(map,140,40);
    const int h = 30;

    vector<int> cols;

    for(auto point : points){
        if(point.y == 0){
            for (size_t i = 0; i < h; i++)
            {
                cols.push_back(0);
            }
            continue;
        }
        int k =0;
        int p = round(h/point.y);
        for(int i = 0; i < p/2;i++){
            k++;
            cols.push_back(0);
        }
        for(int i = 0; i < p;i++){
            k++;
            if(point.y<1.5) cols.push_back(4);
            else if(point.y < 2.5) cols.push_back(3);
            else if(point.y < 3.5) cols.push_back(2);
            else cols.push_back(1);
        }
        while(k<=h){
            k++;
            cols.push_back(0);
        }
    }
    Camera camera = Camera(50);
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