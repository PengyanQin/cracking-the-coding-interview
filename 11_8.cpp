//
//  11_8.cpp
//  
//
//  Created by Pengyan Qin on 7/16/15.
//
//

#include <iostream>

using namespace std;

#define MAX_SIZE 200

// array implementation
class question{
private:
    int A[MAX_SIZE];
    int max_size;
    int cur;
    int binarysearch(int left, int right, int val){
        if(left > right)
            return -1;
        int mid = left + (right - left)/2;
        if(val == A[mid])
            return mid;
        if(val < A[mid])
            return binarysearch(left, mid - 1, val);
        if(val > A[mid])
            return binarysearch(mid + 1, right, val);
        return -1;
    }
public:
    question():max_size(MAX_SIZE), cur(0){}
    // time complexity: O(n)
    void track(int n){
        if(cur == max_size){
            cout << "Full" << endl;
            return;
        }
        if(cur == 0){
            A[cur++] = n;
            return;
        }
        int tmp = cur - 1;
        while(tmp >= 0 && n < A[tmp]){
            A[tmp + 1] = A[tmp];
            tmp--;
        }
        A[tmp + 1] = n;
        cur++;
    }
    // time complexity: O(1)
    // worst case: O(n)
    int getRankOfNumber(int n){
        int ind = binarysearch(0, cur - 1, n);
        if(ind == -1)
            return ind;
        else{
            while(ind < cur && A[ind] == n) //  avoid repetition
                ind++;
            return (ind - 1);
        }
    }
};

int main(){
    int A[] = {3, 3, 3, 3, 3, 3};
    int n = 6;
    question q;
    for(int i = 0; i < n; ++i)
        q.track(A[i]);
    cout << "getRankOfNumber(1) = " << q.getRankOfNumber(1) << endl;
    cout << "getRankOfNumber(3) = " << q.getRankOfNumber(3) << endl;
    cout << "getRankOfNumber(4) = " << q.getRankOfNumber(4) << endl;
}




