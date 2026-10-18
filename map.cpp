#include <iostream>
#include "map.h"
using namespace std;
Map::Map(int r, int c, char* initial_data) {
    rows = r;
    cols = c;
    data = initial_data;
}

void Map::print() const {
    cout<<"Mini Map"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i * cols + j]<<' ';
        }
        cout << endl;
    }
}