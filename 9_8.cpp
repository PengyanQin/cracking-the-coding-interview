//
//  9_8.cpp
//  
//
//  Created by Pengyan Qin on 7/13/15.
//
//

#include <iostream>

using namespace std;
const int max_size = 100;

// 排列(permutation)
void ways(int n, int path[],int m, int &cnt){
    //if(n < 0)
    //    return;
    if(n == 0){
        cnt++;
        for(int i = 0; i < m; ++i)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    if(n >= 25){
        path[m] = 25;
        ways(n-25, path, m+1, cnt);
    }
    if(n >= 10){
        path[m] = 10;
        ways(n-10,path, m+1, cnt);
    }
    if(n >= 5){
        path[m] = 5;
        ways(n-5, path, m+1, cnt);
    }
    if(n >= 1){
        path[m] = 1;
        ways(n-1, path, m+1, cnt);
    }
}

// 组合(combination)
void ways1(int n, int path[], int m, int c, int &cnt){
    if(n < 0)
        return;
    if(n == 0){
        cnt++;
        for(int i = 0; i < m; ++i)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    if(c >= 25){
        path[m] = 25;
        ways1(n-25, path, m+1, 25, cnt);
    }
    if(c >= 10){
        path[m] = 10;
        ways1(n-10,path, m+1, 10, cnt);
    }
    if(c >= 5){
        path[m] = 5;
        ways1(n-5, path, m+1, 5, cnt);
    }
    if(c >= 1){
        path[m] = 1;
        ways1(n-1, path, m+1, 1, cnt);
    }
}


int main(){
    int cnt = 0;
    int m = 0;
    int path[max_size] = {};
    ways1(10,path, m, 10, cnt);
    cout << cnt << endl;
 
}
