//
//  11_7_2.cpp
//  
//
//  Created by Pengyan Qin on 7/16/15.
//
//

#include <iostream>
#include <vector>
#include <algorithm> // for sort()

using namespace std;

struct person{
    int ht;
    int wt;
    person(){}
    person(int ht_, int wt_):ht(ht_), wt(wt_){}
};

typedef vector<vector<person> > vvp;
typedef vector<person> vp;

void print(person A[], int n){
    for(int i = 0; i < n; ++i)
        cout << "(" << A[i].ht << ", " << A[i].wt << ") ";
    cout << endl;
}

bool comp(person p1, person p2){
    return p1.ht < p2.ht; // sort person array based on ht from small to large
}

// time complexity: O(n^2)
// method: sort the list by height, then apply longest increasing subsequence
// algorithm on just their weight
int built_tower(person A[], int n){
    sort(A, A + n, comp);
    
    int *l = new int[n];
    vvp myvvp;
    vp vec;
    for(int i = 0; i < n; ++i)
        myvvp.push_back(vec);
    
    int len = 1;
    int ind = 0;
    for(int i = 0; i < n; ++i){ // the longest non-decreasing subsequence end with A[i]
        l[i] = 1;
        for(int j = 0; j < i; ++j){
            if(A[i].wt > A[j].wt && l[j] + 1 > l[i]){
                l[i] = l[j] + 1;
                myvvp[i] = myvvp[j];
            }
        }
        myvvp[i].push_back(A[i]);
        if(len < l[i]){
            ind = i;
            len = l[i];
        }
    }
    
    vp res = myvvp[ind];
    for(int i = 0; i < res.size(); ++i)
        cout << "(" << res[i].ht << ", " << res[i].wt << ") ";
    cout << endl;
    return len;
    
}

int main(){
    person A[] = {person(65, 100), person(70, 150), person(56, 103), person(75, 190),
        person(60, 95), person(68, 110)};
    int n = 6;
    cout << built_tower(A, n) << endl;
}


