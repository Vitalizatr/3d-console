
#include <iostream>
#include <vector>
#include "column.h"
#include <map>
using namespace std;
int normalize(int num,int start,int end){
    if(num < start) return start;
    if(num > end) return end;
    return num;
}
Camera::Camera(int h){
    height = h;
}
void Camera::PrintVision(vector<vector<int>> cols,int width,map<int, string> numToGrad){

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
void Camera::Vision(vector<float> points,int width,map<int, string> numToGrad){
    vector<vector<int>> cols;
    
    int maxY =0;
    for (auto point : points){
        int rY = round(point)*10;
        if(rY > maxY) maxY =rY;
    }
    for(auto point : points){
        if(point == -1){
            vector<int> nums(height, 0);
            cols.push_back(nums);
            continue;
        }
        vector<int> nums;

        int p = height / (round(point*100)/100.0);
        int ceiling = (height - p) / 2;
        int floor = ceiling + p;

        for (int i = 0; i < ceiling; i++) {
            nums.push_back(0);
        }

        for (int i = ceiling; i < floor; i++) {
            int rY = round(point) * 10;
            if (maxY / rY > 5) nums.push_back(normalize(maxY - rY + 1, 0, numToGrad.size() - 1));
            else nums.push_back(normalize(10 - rY / 10, 0, numToGrad.size() - 1));
        }

        for (int i = floor; i < height; i++) {
            nums.push_back(0); 
        }
        
        cols.push_back(nums);
    }
    PrintVision(cols,width,numToGrad);

}