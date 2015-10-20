//
//  9_5.cpp
//  
//
//  Created by Pengyan Qin on 7/12/15.
//
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vs;

// from 1 char to the whole string s
// take advantage of substr() and inset()
vs permutations(string s, int n){
    vs res;
    if(n == 1){
        string str = s.substr(0, 1);
        res.push_back(str);
        return res;
    }
    vs t = permutations(s, n-1);
    for(int i = 0; i < t.size(); ++i){
        for(int j = 0; j <= t[i].length(); ++j){
            string sub = t[i];
            sub.insert(j, 1, s[n-1]);
            res.push_back(sub);
        }
    }
    return res;
}

// take advantage of erase
vs permutations1(string s){
    vs res;
    if(s.length() == 1){
        res.push_back(s);
        return res;
    }
    for(int i = 0; i < s.length(); ++i){
        char c = s[i];
        string t = s;
        vs r = permutations1(t.erase(i, 1));
        for(int j = 0; j < r.size(); ++j){
            res.push_back(c + r[j]);
        }
    }
    return res;
}

int main(){
    string s = "abcd";
    //int length = s.length();
    vs res = permutations1(s);
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;

}

