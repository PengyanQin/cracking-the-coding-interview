//
//  18_6.cpp
//  
//
//  Created by Pengyan Qin on 7/23/15.
//
//

#include <iostream>
#include <utility> // for swap()

using namespace std;

// accomodata quick sort

int partition(int A[], int left, int right){
    int i = left, j = right - 1;
     while(i < j){
         while(A[i] < A[right])
             ++i;
         while(A[j] > A[right])
             --j;
         if(i < j)
             swap(A[i], A[j]);
         else
             break;
    }
    swap(A[i], A[right]);
    return i;
}

// time complexity: O(n)
void quick_sort(int A[], int left, int right, int n){ // find the smallest n elts(0, 1, ..., n-1), not sorted
    if(left > right)
        return;
    int pivot = partition(A, left, right);
    cout << "pivot " << pivot << endl;
    if(pivot == n-1 || pivot == n) // left <= pivot <= right
        return;
    else if(pivot < n-1)
        quick_sort(A, pivot+1, right, n);
    else // pivot > n
        quick_sort(A, left, pivot-1, n);
}

// pivot = n-1, 0 to pivot the smallest n elts, 0 to (pivot-1) the smallest (n-1) elts
// pivot = n, 0 to pivot the smallest (n+1) elts, 0 to (pivot-1) the smallest n elts

int main(){
    int A[] = {35, 2, 11, 9, 29, 42, 90, 6, 48, 13, 10, 27, 33};
    int left = 0;
    int right = 12;
    int first = 7;
    quick_sort(A, left, right, first);
    for(int i = 0;  i <= right; ++i)
        cout << A[i] << " ";
    cout << endl;

}
