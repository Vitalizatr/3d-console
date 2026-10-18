#pragma once
#include <vector>
class Camera{
    private:
        int height;
        
    public:
    Camera(int h);
    void Vision(std::vector<int> cols);
};