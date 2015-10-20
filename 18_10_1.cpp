//
//  18_10_1.cpp
//  
//
//  Created by Pengyan Qin on 7/25/15.
//
//

// Given two words(start, end), and a dictionary, find one shortest transformation sequences
// from start to end

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // for reverse()

using namespace std;

typedef vector<string> vs;

void BuildPath(map<string, vs> &traces, vs &path, string word, string start){
    if(word == start){
        path.push_back(word);
        reverse(path.begin(), path.end());
        return;
    }
    path.push_back(word);
    vs tmp = traces[word];
    for(int i = 0; i < tmp.size(); ++i)
        BuildPath(traces, path, tmp[i], start);
    return;
}

vs word_ladder_onepath(string A[], int n, string start, string end){
    map<string, vs> traces; // used to reconstructed the path
    vs path; // used to store the reconstructed path

    map<string, bool> mymap;
    for(int i = 0; i < n; ++i){
        mymap[A[i]] = true;
    }

    vs layer[2];
    int cur = 0;
    int pre = 1;
    layer[cur].push_back(start);
    
    while(!layer[cur].empty()){
        for(vs::iterator it = layer[cur].begin(); it != layer[cur].end(); ++it){  // error 1: delete already considered words
            mymap[*it] = false;
        }

        cur = !cur;
        pre = !pre;
        layer[cur].clear();
        
        for(int i = 0; i < layer[pre].size(); ++i){
            string word = layer[pre][i];
            for(int j = 0; j < word.size(); ++j){
                for(char c = 'a'; c <= 'z'; ++c){
                    string tmp = word;
                    if(c != tmp[j]){
                        tmp[j] = c;
                        if(mymap[tmp]){
                            layer[cur].push_back(tmp);
                            traces[tmp].push_back(word);
                            if(tmp == end){   // only find one shortest path
                                BuildPath(traces, path, end, start);
                                return path;
                            }
                        }
                    }
                }
            }
        }
    }
    return path;
}

int main(){
    string A[] = {"hot", "dot", "dog", "lot", "log", "hit", "cog"};
    int n = 7;
    string start = "hit";
    string end = "cog";
    vs path = word_ladder_onepath(A, n, start, end);
    for(int i = 0; i < path.size(); ++i){
        cout << path[i] << " ";
    }
    cout << endl;
}

