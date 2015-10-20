//
//  11_2.cpp
//  
//
//  Created by Pengyan Qin on 7/14/15.
//
//
#include <iostream>
#include <algorithm> // for sort
#include <map> // for map
#include <vector>
#include <string>

using namespace std;

typedef map<string, vector<string> > msv;

// writing compare function
bool comp(string s1, string s2){
    sort(&s1[0], &s1[0] + s1.length());
    sort(&s2[0], &s2[0] + s2.length());
    return s1 < s2;
}

void sort_array(string A[], int n){
    sort(A, A + n, comp);
}

// using hash table
// sorted_string -> original stirng
void sort_map(string A[], int n){
    msv mymap;
    for(int i = 0; i < n; ++i){
        string tmp = A[i];
        sort(tmp.begin(), tmp.end());
        mymap[tmp].push_back(A[i]);
   
    }
    int current = 0;
    for(msv::iterator it = mymap.begin(); it != mymap.end(); ++it){
        vector<string> vs = it->second;
        for(int i = 0; i < vs.size(); ++i)
            A[current++] = vs[i];
    }
}


int main(){
    string A[] = {"abcd", "cd", "adcb", "ad" , "dcba", "afdc"};
    int n = 6;
    sort_map(A, n);
    for(int i = 0; i < n; ++i)
        cout << A[i] << endl;
}


