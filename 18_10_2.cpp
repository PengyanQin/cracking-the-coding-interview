//
//  18_10_2.cpp
//  
//
//  Created by Pengyan Qin on 7/27/15.
//
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // for reverse()

using namespace std;

typedef vector<string> vs;
typedef vector<vector<string> > vvs;

void BuildPath(map<string, vs> &traces, vvs &pathes, vs &path, string word, string start){
    if(word == start){
        path.push_back(word);
        vs tmp = path;
        reverse(tmp.begin(), tmp.end());
        pathes.push_back(tmp);
        path.pop_back();
        return;
    }
    path.push_back(word);
    vs tmp = traces[word];
    for(int i = 0; i < tmp.size(); ++i)
        BuildPath(traces, pathes, path, tmp[i], start);
    path.pop_back();
}

vvs word_ladder_allpathes(string A[], int n, string start, string end){
    map<string, vs> traces; // used to reconstructed the path
    vvs pathes; // used to store the reconstructed path
    
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
        bool found = false;
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
                            if(tmp == end)
                                found = true;
                        }
                    }
                }
            }
        }
        if(found)
            break;
    }
    vs path;
    BuildPath(traces, pathes, path, end, start);
    return pathes;
}

int main(){
    string A[] = {"hot", "dot", "dog", "lot", "log", "hit", "cog"};
    int n = 7;
    string start = "hit";
    string end = "cog";
    vvs pathes = word_ladder_allpathes(A, n, start, end);
    for(int i = 0; i < pathes.size(); ++i){
        for(int j = 0; j < pathes[i].size(); ++j){
            cout << pathes[i][j] << " ";
        }
        cout << endl;
    }
}
