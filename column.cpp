
#include <iostream>
#include <vector>
#include "column.h"
#include <map>
using namespace std;

Camera::Camera(int h){
    height = h;
}
void Camera::Vision(vector<int> cols){
    const map<int,string> numToGrad = {
        {0," "},
        {1,"░"},
        {2,"▒"},
        {3,"▓"},
        {4,"█"}
    };
}
