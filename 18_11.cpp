//
//  18_11.cpp
//  
//
//  Created by Pengyan Qin on 7/28/15.
//
//

#include <iostream>
#include <fstream>

using namespace std;

// 1 represents black, 0 represents white

// time complexity: O(n)
bool is_valid(int *A, int n, int k){
    for(int i = 0; i <= k; i += k){ // only 2 times
        for(int j = 0; j <= k; ++j){
            if(*(A + i*n + j) == 0 || *(A + j*n + i) == 0 )
                return false;
        }
    }
    return true;
}

// brute force
// time complexity: O(n^4)
int maximum_subsquare(int *A, int n){
    for(int k = n-1; k > 0; --k){ // the side length of subsquare
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){  // the start point of subsquare
                if((i + k < n) && (j + k < n)){
                    if(is_valid(A + i*n + j, n, k))
                        return k+1;
                }
                else
                    break;
            }
        }
    }
    return -1;
}

// time complexity: O(n^3)
// check square reduced to O(1) by preprocessing

struct ones{
    int onesright;
    int onesdown;
    ones():onesright(0), onesdown(0){}
};

ones* preprocessing(int *A, int n){
    ones* M = new ones[(n+1)*(n+1)];
    
    for(int i = n; i >= 0; --i){
        for(int j = n ; j >= 0; --j){
            if(i == n || j == n || *(A + i*n + j) == 0 ){
                *(M + i*n + j) = ones();
            }
            else{
                (M + i*n + j)->onesright = (M + i*n + j + 1)->onesright + 1;
                (M + i*n + j)->onesdown = (M + (i + 1)*n + j)->onesdown + 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          cout << "(" << (M + i*n + j)->onesright << ", " << (M + i*n + j)->onesdown << ")" << " ";
        }
        cout << endl;
    }
    return M;
}

int maximum_subsquare_helper(ones *A, int n){
    for(int k = n-1; k >= 0; --k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){  // the start point of subsquare
                if((i + k < n) && (j + k < n)){
                    if((A + i*n + j)->onesdown == k+1 && (A + i*n + j)->onesright == k+1 &&
                       (A + i*n + j + k)->onesdown == k+1 &&  (A + (i + k)*n + j)->onesright == k+1)
                        return k+1;
                }
                else
                    break;
            }
        }
    }
    return -1;
}

int maximum_subsquare1(int *A, int n){
    ones * Ah = preprocessing(A, n);
    return maximum_subsquare_helper(Ah, n);
}

int main(){
    fstream fin;
    string filename = "18_11.in";
    
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open " << endl;
        exit(1);
    }
    int n;
    fin >> n;
    int *A = new int[n*n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            fin >> *(A + i*n + j);
        }
    }
    cout << maximum_subsquare(A, n) << endl;
    cout << maximum_subsquare1(A, n) << endl;
}
