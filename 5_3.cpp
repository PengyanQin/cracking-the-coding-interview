//
//  5_3.cpp
//  
//
//  Created by Pengyan Qin on 7/3/15.
//
//

#include <iostream>
#include <vector>

using namespace std;

void print(unsigned int n){
    vector<int> v;
    int remainder = 0;
    int divide = n;
    while(divide){
        remainder = divide%2;
        divide = divide/2;
        if(remainder)
            v.push_back(1);
        else
            v.push_back(0);
    }
    while(!v.empty()){
        cout << v.back();
        v.pop_back();
    }
    cout << endl;
}

// brute force
int numofone(unsigned int n){
    int count = 0;
    int bit = 0;
    while(bit < 32){
        if(n & 1)
            count++;
        bit++;
        n >>= 1;
    }
    return count;
}

int next_smallest1(unsigned int n){
    int count = numofone(n);
    if(!count)
        return -1;
    int ct = 0;
    while(ct != count){
        ct = numofone(++n);
    }
    return n;
}

int next_largest1(int n){
    int count = numofone(n);
    if(!count)
        return -1;
    int ct = 0;
    while(ct != count){
        if(--n < 0)
            return -1;
        else
            ct = numofone(n);

    }
    return n;
}

// bit operation
unsigned int next_smallest(unsigned int n){ // the smallest number among larger ones
    unsigned int tmp = n;
    int fone  = 0;
    while(!(tmp & 1)){
        tmp >>= 1;
        fone++;
    }
    int fzero = fone;
    while(tmp & 1){
        tmp >>= 1;
        fzero++;
    }
    int numofone = fzero - fone - 1;
    n |= (1 << fzero);  // set fzero bit to one
    n &= (-1) << fzero; // clear last bits
    int mask = (1 << numofone) -1 ;
    n |= mask;  // set the last bits
    return n;
}

unsigned int next_largest(unsigned int n){  // the largest number among smaller ones
    unsigned int tmp = n;
    int fzero = 0;
    while(tmp & 1){
        tmp >>= 1;
        fzero++;
    }
    int fone = fzero;
    while(!(tmp & 1)){
        tmp >>= 1;
        fone++;
    }
    int numofone = fzero + 1;
    int numofzero = fone - numofone;
    n &= (-1) << (fone + 1);  // set fone bit to 0
    n |= (1 << fone) - 1; // set the last bits first to 0
    n &= (-1) << numofzero;
    return n;
}

int main(){
    unsigned int n = 1;
    print(n);
    unsigned int s = next_smallest1(n);
    print(s);
    int m = 1;
    print(m);
    unsigned int l = next_largest1(m);
    print(l);


}

