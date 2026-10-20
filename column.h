#pragma once
#include <vector>
#include <map>
class Camera{
    private:
        int height;
    public:
    Camera(int h);
    void PrintVision(std::vector<std::vector<int>> cols,int width,std::map<int, std::string> numToGrad);
    void Vision(std::vector<float> points,int width,std::map<int, std::string> numToGrad);
};