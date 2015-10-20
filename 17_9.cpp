//
//  17_9.cpp
//  
//
//  Created by Pengyan Qin on 7/21/15.
//
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, int> map_strings(string A[], int n){
    unordered_map<string, int> mymap;
    for(int i = 0; i < n; ++i){
        if(A[i] != ""){
        string word = A[i];
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        mymap[word]++;
        }
    }
    return mymap;
}

int main(){
    string A[] = {"Aa", "bb", "", "cc", "aa", "aa", "bb"};
    int n = 7;
    unordered_map<string ,int> mymap = map_strings(A, n);
    string aa = "aA";
    transform(aa.begin(), aa.end(), aa.begin(), ::tolower);
    cout << mymap[aa] << endl;
}


