//
//  18_4.cpp
//  
//
//  Created by Pengyan Qin on 7/23/15.
//
//

#include <iostream>
#include <cmath>
using namespace std;

// brute force: O(n)
int numOf2(int n){
    int cnt = 0;
    while(n > 0){
        if(n%10 == 2){
            cnt++;
        }
        n = n/10;
    }
    return cnt;
}
int count_2s(int n){
    int res = 0;
    for(int i = 0; i <= n; ++i){
        res += numOf2(i);
    }
    return res;
}

//count 2s by digit
int count_2ss(int n){
    int res = 0;
    int digits = 0;
    int tmp = n;
    while(tmp > 0){
        digits++;
        tmp /= 10;
    }
    int dig = 0;
    while(dig < digits){
        int tens = pow(10, dig);
        int low = n%tens;
        int high = n/(tens*10);
        int val = (n/tens)%10;
        if(val < 2){
            res += high * tens;
        }
        else if(val > 2){
            res += (high + 1)*tens;
        }
        else
            res += high*tens + low + 1;
        
        dig++;
    }
    return res;
}

int count_2book(int n){
    int count = 0;
    int factor = 1;
    int low = 0, high = 0, cur = 0;
    while(n/factor != 0){
        low = n%factor;
        high = n/(factor*10);
        cur = (n/factor)%10;
        if(cur < 2){
            count += high * factor;
        }
        else if(cur > 2){
            count += (high + 1)*factor;
        }
        else
            count += high*factor + low + 1;
        
        factor *= 10;
    }
    return count;
}

int main(){
    int n = 62534;
    cout << numOf2(n) << endl;
    cout << count_2s(n) << endl;
    cout << count_2ss(n) << endl;
    cout << count_2book(n) << endl;
    return 0;


}
