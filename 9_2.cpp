//
//  9_2.cpp
//  
//
//  Created by Pengyan Qin on 7/9/15.
//
//

#include <iostream>
using namespace std;

void count_ways(int x, int y, int X, int Y, int &count){
    if((x == X) && (y == Y)){
        count++;
        return;
    }
    if(x > X || y > Y)
        return;
    count_ways(x+1, y, X, Y, count); // move down
    count_ways(x, y+1, X, Y, count); // move right
}

int main(){
    int X = 2;  //(0, 1, 2)
    int Y = 3;  //(0, 1, 2, 3)
    int count = 0;
    count_ways(0, 0, X, Y, count);
    cout << count << endl;
}
