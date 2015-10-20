//
//  18_10.cpp
//  
//
//  Created by Pengyan Qin on 7/25/15.
//
//

// Given two words(start, end), and a dictionary, find the length of shortest transformation from
// start to end
#include <iostream>
#include <vector>
#include <string> //
#include <map> // for traces and array dict
#include <unordered_set> // for dictionary

using namespace std;

const int MAX = (1 << 30);
typedef vector<string> vs;

// time complexity: O(26*m), m is the word length
int word_ladder_length(string A[], int n, string start, string end){
    if(start.size() != end.size())
        return -1;
    
    map<string, bool> mymap;
    for(int i = 0; i < n; ++i){
        mymap[A[i]] = true;
    }
    
    vs path[2];
    int cur = 0;
    int pre = 1;
    path[cur].push_back(start);
    int len = 0;
    
    while(!path[cur].empty()){
        len++;
        for(int i = 0; i < path[cur].size(); ++i)  // erase all ready considered words
            mymap[path[cur][i]] = false;
        cur = !cur;
        pre = !pre;
        path[cur].clear();
        
        for(int i = 0; i < path[pre].size(); ++i){
            string word = path[pre][i];
            for(int j = 0; j < word.size(); ++j){
                for(int c = 'a'; c <= 'z'; ++c){
                    string tmp = word;
                    if(c != tmp[j]){
                        tmp[j] = c;
                        if(mymap[tmp]){
                            if(tmp == end){
                                len++;
                                return len;
                            }
                            else
                                path[cur].push_back(tmp);
                        }
                    }
                }
            }
        }
    }
    return MAX;
}

// time complexity: O(26*m), m is the word length
// the dictionary should be unordered_set, then do not need unordered_map
// unordered_set have find(), erase(), insert() function, while array do not have
int word_ladder_length1(unordered_set<string> A, string start, string end){
    if(start.size() != end.size())
        return -1;
    
    A.insert(start);
    A.insert(end);
    
    vs path[2];
    int cur = 0;
    int pre = 1;
    path[cur].push_back(start);
    int len = 0;
    
    while(!path[cur].empty()){
        len++;
        for(int i = 0; i < path[cur].size(); ++i)  // erase all ready considered words
            A.erase(path[cur][i]);
        cur = !cur;
        pre = !pre;
        path[cur].clear();
        
        for(int i = 0; i < path[pre].size(); ++i){
            string word = path[pre][i];
            for(int j = 0; j < word.size(); ++j){
                for(int c = 'a'; c <= 'z'; ++c){
                    string tmp = word;
                    if(c != tmp[j]){
                        tmp[j] = c;
                        if(A.find(tmp) != A.end()){
                            if(tmp == end){
                                len++;
                                return len;
                            }
                            else
                                path[cur].push_back(tmp);
                        }
                    }
                }
            }
        }
    }
    return MAX;
}

int main(){
    string A[] = {"hot", "dot", "dog", "lot", "log", "hit", "cog"};
    unordered_set<string> A1 = { "hot", "dot", "dog", "lot", "log", "hit", "cog" };
    int n = 7;
    string start = "hit";
    string end = "cog";
    cout << word_ladder_length(A, n, start, end) << endl;
    cout << word_ladder_length1(A1, start, end) << endl;
}
