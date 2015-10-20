//
//  17_2_1.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>

using namespace std;

bool is_won(int *A, int n){
    // check each row
    for(int i = 0; i < n; ++i){
        cout << "row " << i << endl;
        bool allsame = true;
        int check = 0;
        for(int j = 0; j < n; ++j){
            if(j == 0)
                check = *(A + i*n + j);
            if(check != *(A + i*n + j)){
                allsame = false;
                break;
            }
        }
        if(allsame)
            return true;
    }
    // check each column
    for(int i = 0; i < n; ++i){
        cout << "column " << i << endl;
        bool allsame = true;
        int check = 0;
        for(int j = 0; j < n; ++j){
            if(j == 0)
                check = *(A + j*n + i);
            if(check != *(A + j*n + i)){
                allsame = false;
                break;
            }
        }
        if(allsame)
            return true;
    }
    // check diagonal line
    bool diagonal = true;
    int check = 0;
    for(int i = 0; i < n; ++i){
        cout << "diagonal " << i << endl;
        if(i == 0)
            check = *(A + i*n + i);
        if(check != *(A + i*n + i)){
            diagonal = false;
            break;
        }
    }
    if(diagonal)
        return true;
    // check reverse-diagonal line
    bool rediagonal = true;
    for(int i = 0; i < n; ++i){
         cout << "rediagonal " << i << endl;
        if(i == 0)
            check = *(A + i*n + n - 1 - i);
        if(check != *(A + i*n + n - 1 - i)){
            rediagonal = false;
            break;
        }
    }
    if(rediagonal)
        return true;
    
    return false;

}

int main(){
    int A[][5] = {{0, 1, 1, 0, 1},
                  {1, 1, 1, 0, 1},
                  {1, 0, 0, 1, 1},
                  {1, 0, 0, 0, 0},
                  {1, 0, 0, 1, 0}};
    int n = 5;
    int B[][5] = {{0, 1, 1, 1, 1},
                  {1, 0, 1, 1, 1},
                  {1, 0, 0, 1, 1},
                  {0, 1, 1, 1, 0},
                  {1, 0, 0, 1, 0}};

    cout << is_won((int*)A, n) << endl;
   cout << is_won((int*)B, n) << endl;
}

