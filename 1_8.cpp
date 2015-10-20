//
//  1_8.cpp
//  
//
//  Created by Pengyan Qin on 6/15/15.
//
//

#include <iostream>
#include <string>

using namespace std;

bool is_substring(string s1, string s2){ // check is s2 is a substring of s1
    if(s1.length() == 0 || s2.length() == 0)
        return false;
    int start = 0;  // start position in s1
    int ind = 0;  // compare position in s2
    while((start + ind) < s1.length()){
        if(s1[start + ind] == s2[ind]){
            if(ind == s2.length() - 1)
                return true;
            else
                ind++;
        }
        else{
            ++start;
            ind = 0;
        }
    }
    return false;
}

bool is_rotation(string s1, string s2){ // check if s2 is a rotation of s1
    s2 = s2 + s2;
    return is_substring(s2, s1); // check if s1 is a substring of s2
}

int main(){
    string s1 = "waterbottle";
    string s2 = "erbottlewate";
    cout << is_rotation(s1, s2) << endl;
    return 0;
}

