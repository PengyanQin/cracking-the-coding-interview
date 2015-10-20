//
//  9_6.cpp
//  
//
//  Created by Pengyan Qin on 7/12/15.
//
//

#include <iostream>
#include <vector>
using namespace std;

const int max_size = 100;
typedef vector< string> vs;

// using recursive function
// 排列（permutation）
void parenthesis_helper(int left, int right, char c[], int n){ // left: (, right: )
    if(left < 0 || left > right)
        return;
    if(left == 0 && right == 0){
        for(int i = 0; i < n; ++i)
            cout << c[i] << " ";
        cout << endl;
        return;
    }
    if(left > 0){
        c[n] = '(';
        parenthesis_helper(left-1, right, c, n+1);
    }
    if(left < right){
        c[n] = ')';
        parenthesis_helper(left, right-1, c, n+1);
    }
}

void parenthesis(int n){
    char c[max_size] = {};
    int left = n;
    int right = n;
    parenthesis_helper(left, right, c, 0);
}


int main(){
    parenthesis(3);
}
