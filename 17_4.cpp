//
//  17_4.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>
#include <climits>

using namespace std;

// n is positive or zero, 0
// n is negative, 1
int sign(int n){
    return (n >> 31) & 1;
}

// a >= 0, b < 0, k = 0
// a < 0, b >= 0, k = 1
int max(int a, int b){
    int z = a - b;
    int k = sign(z); //z >= 0, k = 0; z < 0, k = 1
    return a - z*k;
}

int main(){
    int a1 = 10, b1 = 15;
    int a2 = 20, b2 = 13;
    cout << INT_MAX << endl;
    cout << max(a1, b1) << endl;
    cout << max(a2, b2) << endl;
}

