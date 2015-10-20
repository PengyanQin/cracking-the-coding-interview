//
//  17_8.cpp
//  
//
//  Created by Pengyan Qin on 7/21/15.
//
//

#include <iostream>
#include <vector>
using namespace std;

/*
 
 should talk about:
 1. all negative
 2. length is 0
 
 */

vector<int> CLS(int A[], int n){
    vector<int> cur_vec;
    vector<int> max_vec;
    int cur_sum = 0;
    int max_sum = 0;
    for(int i = 0; i < n; ++i){
        cur_sum += A[i];
        cur_vec.push_back(A[i]);
        if(cur_sum < 0){
            cur_sum = 0;
            cur_vec.clear();
        }
        if(cur_sum > max_sum){
            max_sum = cur_sum;
            max_vec = cur_vec;
        }
    }
    cout << "the max sum is " << max_sum << endl;
    return max_vec;
}

int main(){
    int A[] = {-8, 3, -2, 4, -10};
    int n = 5;
    vector<int> vec = CLS(A, n);
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;


}
