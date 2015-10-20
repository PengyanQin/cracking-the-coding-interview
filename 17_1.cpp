//
//  17_1.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>

using namespace std;

// pay attention: XOR ^
void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void swap1(int &a, int &b){
    a = a - b;
    b = a + b; // a
    a = b - a;
}

int main(){
    int a = 10;
    int b = 12;
    cout << "before a = " << a << " b = " << b << endl;
    swap1(a, b);
    cout << "after a = " << a << " b = " << b << endl;
}
