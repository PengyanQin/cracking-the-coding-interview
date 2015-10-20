//
//  17_12.cpp
//  
//
//  Created by Pengyan Qin on 7/22/15.
//
//

#include <iostream>
#include <map>
#include <algorithm> // for sort()
using namespace std;

// brute force
// time complexity: O(n^2)
void fixed_sum(int A[], int n, int sum){
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j)
            if(A[i] + A[j] == sum)
                cout << "(" << A[i] << ", " << A[j] << ")" << endl;
    }
}

// using map
// time complexity: O(n)
// space complexity: O(n)
void fixed_sum1(int A[], int n, int sum){
    map<int, int> mymap;
    for(int i = 0; i < n; ++i){
        if(mymap[sum - A[i]] != 0){
            cout << "(" << A[i] << ", " << (sum - A[i]) << ")" << endl;
            mymap[sum - A[i]]--;
        }
        else
            mymap[A[i]]++;
    }
}

void fixed_sum11(int A[], int n, int sum){
    map<int, int> mymap;
    for(int i = 0; i < n; ++i){
        if(mymap[sum - A[i]] != 0){
            int fre = mymap[sum - A[i]];
            cout << "(" << A[i] << ", " << (sum - A[i]) << ")" << endl;
            fre--;
            while(fre != 0){
                cout << "(" << A[i] << ", " << (sum - A[i]) << ")" << endl;
                fre--;
            }
        }
        mymap[A[i]]++;
    }
}

// sorting
// time complexity: O(nlogn)
void fixed_sum2(int A[], int n, int sum){
    sort(A, A + n);
    int left = 0;         // the smallest
    int right = n - 1;    // the largest
    while(left < right){
        if(A[left] + A[right] > sum)
            --right;
        else if(A[left] + A[right] < sum)
            ++left;
        else{
             cout << "(" << A[left] << ", " << A[right] << ")" << endl;
            ++left;
            --right;
        }
    }
    return;
}

int main(){
    int A[] = {3, 1, 2, 3, 4, 3, 5, 6, 3};
    int n = 9;
    int sum = 6;
    fixed_sum(A, n, sum);
    cout << endl;
    fixed_sum1(A, n, sum);
    cout << endl;
    fixed_sum11(A, n, sum);
    cout << endl;
    fixed_sum2(A, n, sum);

}
