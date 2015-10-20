//
//  1_3.cpp
//  
//
//  Created by Pengyan Qin on 6/14/15.
//
//

#include <iostream>
#include <algorithm> // for sort()
#include <string>

using namespace std;

//time complexity: sort = O(nlogn), total = O(nlogn)
// don't forget to check the case that one of string is emplty
bool is_permutation1(string s1, string s2){
    if(s1 == "" || s2 == "")
        return false;
    if(s1.length() != s2.length())
        return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 == s2)
        return true;
    else
        return false;
}

// time complexity: total = O(n)
// don't forget to check the case that one of string is emplty
bool is_permutation2(string s1, string s2){
    if(s1 == "" || s2 == "")
        return false;
    if(s1.length() != s2.length())
        return false;
    
    int a[128] = {0};  // can use byte operation to reduce the space complexity, refer to 1_1
    
    for(int i = 0; i < s1.length(); ++i){
        int n1 = (int)s1[i];
        int n2 = (int)s2[i];
        a[n1]++;
        a[n2]--;
    }
    
    for(int i = 0; i < 128; ++i)
        if(a[i] != 0)
            return false;
    return true;
}


int main(){
    string s1 = "ab";
    string s2 = "  ";
    cout << is_permutation1(s1, s2) << endl;
    cout << is_permutation2(s1, s2) << endl;
    return 0;
}



