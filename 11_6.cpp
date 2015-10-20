//
//  11_6.cpp
//  
//
//  Created by Pengyan Qin on 7/15/15.
//
//

#include <iostream>
#include <fstream> // for fstream
#include <cstdlib> // for exit
#include <vector>

using namespace std;

// recursive function
// time complexity: O(m + n)
bool find_elts(int *A, int m, int n, int x, int y, int val){
    if(x < 0 || x >= m || y < 0 || y >= n )
        return false;
    if(val == *(A + x*n + y))
        return true;
    if(val < *(A + x*n + y))
        return find_elts(A, m, n, x, y - 1, val); // move left
    else if(val > *(A + x*n + y))
        return find_elts(A, m, n, x + 1, y, val); // move down
    return false;
}

// binary search
// time complexity: O(logn + logm)
// n does not change during recursive function, since the matrix is not changed and access method unchanged
bool find_elts1(int *A, int sm, int em, int sn, int en, int n, int val){
    cout << "left = " << sn << " right = " << en <<  "    ";
    cout << "top = " << sm << " bottom = " << em << "    ";
    if(sm > em || sn > en)
        return false;
    int midm = (sm + em) >> 1;
    int midn = (sn + en) >> 1;
    cout << "row_mid = " << midm << " col_mid = " << midn << endl;
    if(*(A + midm * n + midn) == val)
        return true;
    bool a = false, b = false, c = false, d = false;
    if(val <= *(A + midm * n + midn) && val >= *(A + sm * n + sn)){
        cout << "a" << endl;
        a = find_elts1(A, sm, midm, sn, midn, n, val);
    }
    if(val <= *(A + em * n + en) && val >= *(A + (midm + 1)*n + midn + 1)){
        cout << "b" << endl;
        b = find_elts1(A, midm + 1, em, midn + 1, en, n, val);
    }
    if(val <= *(A + midm * n + en) && val >= *(A + sm * n + midn + 1)){
         cout << "c" << endl;
        c = find_elts1(A, sm, midm, midn + 1, en, n, val);
    }
    if(val <= *(A + em * n + midn) && val >= *(A + (midm + 1) * n + sn)){
         cout << "d" << endl;
        d = find_elts1(A, midm + 1, em, sn, midn, n, val);
    }
    return a + b + c + d;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

bool searchMatrix_helper(vector<vector<int> >& mmatrix, int left, int right, int top, int bottom, int target){
    cout << "left = " << left << " right = " << right <<  "    ";
    cout << "top = " << top << " bottom = " << bottom << "    ";
    if(left > right || top > bottom)
        return false;
    int row_mid = (top + bottom)>>1;
    int col_mid = (left + right)>>1;
    cout << "row_mid = " << row_mid << " col_mid = " << col_mid << endl;
    cout << "mid val " << mmatrix[row_mid][col_mid] << endl;
    if(mmatrix[row_mid][col_mid] == target){
        cout << "come to hear" << endl;
        return true;
    }
    bool a = false, b = false, c = false, d = false;
    if(target >= mmatrix[top][left] && target <= mmatrix[row_mid][col_mid]){
        cout << "a" << endl;
        a = searchMatrix_helper(mmatrix, left, col_mid, top, row_mid, target);
    }
    if(col_mid + 1 <= right && target >= mmatrix[top][col_mid + 1] && target <= mmatrix[row_mid][right]){
         cout << "b" << endl;
        b = searchMatrix_helper(mmatrix, col_mid + 1, right, top, row_mid, target);
        cout << b << endl;
    }
    if(row_mid + 1 <= bottom &&target >= mmatrix[row_mid + 1][left] && target <= mmatrix[bottom][col_mid]){
         cout << "c" << endl;
        c = searchMatrix_helper(mmatrix, left, col_mid, row_mid + 1, bottom, target);
    }
    if(row_mid + 1 <= bottom && col_mid + 1 <= right && target >= mmatrix[row_mid + 1][col_mid + 1] && target <= mmatrix[bottom][right]){
         cout << "d" << endl;
        d = searchMatrix_helper(mmatrix, col_mid + 1, right, row_mid + 1, bottom, target);
    }
    return a + b + c + d;
}

int main(){
    fstream fin;
    string filename = "11_6.in";
    
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open " << endl;
        exit(1);
    }
    int m, n;
    fin >> m >> n;
    cout << "m = " << m << " n = " << n << endl;
    int *A = new int[m*n];
    vector<vector<int> > matrix(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            fin >> *(A + i*n + j);
            matrix[i][j] = *(A + i*n + j);
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j)
            cout << matrix[i][j] <<  " ";
        cout << endl;
    }
    
    int val = 0;
   // cout << find_elts(A, m, n, 0, n-1, val) << endl;
    //cout << find_elts1(A, 0, m-1, 0, n-1, n, val) << endl;
    //cout << "next method " << endl;
    cout << searchMatrix_helper(matrix, 0, n-1, 0, m-1, val) << endl;
    
}

