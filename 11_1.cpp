//
//  11_1.cpp
//  
//
//  Created by Pengyan Qin on 7/13/15.
//
//

#include <iostream>

using namespace std;

# define MAX 100

// similar to merge portion of mergesort

void mergeAB(int A[], int a, int B[], int b){
    for(int i = a - 1, j = b - 1, k = a + b - 1; (i >= 0) || (j >= 0); ){
        if((i >= 0) && (j >= 0))
            A[k--] = A[i] > B[j] ? A[i--] : B[j--];
        else if(i >= 0){
            A[k--] = A[i--];
        }
        else
            A[k--] = B[j--];
    }
    
    for(int i = 0; i < a + b; ++i)
        cout << A[i] << " ";
    cout << endl;
    return;
}

int main(){
    int A[MAX] = {2, 3, 5, 8, 12};
    int a = 5;
    int B[] = {1, 5, 7, 10};
    int b = 4;
    mergeAB(A, a, B, b);
}
