//
//  1_2.cpp
//  
//
//  Created by Pengyan Qin on 6/14/15.
//
//

#include <iostream>
#include <cstring>
#include <algorithm>  // for swap

//Time complexity: O(n)
//易忽略：str为空，要代入考虑

using namespace std;

void reverse(char *str){
    int i = 0;
    int j = strlen(str) - 1;
   
    for(int k = 0; k < strlen(str)/2; ++k)
        swap(str[i++], str[j--]);
    return;
}

void reverse1(char *str){
    int i = 0;
    int j = strlen(str) - 1;
    
    while(i < j)
        swap(str[i++], str[j--]);

    return;
}

void reverse2(char *str){
    int i = 0;
    int j = strlen(str) - 1;
    
    while(i < j){
        char tmp = *(str + i);
        *(str + i++) = *(str + j);
        *(str + j--) = tmp;
    }
    return;
}


int main(){
    char str[] = "what";
    int i = 0;
    //reverse(str);
    reverse2(str);
    while(str[i] != '\0'){
        cout << str[i];
        ++i;
    }
    cout << endl;
    return 0;
}






