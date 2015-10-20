//
//  5_1.cpp
//  
//
//  Created by Pengyan Qin on 7/3/15.
//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(int n){
    vector<int> v;
    int len = 8*sizeof(n);
    int mask = 1;
    while(len--){
        if(mask&n)
            v.push_back(1);
        else
            v.push_back(0);
        
        n = n >> 1;
    }
    while(!v.empty()){
        cout << v.back();
        v.pop_back();
    }
    cout << endl;
}

int insert_num(int N, int M, int i, int j){ // insert M into N from i to j
    int mask1 = (-1 << (j+1)) | ((1 << i) - 1); // 1111100001111
    print(mask1);
    N &= mask1;
    print(N);
    M <<= i;
    print(M);
    N = M | N;
    return N;
}

int main(){
    int N = 129274611;
    print(N);
    int M = 35;
    print(M);
    int i = 4;
    int j = 9;
    int res = insert_num(N, M, i, j);
    print(res);
}

// print(~0) and print(-1) is all 1
