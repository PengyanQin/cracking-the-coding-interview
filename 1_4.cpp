//
//  1_4.cpp
//  
//
//  Created by Pengyan Qin on 6/14/15.
//
//

#include <iostream>
#include <string>

using namespace std;

// time complexity: O(n)
// space complexity: O(n)
// do not use the space after string, bot optimal

// if don't have the size, we may first calculate the new size, and then change from back to front（in place）

void replace2(string &s, int n){
    if(s.length() == 0)
        return;
    string res;
    for(int i = 0; i < n ; ++i){ // auto is the new feature of c++11
        if(isgraph(s[i]))   // is not space
            res += s[i];
        else
            res += "%20";
    }
    s = res;
}

// time complexity: O(n)
// space complexity: in place, optimal

void replace1(string &s, int n){
    if(s.length() == 0)
        return;
    int len = s.length();
    for(int i = n - 1; i >=0 ; --i){
        if(s[i] != ' ')
            s[--len] = s[i];
        else{
            s[--len] = '0';
            s[--len] = '2';
            s[--len] = '%';
        }
    }
    return;
}

int main(){
    string s = "Mr John Smith    ";
    int n = 13;
    replace2(s, n);
    cout << s << endl;
    return 0;
}


