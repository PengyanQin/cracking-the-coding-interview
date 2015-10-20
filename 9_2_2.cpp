//
//  9_2_2.cpp
//  
//
//  Created by Pengyan Qin on 7/11/15.
//
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// 0 is off limits and 1 is valid step
// recursive function, using stack and point to store the path

struct point{
    int x, y;
    point() {}
    point(int x_, int y_):x(x_), y(y_) {}
};

void print(int *matrix, int X, int Y){
    for(int i = 0 ; i <= X; ++i){
        for(int j = 0; j <= Y; ++j){
            cout << *(matrix + i*X + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_safe(int *matrix, int x, int y, int X, int Y){
    if((x <= X && x >= 0) && (y <= Y && y >= 0) && *(matrix + x*X + y) == 1)
        return true;
    return false;
}

bool get_path(int *matrix, int x, int y, int X, int Y, vector<point> &vec){
    if(x == X && y == Y){
        vec.push_back(point(x, y));
        return true;
    }
    if(is_safe(matrix, x, y, X, Y)){
        vec.push_back(point(x, y));
        if(get_path(matrix, x + 1, y, X, Y, vec)) // move down
            return true;
        if(get_path(matrix, x, y + 1, X, Y, vec)) // move right
            return true;
        vec.pop_back();
        return false;
    }
    else
        return false;
}

void get_all_path(int* matrix, int x, int y, int X, int Y, vector<point> &vec){
    if(x == X && y == Y){
        vec.push_back(point(x, y));
        for(int i = 0; i < vec.size(); ++i )
            cout << "(" << vec[i].x << "," << vec[i].y << ") ";
        cout << endl;
        vec.pop_back();
        return;
    }
    if(is_safe(matrix, x, y, X, Y)){
        vec.push_back(point(x, y));
        get_all_path(matrix, x + 1, y, X, Y, vec); // move down
        get_all_path(matrix, x, y + 1, X, Y, vec); // move right
        vec.pop_back();
    }
}

int main(){
    ifstream fin;
    string filename = "get_all_path(int* matrix, int x, int y, int X, int Y, vector<point> &vec).in";
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open" << endl;
        exit(1);
    }
    
    int X, Y;  // X, Y is the index of last square, not the number of columns and rows
    fin >> X >> Y;
    
    int *matrix  = new int[(X+1)*(Y+1)]; // should be the number of columns and rows
    vector<point> vec;
    for(int i = 0 ; i <= X; ++i){
        for(int j = 0; j <= Y; ++j){
            fin >> *(matrix + i*X + j);
        }
    }
    cout << "maze: " << endl;
    print(matrix, X, Y);
    /*
    cout << get_path(matrix, 0, 0, X, Y, vec) << endl;
    for(int i = 0; i < vec.size(); ++i )
        cout << "(" << vec[i].x << "," << vec[i].y << ") ";
    cout << endl;
     */
    get_all_path(matrix, 0, 0, X, Y, vec);
    
}

