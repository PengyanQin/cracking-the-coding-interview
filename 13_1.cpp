//
//  13_1.cpp
//  
//
//  Created by Pengyan Qin on 7/17/15.
//
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void printLastKLines(int k, string filename){
    fstream fin;
    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout << "fail to open" << endl;
        exit(1);
    }
    
    arr[k]; // string array can define without initialization
    int l_num = 0;
    string line;
    int ind = 0;
    while(getline(fin, line)){
        l_num++;
        if(ind >= k)
            ind = ind % k;
        arr[ind] = line;
    }
    
    int start = l_num % k;
    for(int i = start; i < k; ++i)
        cout << *(sptr + i) << endl;
    if(start != 0){
        for(int i = 0; i < start; ++i)
            cout << << endl;
    }
}

int main(){
    string filename = "13_1.in";
    int k = 4;
    printLastKLines(k, filename);
}

