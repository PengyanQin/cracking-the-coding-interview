//
//  9_2_1.cpp
//  
//
//  Created by Pengyan Qin on 7/11/15.
//
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// 0 is off limits and 1 is valid step
// recursive function, using matrix to store the path
void print(int *matrix, int X, int Y){
    for(int i = 0 ; i <= X; ++i){
        for(int j = 0; j <= Y; ++j){
            cout << *(matrix + i*X + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void matrix_init(int *matrix, int X, int Y){
    for(int i = 0 ; i <= X; ++i){
        for(int j = 0; j <= Y; ++j){
            *(matrix + i*X + j) = 0;
        }
    }
}

bool is_safe(int *matrix, int x, int y, int X, int Y){
    if((x <= X && x >= 0) && (y <= Y && y >= 0) && *(matrix + x*X + y) == 1)
        return true;
    return false;
}

bool get_path(int *matrix,int x, int y, int X, int Y, int *path){
    if(x == X && y == Y){
        *(path + x*X + y) = 1;
        return true;
    }
    if(is_safe(matrix, x, y, X, Y)){
        *(path + x*X + y) = 1;
        if(get_path(matrix, x + 1, y, X, Y, path)) // move down
            return true;
        if(get_path(matrix, x, y + 1, X, Y, path)) // move right
            return true;
        *(path + x*X + y) = 0; // backtracking
        return false;
    }
    else
        return false;
}

void get_all_path(int *matrix,int x, int y, int X, int Y, int *path){
    if(x == X && y == Y){
        *(path + x*X + y) = 1;
        print(path, X, Y);
        *(path + x*X + y) = 0;
        return;
    }
    if(is_safe(matrix, x, y, X, Y)){
        *(path + x*X + y) = 1;
        get_all_path(matrix, x + 1, y, X, Y, path); // move down
        get_all_path(matrix, x, y + 1, X, Y, path); // move right
        *(path + x*X + y) = 0;
        return;
    }
    else
        return;
}

int main(){
    ifstream fin;
    string filename = "9_2_1.in";
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open" << endl;
        exit(1);
    }
    
    int X, Y;  // X, Y is the index of last square, not the number of columns and rows
    fin >> X >> Y;
    
    int *matrix  = new int[(X+1)*(Y+1)]; // should be the number of columns and rows
    int *sol = new int[(X+1)*(Y+1)];
    
    for(int i = 0 ; i <= X; ++i){
        for(int j = 0; j <= Y; ++j){
            fin >> *(matrix + i*X + j);
        }
    }
    matrix_init(sol, X, Y);
    cout << "maze: " << endl;
    print(matrix, X, Y);
    cout << "sol matrix: " << endl;
    print(sol, X, Y);
    /*
    cout << get_path(matrix, 0, 0, X, Y, sol) << endl;
    print(sol, X, Y);
     */
    get_all_path(matrix, 0, 0, X, Y, sol);
    
}

