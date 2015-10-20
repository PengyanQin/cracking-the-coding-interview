//
//  5_4.cpp
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

// using XOR
int numofbits(int a, int b){
    int res = a^b;
    int count = 0;
    int bit = 0;
    while(bit < 32){
        if(res & 1)
            count++;
        res >>= 1;
        bit++;
    }
    return count;
}

// compare bit by bit
int numofbits1(int a, int b){
    int count = 0;
    int bit = 0;
    while(bit < 32){
        if((a&1) != (b&1))
            count++;
        a >>= 1;
        b >>= 1;
        bit++;
    }
    return count;
}

int main(){
    int a = 32;
    print(a);
    int b = 24;
    print(b);
    cout << numofbits(a, b) << endl;
    cout << numofbits1(a, b) << endl;
}
