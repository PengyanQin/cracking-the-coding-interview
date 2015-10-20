//
//  5_7.cpp
//  
//
//  Created by Pengyan Qin on 7/3/15.
//
//

#include <iostream>
#include <unordered_map>

using namespace std;

int fetch(int a[], int i, int j){
    return (a[i]>>j)&1;
}

int get_val(int a[], int i){
    int res = 0;
    for(int j = 31; j >= 0; --j){
        res = (res<<1) | fetch(a, i, j);
    }
    return res;
}

// compare each number, but the sequence must in order
int missing_num(int a[], int n){
    for(int i = 0; i <= n; ++i){
        if(i != get_val(a, i))
            return i;
    }
    return -1;
}

// only focus on the last bit, but the sequence must in order
int missing_num1(int a[], int n){
    for(int i = 0; i <= n; ++i){
        if(i%2 != fetch(a, i, 0))
            return i;
    }
    return -1;
}

// the sequence can be out of order with the help of unordered_map
int missing_num2(int a[], int n){x
    unordered_map<int, bool> map;
    for(int i = 0; i < n; ++i){
        map[get_val(a, i)] = true;
    }
    for(int i = 0; i <= n; ++i){
        if(!map[i])
            return i;
    }
    return -1;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    cout << missing_num2(a, n) << endl;
}

