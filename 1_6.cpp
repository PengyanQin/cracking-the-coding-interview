//
//  1_6.cpp
//  
//
//  Created by Pengyan Qin on 6/15/15.
//
//

#include <iostream>

using namespace std;

// time complexity: O(n^2)

void rotate(int *matrix, int n){
    for(int layer = 0; layer < n/2; ++layer){
        for(int shift = layer ; shift < n-1-layer; ++shift){
            int tmp = *(matrix + layer*n + shift); // store top
            *(matrix + layer*n + shift) = *(matrix + (n-shift-1)*n + layer); // left -> top
            *(matrix + (n-shift-1)*n + layer) = *(matrix + (n-1-layer)*n + n-shift-1); // bottom ->left
            *(matrix + (n-1-layer)*n + n-shift-1) = *(matrix + shift*n + n-1-layer); // right ->bottom
            *(matrix + shift*n + n-1-layer) = tmp; // top -> right
        }
    }
    return;
}

int main(){
    int a[4][4] = {{1, 6,  1, 1},
                   {2, 9, 3, 2},
                   {0, 3, 6, 3},
                   {5, 1, 4, 8}};
    int n = 4;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    rotate((int*)a, n);
    
    cout << "rotate result: " << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}
