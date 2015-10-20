//
//  18_2.cpp
//  
//
//  Created by Pengyan Qin on 7/22/15.
//
//

#include <iostream>
#include <cstdlib> // for rand()
#include <algorithm> // for swap

using namespace std;

void shuffle_cards(int A[], int n){
    for(int i = 0;  i < n; ++i){
        int ind = rand()%(n-i) + i;
        swap(A[0], A[ind]);
    }
}

int main(){
    srand((unsigned)time(0));
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    shuffle_cards(A, n);
    for(int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}





