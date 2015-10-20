//
//  5_2.cpp
//  
//
//  Created by Pengyan Qin on 7/3/15.
//
//

#include <iostream>
#include <string>  // c_str()
#include <vector>
#include <math.h>  // for pow()
#include <stdlib.h> // for atoi()

using namespace std;

void print_realnum(double d){
    vector<int> v;
    int count = 0;
    while((count < 32) && d){
        d = d*2;
        if(d >= 1){
            v.push_back(1);
            d = d - 1;
        }
        else
            v.push_back(0);
        count++;
    }
    if(count == 32){
        cout << "ERROR" << endl;
    }
    else{
        cout << "0.";
        for(int i = 0; i < v.size(); ++i){
            cout << v[i];
        }
        cout << endl;
    }
}

void dec_bin(double d){
    string s;
    d = 2*d;
    while(d > 0){
        if(s.size() > 31){
            cout << "ERROR" << endl;
            return;
        }
        
        if(d >= 1){
            s +=  to_string(1);
            d = d - 1;
        }
        else{
            s +=  to_string(0);
        }
        d = 2*d;
    }
    cout << "0.";
    cout << s << endl;
}

double bin_dec(string s){
    string inte;
    string deci;
    int pos = s.find('.', 0); // if '.' doos not exit, pos = -1
    if(pos != -1){
        inte = s.substr(0, pos);
        deci = s.substr(pos + 1);
    }
    else{
        inte = s;
        deci = "0";
    }
    cout << inte << endl;
    cout << deci << endl;
    double res = 0;
    int tmp = atoi(inte.c_str());
    for(int i = 0; i < inte.size(); ++i){
        int bit = tmp & 1;
        tmp >>= 1;
        res += bit * pow(2, i);
    }
    tmp = atoi(deci.c_str());
    for(int i = 0; i < deci.size(); ++i){
        int bit = tmp & 1;
        tmp >>= 1;
        res += bit*pow(2, -(i+1));
    }
    return res;
}


int main(){
    //double d = 0.1285;
    //print_realnum(d);
    //dec_bin(d);
    
    string s = "11.0110";
    double res = bin_dec(s);
    cout << res << endl;
}


