//
//  18_12.cpp
//  
//
//  Created by Pengyan Qin on 7/28/15.
//
//

#include <iostream>
#include <fstream>
using namespace std;

//time complexity: O(n^3)
//p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j]
int* pre_processing(int* A, int n){
    int *p = new int[(n+1)*(n+1)];
    for(int i = 0; i < n+1; ++i)
        *(p + i) = *(p + i * (n+1)) = 0;
    for(int i = 1; i < n+1; ++i){
        for(int j = 1; j < n+1; ++j)
            *(p + i*(n+1) + j) = *(p + (i-1)*(n+1) + j) + *(p + i*(n+1) + j-1) - *(p + (i-1)*(n+1) + j-1) + *(A + i*(n+1) + j);
    }
    return p;
}

// area(column k, rows i through j, included) = p[j][k] - p[i-1][k] - p[j][k-1] + p[i-1][k-1]
int max_sum1(int* A, int n){
    int *p = pre_processing(A, n);
    for(int i = 0; i < n+1; ++i){
        for(int j = 0; j < n+1; ++j){
            cout << *(p + i *(n+1) + j) << " ";
        }
        cout << endl;
    }
    int max_sum = 0;
    for(int i = 1; i < n + 1; ++i){
        for(int j = i ; j < n + 1; ++j){
            int cur_sum = 0;
            for(int k = 1; k < n + 1; ++k){
                cur_sum +=  *(p + j*(n+1) + k) - *(p + (i-1)*(n+1) + k) - *(p + j*(n+1) + k-1) + *(p + (i-1)*(n+1) + k-1); // right part is the sum of rows i, i+1, i+2, ..., j, column k
                if(cur_sum < 0)
                    cur_sum = 0;
                if(cur_sum > max_sum)
                    max_sum = cur_sum;
            }
        }
    }
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
    int *A = new int[(n+1)*(n+1)];
    for(int i = 0; i < n+1; ++i)
        *(A + i) = *(A + i*(n + 1)) = 0;
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            fin >> *(A + i*(n+1) + j);
        }
    }
    
    cout << max_sum1(A, n) << endl;

    // simplified version of contimuous largest sum in an array
    int B[] = {3, -2, -5, 6};
    int nn = 4;
    int cur = 0;
    int max = 0;
    for(int i = 0; i < nn; ++i){
        cur += B[i];
        if(cur < 0)
            cur = 0;
        if(cur > max)
            max = cur;
    }
    cout << max << endl;

}
