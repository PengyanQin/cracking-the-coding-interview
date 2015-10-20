//
//  9_9.cpp
//  
//
//  Created by Pengyan Qin on 7/13/15.
//
//

#include <iostream>
#include <cmath>
using namespace std;

void print(int A[], int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(A[i] == j)
                cout << "1" << " ";
            else
                cout << "0" << " ";
        
        }
        cout << endl;
    }
    return;
}
void queen(int n, int A[], int m, int &cnt){
    if(m == n){
        cnt++;
        cout << "cnt = " << cnt << endl;
        print(A, n);
        return;
    }
    for(int i = 0; i < n; ++i){ // try each column for row m
          A[m] = i;
          int ok = 1;
          for(int j = 0; j < m ; ++j){ // filter the column not meet the requirements
              if(A[j] == A[m] || abs(i - A[j]) == abs(m - j)){
                  ok = 0;
                  break;
              }
          }
          if(ok)
              queen(n, A, m+1, cnt);
    }
}

int main(){
    int n = 4;
    int cnt = 0;
    int A[4] = {};
    queen(n, A, 0, cnt);
    cout << "total way: " << cnt << endl;

}

