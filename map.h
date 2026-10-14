#pragma once
class Map {
private:
    char* data;
    int rows;
    int cols;

public:
    Map(int r, int c, char* initial_data);

    void print() const;
    int r() const { return rows; }
    int c() const { return cols; }
    
    const char* d() const { return data; } 

};