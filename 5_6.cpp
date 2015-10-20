//
//  5_5.cpp
//  
//
//  Created by Pengyan Qin on 7/3/15.
//
//

#include <iostream>
#include <vector>

using namespace std;

void print(int n){
    vector<int> v;
    int count = 0;
    while(count < 32){
        if(n & 1)
            v.push_back(1);
        else
            v.push_back(0);
        count++;
        n >>= 1;
    }
    while(!v.empty()){
        cout << v.back();
        v.pop_back();
    }
    cout << endl;
}

int swap_bit(int a){
    int odd = 0xaaaaaaaa & a;
    int even = 0x55555555 & a;
    return (odd >> 1) | (even << 1);
}

int main(){
    int a = 14;
    int swap_a = swap_bit(a);
    print(a);
    print(swap_a);
}

