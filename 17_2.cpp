//
//  17_2.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>

using namespace std;

// normal tic-tac-toe(3*3)
bool is_won(int A[][3], int n){
    for(int i = 0; i < n; ++i){
        if(A[i][0] == A[i][1] && A[i][0] == A[i][2]){
            return true;
        }
        if(A[0][i] == A[1][i] && A[0][i] == A[2][i]){
            return true;
        }
    }
    if(A[0][0] == A[1][1] && A[0][0] == A[2][2])
        return true;
    if(A[0][2] == A[1][1] && A[0][2] == A[2][0])
        return true;
    return false;
}

int main(){
    int A[3][3] = {{0, 0, 1},
                   {1, 1, 0},
                   {0, 1, 1}};
    int n = 3;
    int B[3][3] = {{1, 0, 1},
                   {1, 1, 0},
                   {0, 0, 1}};
    
    cout << is_won(A, n) << endl;
    cout << is_won(B, n) << endl;
}


