//
//  17_3.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>
#include <climits>
using namespace std;

// time complexity: O(n)
// can only cal n < 13
int trail_zero(int n){
    if(n < 0)
        return -1;
    int res = 1;
    for(int i = n; i > 0; --i){
        res = i * res;
    }
    cout << res << endl;
    int cnt = 0;
    while(!(res%10)){
        res /= 10;
        cnt++;
    }
    return cnt;
}

// time complexity: O(n)
// count the number of 5, 2 is definitely enough, quite easy
int trail_zero1(int n){
    if(n < 0)
        return -1;
    int cnt = 0;
    for(int i = n; i > 0; --i){
        int tmp = i;
        while(!(tmp%5)){
            tmp /= 5;
            cnt++;
        }
    }
    return cnt;
}

int trail_zero2(int n){
    if(n < 0)
        return -1;
    int cnt = 0;
    for(int i = 5; i <= n; i *= 5){
        int tmp = n;
        if(tmp/i){
            cnt += tmp/i;
            tmp /= i;
        }
    }
    return cnt;
}

int fac(int n){
    if(n == 0)
        return 1;
    return n*fac(n-1);
}

int main(){
    int n = 50;
    //cout << INT_MAX << endl;
    //cout << fac(n) << endl;
    //cout << trail_zero(n) << endl;
    cout << trail_zero1(n) << endl;
    cout << trail_zero2(n) << endl;
}
