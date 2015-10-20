//
//  11_7_1.cpp
//  
//
//  Created by Pengyan Qin on 7/16/15.
//
// Find the largest problem

#include <iostream>
#include <vector>

using namespace std;

// Given a sequence of number
// Find the length of the longest non_decreasing sequence

int LIS(int A[], int n){
    int *l = new int[n];
    vector<vector<int> > vvi;
    vector<int> vec;
    for(int i = 0; i < n; ++i)
        vvi.push_back(vec);
    
    int len = 1;
    int ind = 0;
    for(int i = 0; i < n; ++i){  // the longest subsequence with ends with A[i]
        l[i] = 1;
        for(int j = 0; j < i; ++j){  // go through A[0] to A[i-1]
            if(A[i] >= A[j] && (l[j] + 1) > l[i]){
                l[i] = l[j] + 1;
                vvi[i] = vvi[j];
            }
        }
        vvi[i].push_back(A[i]);   // the sequence ends with A[i]
        if(l[i] > len){
            ind = i;
            len = l[i];
        }
    }
    for(int i = 0; i < vvi[ind].size(); ++i)
        cout << vvi[ind][i] << " ";
    cout << endl;
    
    delete[] l;
    return len;
}

int main(){
    int A[] = {13, 14, 15, 11, 12};
    int n = 5;
    cout << LIS(A, n) << endl;
}



