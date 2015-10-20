//
//  11_7.cpp
//  
//
//  Created by Pengyan Qin on 7/16/15.
//
// Find the minimum problem

#include <iostream>
#include <vector>
using namespace std;

#define INF (1 << 30);
// Given a list of coins A[], total sum
// Find the minimum number of coins the sum of which is sum
int min_num_coin(int A[], int n, int sum){
    vector<vector<int> > vvi;
    int *B = new int[sum + 1];  // store the results up till now
    B[0] = 0;
    vector<int> vec;
    for(int i = 0;  i < sum + 1; ++i)
        vvi.push_back(vec);  // remember to initialize vvi or it will corrupt
    for(int i = 1; i < sum + 1; ++i)
        B[i] = INF;
    
    for(int i = 1; i < sum + 1; ++i){
        for(int j = 0; j < n; ++j)
            if(A[j] <= i && B[i-A[j]] + 1 < B[i]){
                B[i] = B[i-A[j]] + 1;
                vvi[i] = vvi[i - A[j]];
                vvi[i].push_back(A[j]);
            }
    }
    
    for(int i = 0; i < vvi[sum].size(); ++i)
        cout << vvi[sum][i] << " ";
    cout << endl;
    int res  = B[sum];
    delete[] B;
    return res;
}

int main(){
    int A[] = {1, 10, 25}; // the sequence of the coin have no effect on the result
    int n = 3;
    int sum = 30;
    cout << min_num_coin(A, n, sum) << endl;
}



