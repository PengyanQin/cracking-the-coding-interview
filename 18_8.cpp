//
//  18_8.cpp
//  
//
//  Created by Pengyan Qin on 7/23/15.
//
//

#include <iostream>
#include <string>

const int MAX_M = 11*11;
const int MAX_N = 26;

using namespace std;
class Trie{
public:
    int size;
    int trie[MAX_M][MAX_N];

    Trie(char *s);
    void insert(char *s);
    bool find(char *s);
    void print();
};

Trie::Trie(char *s){ // a pointer to char
    memset(trie[0], -1, sizeof(trie[0]));
    size = 1;
    while(*s){
        insert(s);
        ++s;
    }
}

void Trie::insert(char *s){
    int p = 0;
    while(*s){
        int i = *s - 'a';
        if(-1 == trie[p][i]){
            memset(trie[size], -1, sizeof(trie[size]));
            trie[p][i] = size++;
        }
        p = trie[p][i];
        ++s;
    }
}

bool Trie::find(char *s){
    int  p = 0;
    while(*s){
        int i = *s - 'a';
        if(-1 == trie[p][i])
            return false;
        p = trie[p][i];
        ++s;
    }
    return true;
}

void Trie::print(){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < MAX_N; ++j){
            cout << trie[i][j] << " ";
        }
        cout << endl;
    }
}

// pay attention: c_str() returns  const char*, cannot be modified further
int main(){
    //string target = "mississippi"; // a string is composed of several char
    char s[] = "mississippi";
    Trie tree(s);
    tree.print();
    
    string patter[] = {"is", "sip", "hi", "sis", "mississippa"};
    int n = 5;
    for(int i = 0; i < n; ++i)
        cout << tree.find((char*)&patter[i][0]) << endl;
    return 0;
}


