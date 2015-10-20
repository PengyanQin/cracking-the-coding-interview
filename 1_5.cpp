//
//  1_5.cpp
//  
//
//  Created by Pengyan Qin on 6/14/15.
//
//

#include <iostream>
#include <string>

using namespace std;

// time complexity: O(n)

// string->int: atoi (#include <stdlib.h>)
// val -> string: to_string (#include <string>)

string compression(string s){
    string res;
    int cnt = 1;
    char c = s[0];
    for(int i = 1; i < s.length(); ++i){
        if(s[i] == c)
            cnt++;
        else{
            res += c + to_string(cnt);
            cnt = 1;
            c = s[i];
        }
    }
    res += c + to_string(cnt);
    
    if(res.length() < s.length())
        return res;
    else
        return s;
}

int main(){
    string s = "abcca";
    cout << compression(s) << endl;
    return 0;

}



















