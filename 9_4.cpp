//
//  9_4.cpp
//  
//
//  Created by Pengyan Qin on 7/12/15.
//
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector <vector<int> > vvi;
typedef vector<int> vi;

// take advantage of bit operaton
vvi subsets(int A[], int n){
    vvi res;
    int m = pow(2, n); // int m = 1 << n;
    for(int i = 0; i < m; ++i){
        vi vec;
        int ii = i;
        for(int j = 0; j < n; ++j){
            int bit = ii & 1;
            int w = bit * A[j];
            if(w)
                vec.push_back(w);
            ii >>= 1;
        }
        res.push_back(vec);
    }
    return res;
}

// recursive function
vvi subsets1(int A[], int n){
    vvi res;
    if(n == 0){
        vi sub;
        res.push_back(sub);
        return res;
    }
    vvi r = subsets1(A, n-1);
    for(int i = 0; i < r.size(); ++i){
        res.push_back(r[i]);
        r[i].push_back(A[n-1]);
        res.push_back(r[i]);
    }
    return res;
}

int main(){
    int A[] = {1, 2, 3};
    int n = 3;
    vvi res = subsets1(A, n);
    for(int i = 0; i < res.size(); ++i){
        vi tmp = res[i];
        cout << "( ";
        for(int j = 0; j < tmp.size(); ++j)
            cout << tmp[j] << " ";
        cout << ")" << endl;
    }
    return 0;
}

