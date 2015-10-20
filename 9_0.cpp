//
//  9_0.cpp
//  
//
//  Created by Pengyan Qin on 7/9/15.
//
//

// problem : whether there is a path from (0,0) to (N-1, N-1), if it exits, print it out
// using backtracking to solve maze problem (M[N][N])

// only find one path and print it out, not all pathes

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void print(int *M, int N){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cout << *(M + i*N + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_safe(int *M, int N, int x, int y){
    if((x >= 0 && x < N) && (y >= 0 && y < N) && (*(M + x*N + y) == 1))
        return true;
    return false;
}

bool SolveMaze(int *M, int N, int x, int y, int *sol){
    if((x == N-1) && (y == N-1)){  // base case
        *(sol + x*N + y) = 1;
        print(sol, N);
        return true;
    }
    
    if(is_safe(M, N, x, y)){
         *(sol + x*N + y) = 1;
        if(SolveMaze(M, N, x+1, y, sol))  // Down
            return true;
        if(SolveMaze(M, N, x, y+1, sol))  // Right
            return true;
        if(SolveMaze(M, N, x-1, y, sol))  // Up
            return true;
        if(SolveMaze(M, N, x, y-1, sol))  // Left
            return true;
        *(sol + x*N + y) = 0;   // backtracking
        return false;
    }
    else
        return false;
}

int main(){
    ifstream fin;
    string filename = "9_0.in";
    fin.open(filename.c_str());
    
    if(!fin.is_open()){
        cout << "open failed" << endl;
        exit(1);
    }
    
    int N = 0;
    fin >> N;
    cout << N << endl;
    int *M = new int[N*N];
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            fin >> *(M + i*N + j);
    
    print(M, N);
    
    int *sol = new int[N*N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            *(sol + i*N + j) = 0; //initialization
    
    cout << SolveMaze(M, N, 0, 0, sol) << endl;
}


