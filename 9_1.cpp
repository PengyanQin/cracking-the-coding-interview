//
//  9_1.cpp
//  
//
//  Created by Pengyan Qin on 7/9/15.
//
//

#include <iostream>

using namespace std;

const int MAX = 100;

// recursive function
int stairs_recursive(int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    return stairs_recursive(n - 1) + stairs_recursive(n - 2) + stairs_recursive(n - 3);
}

// dynamic programming(bottom to top)
int method[MAX] = {0};
int stairs_dp(int n){
    if(n == 0)
        method[n] = 1;
    if(n == 1)
        method[n] = 1;
    if(n == 2)
        method[n] = 2;

    if(method[n] != 0)
        return method[n];
    method[n] = stairs_dp(n-1) + stairs_dp(n-2) + stairs_dp(n-3);
    return method[n];
}

int main(){
    int n = 6;
    
    for(int i = 0; i < 100; ++i)
        cout << method[i] << " ";
    cout << endl;
    
    cout << stairs_recursive(n) << endl;
    cout << stairs_dp(n) << endl;
}
