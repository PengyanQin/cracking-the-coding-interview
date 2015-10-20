//
//  17_6.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>

using namespace std;
struct sortInd{
    int start;
    int end;
};

// most straight forward method
// time complexity: O(n^2)
sortInd find_index(int A[], int n){
    sortInd res;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(A[i] > A[j]){
                res.start = i;
                goto next;
            }
        }
    }
next:
    for(int i = n - 1; i >= 0; --i){
        for(int j = i - 1; j >= 0; --j){
            if(A[i] < A[j]){
                res.end = i;
                goto end;
            }
        }
    }
end:
    return res;
}

int main(){
    int A[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    int n = 13;
    sortInd res = find_index(A, n);
    cout << "(" << res.start << ", " << res.end << ")" << endl;
}
