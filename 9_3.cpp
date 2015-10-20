//
//  9_3.cpp
//  
//
//  Created by Pengyan Qin on 7/11/15.
//
//

#include <iostream>
#include <algorithm>  // for min, max
using namespace std;

// Brute Force
// time complexity: O(n)
int magic_index(int A[], int n){
    for(int i = 0; i < n; ++i)
        if(A[i] == i)
            return i;
    return -1;
}

// assumption: distinct integers
// recursive function, cut into two pieces
// time complexity: O(logn)
int magic_index1(int A[], int start, int end){
    if(start > end)
        return -1;
    //int mid = (start + end)/2;
    int mid = start + (end - start)/2; // prevent overflow
    if(A[mid] < mid)
        return magic_index1(A, mid + 1, end);
    else if(A[mid] > mid)
         return magic_index1(A, start, mid - 1);
    else
        return mid;
}

// assumption: the numbers distinct integers
// recursive function, cut into two pieces
// the recursive function method will have segmentation fault
// since it is start from the smallest range
/*
int magic_index_rep1(int A[], int start, int end){
    if(start > end)
        return -1;
    int mid = start + (end - start)/2;
    if(A[mid] == mid)
        return mid;
    
    int left_ind = min(A[mid], mid);
    int right_ind = max(A[mid], mid);
    int left = magic_index_rep1(A, start, left_ind);
    int right = magic_index_rep1(A, right_ind, end);
    if(left > -1)
        return left;

    if(right > -1)
        return right;
    
    return -1;
}
*/

// assumption: the numbers distinct integers
// iterative method, cut into two pieces

int magic_index_rep(int A[], int start, int end){
    if(start > end)
        return -1;
    int cstart = start;
    int cend = end;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(A[mid] == mid)
            return mid;
        int left_ind = min(A[mid], mid);
        end = left_ind;
    }
    while(cstart <= cend){
        int mid = cstart + (cend - cstart)/2;
        if(A[mid] == mid)
            return mid;
        int right_ind = max(A[mid], mid);
        cstart = right_ind;
    }
    return -1;
}


int main(){
    /*
    int A[] = {-8, -1, 0, 2, 3, 5, 9, 11};
    int n = 8;
    cout << magic_index(A, n) << endl;
    cout << magic_index1(A, 0, n-1) << endl;
    */
    
    int B[] = {-3, 0, 4, 6, 7, 8, 8, 8, 9, 9, 13};
    int m = 11;
    cout << magic_index_rep(B, 0, m-1) << endl;
    cout << magic_index_rep1(B, 0, m-1) << endl;
}
