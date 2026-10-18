#pragma once
#include <vector>
#include <map>

class Camera{
    private:
        int height;
        int width;
        std::map<int, std::string> numToGrad;
    public:
    Camera(int h,int w, std::map<int, std::string> nToG);
    void Vision(std::vector<std::vector<int>> cols);
};