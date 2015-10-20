//
//  17_5.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>

using namespace std;
#define SIZE 4

// time complexity: O(4)
// input is array
enum Color{R, Y, G, B};
void MasterMind(Color guess[], Color sol[]){
    int hit = 0;
    int ps_hit = 0;
    int cnt_g[SIZE] = {};
    int cnt_s[SIZE] = {};
    for(int i = 0; i < SIZE; ++i){
        if(guess[i] == sol[i])
            hit++;
        else{
            cnt_g[guess[i]]++;
            cnt_s[sol[i]]++;
        }
    }
    cout << "the hit number is " << hit << endl;
    for(int i = 0; i < SIZE; ++i){
        while(cnt_g[i] != 0 && cnt_s[i]){
            ps_hit++;
            cnt_g[i]--;
            cnt_s[i]--;
        }
    }
    cout << "the pseudo-hit number is " << ps_hit << endl;
}

// method is totally same
// while input is string, without use of enum
// pay attention: the string is composed of char
int code(char c){
    switch(c){
        case 'R':
            return 0;
        case 'G':
            return 1;
        case 'B':
            return 2;
        case 'Y':
            return 3;
        default:
            return -1;
    }

}

void MasterMind1(string guess, string sol){
    int hit = 0;
    int ps_hit = 0;
    int cnt_g[SIZE] = {};
    int cnt_s[SIZE] = {};
    for(int i = 0; i < SIZE; ++i){
        if(guess[i] == sol[i])
            hit++;
        else{
            cnt_g[code(guess[i])]++;
            cnt_s[code(sol[i])]++;
        }
    }
    cout << "the hit number is " << hit << endl;
    for(int i = 0; i < SIZE; ++i){
        while(cnt_g[i] != 0 && cnt_s[i]){
            ps_hit++;
            cnt_g[i]--;
            cnt_s[i]--;
        }
    }
    cout << "the pseudo-hit number is " << ps_hit << endl;
}

int main(){
    Color guess[SIZE] = {R, G, B, Y};
    Color sol[SIZE] = {G, G, R, R};
    string str_guess = "RGBY";
    string str_sol = "GGRR";
    MasterMind(guess, sol);
    MasterMind1(str_guess, str_sol);
}



