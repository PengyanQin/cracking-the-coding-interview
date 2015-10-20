//
//  17_11.cpp
//  
//
//  Created by Pengyan Qin on 7/22/15.
//
//

#include <iostream>
#include <stdlib.h> // for rand()

using namespace std;

int rand5(){
    return rand()%5;
}

// exit the while loop only when generate 0 to 6, so low efficiency
// 0, 1, 2, 3, 4, 5, 6
int rand7(){
    int tmp = 5*rand5() + rand5(); // randomly generage 0 to 24 inclusively, low
    while(tmp > 6){
        tmp = 5*rand5() + rand5();
    }
    return tmp;
}

// exit the while loop when generate 0 to 20, high efficiency
// 0,  1,  2,  3,   4,  5,  6
// 7,  8,  9,  10, 11, 12, 13
// 14, 15, 16, 17, 18, 19 ,20
int rand7_high(){
    int x = (1 << 30);
    while(x > 20){
        x = 5*rand5() + rand5();
    }
    return x%7;
}

int main(){
    cout << rand7() << endl;
    cout << rand7_high() << endl;
}
