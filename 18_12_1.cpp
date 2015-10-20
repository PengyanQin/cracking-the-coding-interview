//
//  18_12_1.cpp
//  
//
//  Created by Pengyan Qin on 7/29/15.
//
//
#include <iostream>
#include <fstream>
using namespace std;

// brute force
// time complexity: O(n^2)
int mat_sum(int *A, int n, int r, int c){
    int res = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            res += *(A + i*n + j);
        }
    }
    return res;
}

// time complexity: O(n^6)
int max_sum(int *A, int n){
    int max_sum = 0;
    int xx = 0;
    int yy = 0;
    int r = 0;
    int c = 0;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){ // for each point
            for(int li = 1; li <= n - i; ++li){ // how many columns
                for(int lj = 1; lj <= n - j; ++lj){ // how many rows
                    int sub_sum = mat_sum(A + i*n +j, n, li, lj);
                    if(sub_sum > max_sum){
                        xx = i;
                        yy = j;
                        r = li;
                        c = lj;
                        max_sum = sub_sum;
                    }
                }
            }
        }
    }
    cout << "(" << xx << ", " << yy << ")" << endl;
    cout << r << "rows and " << c << "columns" << endl;
    return max_sum;
}

int main(){
    fstream fin;
    string filename = "18_12.in";
    
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open " << endl;
        exit(1);
    }
    int n;
    fin >> n;
    int *A = new int[n*n];
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            fin >> *(A + i*n + j);
        }
    }
    
    cout << max_sum(A, n) << endl;

}
