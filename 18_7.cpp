//
//  18_7.cpp
//  
//
//  Created by Pengyan Qin on 7/23/15.
//
//

#include <iostream>
#include <algorithm> // for sort()
#include <string>
#include <unordered_map>
using namespace std;

bool comp(string s1, string s2){
    return s1.length() > s2.length();
}

// simple version: only made of two words
// time complexity of sort(): O(nlogn)
string LonestWord_Two(string A[], int n){
    sort(A, A+n, comp);
    unordered_map<string, bool> dict;
    for(int i = 0; i < n; ++i)
        dict[A[i]] = true;

    for(int i = 0; i < n; ++i){
        for(int j = 1; j < A[i].length(); ++j){
            string left = A[i].substr(0, j);
            string right = A[i].substr(j);
            if(dict[left] && dict[right])
                return A[i];
        }
    }
    return "";
}


//
bool BuildOfWords(unordered_map<string, bool> map, string word, bool isoriginal){
    if(map[word] && !isoriginal)
        return true;
    for(int i = 0; i < word.length(); ++i){
        string first = word.substr(0, i);
        string rest = word.substr(i);
        if(map[first] && BuildOfWords(map, rest, false))
            return true;
    }
    map[word] = false; // dynamic programming approach to cache the results between calls
    return false;
}

string LonestWord_Any(string A[], int n){
    sort(A, A+n, comp);
    unordered_map<string, bool> dict;
    for(int i = 0; i < n; ++i)
        dict[A[i]] = true;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < A[i].length(); ++i){
            if(BuildOfWords(dict, A[i], true))
                return A[i];
        }
    }
    return "";
}

int main(){
    string A[] = {"test", "tester", "testertest", "testing",
        "apple", "seattle", "banana",  "batting", "ngcat",
        "batti","bat", "testingtester", "testbattingcat"};
    int n = 13;
    cout << LonestWord_Two(A, n) << endl;
    cout << LonestWord_Any(A, n) << endl;
    

}


