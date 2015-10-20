//
//  7_4.cpp
//  
//
//  Created by Pengyan Qin on 7/6/15.
//
//

#include <iostream>

using namespace std;


// don't remember the special case

/*
int flip_sign(int a){ // -a
    int res = 0;
    if(a > 0){
        for(int i = 0; i < a; ++i)
            res += -1;
    }
    else{
        for(int i = a; i < 0; ++i)
            res += 1;
    }
    return res;
}
*/

int flip_sign(int a){  // -a
    int d = a < 0 ? 1:-1;
    int res = 0;
    while(a){
        res += d;
        a += d;
    }
    return res;
}

int my_abs(int a){ // |a|
    if(a < 0)
        a = flip_sign(a);
    return a;
}

int multiply(int a, int b){  //a*b
    int flag = 0;
    if((a > 0 && b < 0) || (a < 0 && b > 0))
        flag = 1;  // flag = 0, result is positive; flag = 1, result is negative
    a = my_abs(a);
    b = my_abs(b);
    if(a > b)
        swap(a, b); // guarantee a < b
    int res = 0;
    for(int i = 0; i < a; ++i)
        res += b;
    if(flag)
        res = flip_sign(res);
    return res;
}


int subtract(int a, int b){ //a - b
    return a + flip_sign(b);
}

// don't remember the special case
int divide(int a, int b){  // a/b
    if(b == 0){
        cout << "denominator can't be 0" << endl;
        return -1;
    }
    int flag = 0;
    if((a > 0 && b < 0) || (a < 0 && b > 0))
        flag = 1;  // flag = 0, result is positive; flag = 1, result is negative
    a = my_abs(a);
    b = my_abs(b);
    int res = 0;
    int count = 0;
    while(res < a){
        res += b;
        count++;
    }
    if(flag)
        count = flip_sign(count);
    return count;
}

int main(){
    cout << flip_sign(0) << endl;
    cout << flip_sign(5) << endl;
    cout << flip_sign(-5) << endl;
    
    cout << my_abs(0) << endl;
    cout << my_abs(5) << endl;
    cout << my_abs(-5) << endl;
    
    cout << multiply(3, 0) << endl;
    cout << multiply(0, 3) << endl;
    cout << multiply(3, 2) << endl;
    cout << multiply(-3, 2) << endl;
    cout << multiply(3, -2) << endl;
    cout << multiply(-3, -2) << endl;
    
    cout << subtract(2, 3) << endl;
    cout << subtract(2, -3) << endl;
    cout << subtract(2, 0) << endl;
    cout << subtract(0, 2) << endl;
    
    cout << divide(15, 5) << endl;
    cout << divide(15, -5) << endl;
    cout << divide(-15, -5) << endl;
    cout << divide(-15, 5) << endl;
    cout << divide(0, 5) << endl;
    cout << divide(0, -5) << endl;
    cout << divide(5, 0) << endl;

}
