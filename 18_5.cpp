//
//  18_5.cpp
//  
//
//  Created by Pengyan Qin on 7/23/15.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAX = (1 << 30);
// do one operation
// time complexity: O(n)
int shortest_distance(string A[], int n, string word1, string word2){
    if(word1 == word2)
        return 0;
    int min_dist = MAX;
    int cur_dist = MAX;
    int last_word1 = -1;
    int last_word2 = -1;
    for(int i = 0; i < n; ++i){
        if(A[i] == word1){
            last_word1 = i;
            if(last_word2 != -1)
                cur_dist = last_word1 - last_word2;
        }
        else if(A[i] == word2){
            last_word2 = i;
            if(last_word1 != -1)
                cur_dist = last_word2 - last_word1;
        }
        if(cur_dist < min_dist)
            min_dist = cur_dist;
    }
    return min_dist;
}

// do repeated operations, using map
// first preprocessing, takes O(n)
// find shortest distance, takes O(1)
map<string, vector<int> > preprocessing(string A[], int n){
    map<string, vector<int> > mymap;
    for(int i = 0; i < n; ++i){
        mymap[A[i]].push_back(i);
    }
    return mymap;
}

// time complexity: O(a*b)
int minDiff(vector<int> A, vector<int> B){
    int min_diff = MAX;
    int cur_diff = MAX;
    
    for(int i = 0; i < A.size(); ++i){
        for(int j = 0; j < B.size(); ++j){
            cur_diff = abs(A[i] - B[j]);
            if(cur_diff < min_diff)
                min_diff = cur_diff;
        }
    }
    return min_diff;
}
// time complexity: O(a + b)
int minDiff1(vector<int> A, vector<int> B){
    int min_diff = MAX;
    int cur_diff = MAX;
    
    for(int i = 0, j = 0; i < A.size() && j < B.size(); ){
        cur_diff = abs(A[i] - B[j]);
        if(A[i] < B[j])
            ++i;
        else if(A[i] > B[j])
            ++j;
        else
            return 0;
        if(cur_diff < min_diff)
            min_diff = cur_diff;
    }
    return min_diff;
}


int shortest_distance1(string A[], int n, string word1, string word2){
    map<string, vector<int> > mymap = preprocessing(A, n);
    return minDiff1(mymap[word1], mymap[word2]);
}

int main(){
    string A[] = {"what", "is", "your", "name", "my", "name", "is", "Monica"};
    int n = 8;
    string word1 = "name";
    string word2 = "is";
    cout << shortest_distance(A, n, word1, word2) << endl;
    cout << shortest_distance1(A, n, word1, word2) << endl;
}


