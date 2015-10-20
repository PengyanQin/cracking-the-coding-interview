//
//  11_4.cpp
//  
//
//  Created by Pengyan Qin on 7/15/15.
//
//

#include <iostream>
#include <string>

using namespace std;

// if A[mid] is empty, move mid to left
int find_string(string A[], int left, int right, string str){
    if(left > right)
        return -1;
    int mid = left + (right - left)/2;
    int tmp = mid;
    while(A[mid] == "" && mid >= left) // if A[mid] is empty, move left until non-empty or tmp < left
        mid--;
    if(mid < left)   // search right half
        return find_string(A, tmp + 1, right, str);
    else{            // find non empty string in A[mid]
        if(A[mid] == str)
            return mid;
        if(str < A[mid])
            return find_string(A, left, mid - 1, str);
        else
            return find_string(A, mid + 1, right, str);
    }
}

// if A[mid] is empty, move mid to cloest non-empty string
int find_string1(string A[], int left, int right, string str){
    if(left > right)
        return -1;
    int mid = (left + right) >> 1;
    int i = 0;
    while(A[mid] == ""){
        if(mid - i >= left || mid + i <= right){
            if(mid - i >= left && A[mid - i] != ""){
                mid = mid - i;
                break;
            }
            else if(mid + i <= right && A[mid + i] != ""){
                mid = mid + i;
                break;
            }
            ++i;
        }
        else
            return -1;
    }
    if(str == A[mid])
        return mid;
    if(str < A[mid])
        return find_string1(A, left, mid - 1, str);
    else
        return find_string1(A, mid + 1, right, str);
}

int find_string2(string A[], int left, int right, string str){
    if(left > right)
        return -1;
    int mid = (left + right) >> 1;
    int l = mid - 1;
    int r = mid + 1;
    while(A[mid] == ""){
        if(l < left && r > right)
            return -1;
        else if(l >= left && A[l] != ""){
            mid = l;
            break;
        }
        else if(r <= right && A[r] != ""){
            mid = r;
            break;
        }
        --l;
        ++r;
    }
    
    if(str == A[mid])
        return mid;
    if(str < A[mid])
        return find_string1(A, left, mid - 1, str);
    else
        return find_string1(A, mid + 1, right, str);
}

int main(){
    string A[] = {"", "dad", "", "", "", "", "", "", "", "", "", "", ""};
    int n = 13;
    string str = "dad";
    cout << find_string1(A, 0, n-1, str) << endl;
}


