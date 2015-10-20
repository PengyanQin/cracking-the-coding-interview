//
//  9_7.cpp
//  
//
//  Created by Pengyan Qin on 7/12/15.
//
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

enum color {red, gre, blu, yel};

void print(color *graph, int m, int n){ // m rows, n columns
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << *(graph + i*n + j) << " ";
        }
        cout << endl;
    }
    return;
}

// only change the surrounding area around the point
// chnage ocolor(the color of the point) to ncolor
void paintfill_helper(color *graph, int m, int n, int x, int y, color ocolor, color ncolor){ // m rows, n columns, (y, x)
    if(x < 0 || x >= n || y < 0 || y >= m)
        return;
    if(*(graph + y*n + x) == ocolor){
        *(graph + y*n + x) = ncolor;
        paintfill_helper(graph, m, n, x - 1, y, ocolor, ncolor); // move left
        paintfill_helper(graph, m, n, x, y + 1, ocolor, ncolor); // move down
        paintfill_helper(graph, m, n, x + 1, y, ocolor, ncolor); // move right
        paintfill_helper(graph, m, n, x, y - 1, ocolor, ncolor); // move up
    }
    return;
}

void paintfill(color *graph, int m, int n, int x, int y, color ncolor){
    if(*(graph + y*n +x) == ncolor)
        return;
    paintfill_helper(graph, m, n, x, y, *(graph + y*n +x), ncolor);
}

// we need a closed new color shape to defined the painted area
// change non ncolor to ncolor
bool paintfill1(color *graph, int m, int n, int x, int y, color ncolor){ // m rows, n columns, (y, x)
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if(*(graph + y*n + x) == ncolor)
        return false;
    else{
        *(graph + y*n + x) = ncolor;
        paintfill1(graph, m, n, x - 1, y, ncolor); // move left
        paintfill1(graph, m, n, x, y + 1, ncolor); // move down
        paintfill1(graph, m, n, x + 1, y, ncolor); // move right
        paintfill1(graph, m, n, x, y - 1, ncolor); // move up
    }
    return true;
}

int main(){
    ifstream fin;
    string filename = "9_7.in";
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open" << endl;
        exit(1);
    }
    
    int m, n;
    fin >> m >> n;
    color *graph = new color[m*n];

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int t;
            fin >> t;
           *(graph + i*n + j) = (color)t;
        }
    }

    print(graph, m, n);
    paintfill1(graph, m, n, 1, 2, red);
    cout << "after paint fill: " << endl;
    print(graph, m, n);
    return 0;
}
    

