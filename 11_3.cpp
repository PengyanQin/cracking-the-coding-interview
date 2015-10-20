//
//  11_3.cpp
//  
//
//  Created by Pengyan Qin on 7/15/15.
//
//

#include <iostream>

using namespace std;

int find_ind(int A[], int left, int right, int val){
    if(left >= right)
        return -1;
    int mid = left + (right - left)/2;
    if(A[mid] == val)
        return mid;
    if(A[left] < A[mid]){
        if(val >= A[left] && val < A[mid])
            return find_ind(A, left, mid - 1, val);
        else
            return find_ind(A, mid + 1, right, val);
    }
    else if(A[mid] < A[right]){
        if(val > A[mid] && val <= A[right])
            return find_ind(A, mid + 1, right, val);
        else
            return find_ind(A, left, mid - 1, val);
    }
    else if(A[left] == A[mid]){
        if(A[mid] != A[right])
            return find_ind(A, mid + 1, right, val);
        else{
            int result = find_ind(A, left, mid - 1, val);
            if(result == -1)
                return find_ind(A, mid + 1, right, val);
            else
                return result;
        }
    }
    return -1;
}

int main(){
    int A[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int n = sizeof(A)/sizeof(A[0]);
    cout << find_ind(A, 0, n-1, 5) << endl;

}

