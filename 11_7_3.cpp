//
//  11_7_3.cpp
//  
//
//  Created by Pengyan Qin on 7/16/15.
//
//

#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()

using namespace std;

int max_apple(int *A, int m, int n){
    int *B = new int[m*n];
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            *(B + i*n + j) = *(A + i*n +j);
            if(j - 1 >= 0 && *(B + i*n + j - 1) + *(A + i*n +j) > *(B + i*n + j)){ // move left
                *(B + i*n + j) = *(B + i*n + j - 1) + *(A + i*n +j);
            }
            if(i - 1 >= 0 && *(B + (i-1)*n + j) + *(A + i*n +j) > *(B + i*n + j)){ // move up
                *(B + i*n + j) = *(B + (i-1)*n + j) + *(A + i*n +j);
            }
        }
    }
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << *(B + i*n + j) << " ";
        }
        cout << endl;
    }
    
    int res = *(B + (m-1)*n + n-1);
    delete[] B;
    return res;
}

int main(){
    fstream fin;
    string filename = "11_7_3.in";
    
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open " << endl;
        exit(1);
    }
    int m, n;
    fin >> m >> n;
    cout << "m = " << m << " n = " << n << endl;
    int *A = new int[m*n];
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j)
            fin >> *(A + i*n + j);
    }
    
    cout << max_apple(A, m, n) << endl;
}

