//
//  7_0.cpp
//  
//  all about prime numbers
//  Created by Pengyan Qin on 7/6/15.
//
//

#include <iostream>
#include <cmath>
using namespace std;

// check whether a number is a prime number
bool is_prime(int n){
    if(n < 2)             // prime number is larger than 1
        return false;
    for(int i = 2; i < n; ++i){     // prime number only divisible by 1 and itself
        if(n%i == 0)
            return false;
    }
    return true;
}

// improve the time efficiency
bool is_prime1(int n){
    if(n < 2)
        return false;
    int sn = sqrt(n);
    for(int i = 2; i <= sn; ++i){
        if(n%i == 0)
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////
// print a list of prime numbers smaller or equal than max

// check each number
void print_prime(int max){
    for(int i = 0; i <= max; ++i)
        if(is_prime1(i))
            cout << i << ", ";
    cout << endl;
}

// sieve of eratosthenes
// all non-prime numbers are divisible by a prime number
void print_prime1(int n){
    bool *composite = new bool[n+1];  // undefined value
    memset(composite, false, sizeof(bool)*(n+1)); // always used in c
    int m = sqrt(n);
    for(int i = 2;  i <= m; ++i){
        if(!composite[i]){
            for(int j = i*i; j <= n; j += i){
                composite[j] = true;
            }
        }
    }
    for(int i = 2; i <= n; ++i)
        if(!composite[i])
            cout << i << ", ";
    cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////
// print the first n prime numbers
void print_n_prime(int n){
    int m = pow(n,2);
    int count = 0;
    for(int i = 0; i <= m; ++i)
        if(is_prime1(i)){
            cout << i << ", ";
            count++;
            if(count == n){
                cout << endl;
                return;
            }
        }
    cout << endl;
}

void print_n_prime1(int n){
    int m = pow(n,2);
    int count = 0;
    bool *composite = new bool[m+1];  // undefined value
    memset(composite, false, sizeof(bool)*(m+1)); // always used in c
    for(int i = 2;  i <= n; ++i){
        if(!composite[i]){
            for(int j = i*i; j <= m; j += i){
                composite[j] = true;
            }
        }
    }
    for(int i = 2; i <= m+1; ++i)
        if(!composite[i]){
            cout << i << ", ";
            count++;
            if(count == n){
                cout << endl;
                return;
            }
        }
    cout << endl;
}


int main(){
    int n = 2; // 2 is the smallest prime number
    int m = 100;
    cout << is_prime(n) << endl;
    cout << is_prime1(n) << endl;
    
    cout << is_prime(m) << endl;
    cout << is_prime1(m) << endl;
    
    print_prime(m);
    print_prime1(m);
    
    print_n_prime(5);
    print_n_prime1(5);
    

    return 0;
}
