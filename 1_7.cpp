//
//  1_7.cpp
//  
//
//  Created by Pengyan Qin on 6/15/15.
//
//

#include <iostream>

using namespace std;

// time complexity: O(n^2)
// space complexity: O(2n)

void to_zero(int *matrix, int n){
    int *row = new int[n];   // row[] containes undefined values
    int *col = new int[n];   // col[] containes undefined values
    for(int i = 0; i < n; ++i){
        row[i] = 0;
        col[i] = 0;
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(*(matrix + i*n + j) == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(row[i]){
            for(int j = 0; j < n; ++j)
                *(matrix + i*n + j) = 0;
        }
        if(col[i]){
            for(int j = 0; j < n; ++j)
                *(matrix + j*n + i) = 0;
        
        }
    }
    delete[] row;
    delete[] col;
}

// time complexity: O(n^2)
// space complexity: O(1)
void to_zero1(int *matrix, int m, int n){ // m row, n column
    bool row = false;
    bool col = false;
    
    for(int i = 0; i < n; ++i){  // check the first row
        if(*(matrix + i) == 0)
           row = true;
    }
    
    for(int i = 0; i < m; ++i){  // check the first column
        if(*(matrix + i*n))
            col = true;
    }
    
    for(int i = 1; i < m; ++i){  // check the rest of the matrix
        for(int j = 1; j < n; ++j){
            if(*(matrix + i*n +j) == 0){
                *(matrix + i*n) = 0;
                *(matrix + j) = 0;
            }
        }
    }
    
    for(int i = 0; i < n; ++i){  // set zero for each column
        if(*(matrix + i) == 0){
            for(int j = 0; j < m; ++j)
                *(matrix + j*n + i) = 0;
        }
    }
    
    for(int i = 0; i < m; ++i){  // set zero for each row
        if(*(matrix + i*n) == 0){
            for(int j = 0; j < n; ++j)
                *(matrix + i*n +j) = 0;
        }
    }
    
    if(row){  // set zero for first row
        for(int i = 0; i < n; ++i)
            *(matrix + i) = 0;
    }
    if(col){  // set zero for first column
        for(int i = 0; i < m; ++i)
            *(matrix + i*n) = 0;
    }
    return;
}



int main(){
    int a[5][4] = {{1, 6,  0, 1},
                    {2, 9, 3, 2},
                    {0, 3, 6, 3},
                    {5, 1, 0, 8},
                    {3, 5, 1, 5}};
    int m = 5;
    int n = 4;
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    to_zero1((int*)a, m, n);
    
    cout << "to_zero result: " << endl;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    
}



