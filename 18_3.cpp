//
//  18_3.cpp
//  
//
//  Created by Pengyan Qin on 7/22/15.
//
//

#include <iostream>
#include <cstdlib> // for rand()

using namespace std;

void Random(int A[], int n, int m){
    for(int i = 0; i < m; ++i){
        int k = rand()%(n - i) + i;
        swap(A[i], A[k]);
    }
}

int main(){
    srand((unsigned)time(0));
    int n = 9, m = 7;
    int A[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    Random(A, n, m);
    for(int i = 0; i < m; ++i)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}

