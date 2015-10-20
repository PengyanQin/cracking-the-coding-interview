//
//  17_7.cpp
//  
//
//  Created by Pengyan Qin on 7/21/15.
//
//

#include <iostream>
#include <cmath> // for pow()
using namespace std;

string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string digit[] = {"hundred", "thousand", "million", "billion"};
string bigs[] = {"", "thousand", "million", "billion"};
// method 1: the result takes into account of single and plural
string convert_english(int n){
    string res;
    if(n < 10 && n >= 0){
        res = ones[n];
        return res;
    }
    if(n >= 10 && n < 20){
        int ind = n - 10;
        res = teens[ind];
        return res;
    }
    if(n >= 20 && n < 100){
        int ten = n/10 - 2;
        int one = n%10;
        if(one == 0)
            res = tens[ten];
        else
            res = tens[ten] + " " + ones[one];
        return res;
    }
    int high_dig = 0;
    int tmp = 0;
    for(int i = 0; i <= 4; ++i){
        tmp = n/pow(1000, i);
        if(tmp == 0){
            high_dig = i - 1;
            break;
        }
    }
    int high = 0;
    if(high_dig == 0){ // hundred
        high = n/100;
        n = n%100;
    }
    else{   //others
        int div = pow(1000, high_dig);
        high = n/div;
        n = n%div;
    }
    
    if(n == 0){
        if(high == 1){
            res = convert_english(high) + " " + digit[high_dig];
        }
        else{
            res = convert_english(high) + " " + digit[high_dig] + "s ";
        }
    }
    else{
        if(high == 1){
            res = convert_english(high) + " " + digit[high_dig] + " " + convert_english(n) ; // from high to low
        }
        else{
            res = convert_english(high) + " " + digit[high_dig] + "s " + convert_english(n);
        }
    }
    return res;
}

// method 2: regardless of single or plural, but take into account of comma
// represent 0 through 999, then

string NumToHundred(int n){
    string res;
    if(n < 10 && n >= 0){
        res = ones[n];
        return res;
    }
    if(n >= 10 && n < 20){
        int ind = n - 10;
        res = teens[ind];
        return res;
    }
    if(n >= 20 && n < 100){
        int ten = n/10 - 2;
        int one = n%10;
        if(one == 0)
            res = tens[ten];
        else
            res = tens[ten] + " " + ones[one];
        return res;
    }
    if(n >= 100 && n < 1000){
        int thou = n/100;
        int rest = n%100;
        if(rest == 0){
            res = ones[thou] + " hundred";
        }
        else{
            res = ones[thou] + " hundred " + convert_english(rest);
        }
        return res;
    }
    return res;
}

string NumToString(int n){
    string res;
    int count = 0;
    while(n > 0){
        if(n%1000 != 0){
            res = NumToHundred(n%1000) + " " + bigs[count] + ", " +  res; // from low to high
        }
        n = n/1000;
        count++;
    }
    return res;
}


int main(){
    int n = 99999;
    string res = convert_english(n);
    string res1 = NumToString(n);
    
    cout << res << endl;
    cout << res1 << endl;

}
