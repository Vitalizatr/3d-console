#include <iostream>

using namespace std;
void printReverse(vector<string> strings){
    for(int i =0; i < strings[0].length();i++){
        for(int j = 0; j < strings.size();j++){
            cout<<strings[j][i];
        }
        cout<<endl;
    }
}
int main(){
    vector<string> res;
    for(int i = 0; i<100;i++){
        string cur = "   #   ";
        res.push_back(cur);
    }
    printReverse(res);
}
