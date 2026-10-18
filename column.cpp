
#include <iostream>
#include <vector>
#include "column.h"
#include <map>
using namespace std;

Camera::Camera(int h,int w,map<int, string> nToG){
    height = h;
    width = w;
    numToGrad = nToG;
}
void Camera::Vision(vector<vector<int>> cols){

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j<  width; j++)
        {
            int num = cols[j][i];
            cout<<numToGrad.at(num);
        }
        cout<<endl;
        
    }
    

    
}
