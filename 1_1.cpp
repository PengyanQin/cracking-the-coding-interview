//
//  1_1.cpp
//  
//
//  Created by Pengyan Qin on 6/13/15.
//
//

# include <string>
# include <iostream>
# include <algorithm>  // for transform

using namespace std;

// time complexity: O(n)

// 易错点：don't consider the special case
// s.lengt() > 128

bool is_unique1(string s){ // ASCII string
    if(s.length() > 128)
        return false;
    int a[128] = {0};
    for(int i = 0; i < s.length(); ++i){
        int num = (int)s[i];
        if(a[num])
            return false;
        else
            a[num] = 1;
    }
    return true;
}

bool is_unique2(string s){// only english word
    if(s.length() > 26)
        return false;
    int a[26] = {0};
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i = 0; i < s.length(); ++i){
        int num = s[i] - 'a';
        if(a[num])
            return false;
        else
            a[num] = 1;
    }
    return true;
}

bool is_unique3(string s){ // use less space for only english word
    if(s.length() > 26)
        return false;
    int a = 0;  // 32 bits
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i = 0; i < s.length(); ++i){
        int num = s[i] - 'a';
        if(a & (1 << num))
            return false;
        else
            a |= (1 << num);
        
    }
    return true;
}

bool is_unique4(string s){ // use less space for ASCII string
    if(s.length() > 128)
        return false;
    int a[4] = {};
    for(int i = 0; i < s.length(); ++i){
        int num = (int)s[i];
        int shift = num%32;
        int ind = num/32;
        if(a[ind] & (1 << shift))
            return false;
        else
            a[ind] |= (1 << shift);
    }
    return true;

}

int main(){
    string str = "absgs";
    cout << is_unique4(str) << endl;
    cout << is_unique1(str) << endl;
    string str1 = "AbowjHP";
    cout << is_unique3(str1) << endl;
    return 0;
}



