//
//  18_1.cpp
//  
//
//  Created by Pengyan Qin on 7/22/15.
//
//

#include <iostream>

using namespace std;

// using bit manipulation
int sum_fnc(int a, int b){
    if(b == 0)
        return a;
    int sum = a^b;
    int carry = (a&b)<<1;
    return sum_fnc(sum, carry);
}

// take advantage of array
// does not work, but logically right
int sum_fnc1(int a, int b){
    char *c = (char*)a;
    return (int)&c[b]; // c+sizeof(char)*b=a + b
}

int main(){
    int a = 13;
    int b = 9;
    cout << sum_fnc(a, b) << endl;

}
