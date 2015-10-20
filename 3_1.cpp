//
//  3_1.cpp
//  
//
//  Created by Pengyan Qin on 6/17/15.
//
//

#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 100  // the size of each stack
#define MAX_SIZE 300

// Fixed Division
class Stack3{
    int a[3*SIZE]; // the single array
    int ptop[3]; // the number of elts in each stack
public:
    Stack3(){
        for(int i = 0; i < 3*SIZE; ++i)
            a[i] = 0;
        ptop[0] = 0;  // record the number of elements in the stack 0
        ptop[1] = 0;  // record the number of elements in the stack 1
        ptop[2] = 0;  // record the number of elements in the stack 2
    }
    
    bool empty(int stack){
        return ptop[stack] == 0;
    
    }
    
    void push(int stack, int val){
        if(ptop[stack] >= SIZE){
            cout << "the stack is full!" << endl;
            return;
        }
        a[stack*SIZE + ptop[stack]] = val;
        ptop[stack]++;
    }
    
    void pop(int stack){
        if(ptop[stack] == 0){
            cout << "the stack is empty!" << endl;
            return;
        }
        ptop[stack]--;
    }
    
    int& top(int stack){
        if(ptop[stack] == 0){
            cout << "the stack is empty!" << endl;
            exit(0);
        }
        return a[stack*SIZE + ptop[stack] - 1];
    }
    
    void print(){
        for(int i = 0; i < 3; ++i){
            cout << "the " << i << " stack : ";
            for(int j = i*SIZE; j < i*SIZE + ptop[i]; ++j)
                cout << a[j] << " ";
            cout << endl;
        }
        return;
    }
};

// Flexible Division

class Stack3f{
    struct node{
        int val;       // the val in current postion
        int pre_ind;   // the index of last postion
        node(): val(0), pre_ind(-1) {}
        node(int val_, int pre_ind_):val(val_), pre_ind(pre_ind_) {}
    };
    
    node a[MAX_SIZE];
    int ptop[3];
    int cur;
    
public:
    Stack3f(){
        ptop[0] = -1;  // record current position in stack 0 (total array)
        ptop[1] = -1;  // record current position in stack 1 (total array)
        ptop[2] = -1;  // record current position in stack 2 (total array)
        cur = -1; // the current position in array
    }
    
    bool empty(int stack){
        return ptop[stack] == -1;
    
    }
    
    void push(int stack, int val){
        if(cur >= MAX_SIZE){
            cout << "the stack is full!" << endl;
            return;
        }
        node p(val,ptop[stack]);
        a[++cur] = p;
        ptop[stack] = cur;
        return;
    }
    
    void pop(int stack){
        if(ptop[stack] == -1){
            cout << "the stack is empty!" << endl;
            return;
        }
        
        ptop[stack] = a[ptop[stack]].pre_ind;
    }
    
    int& top(int stack){
        if(ptop[stack] == -1){
            cout << "the stack is empty!" << endl;
            exit(0);
        }
        
        return a[ptop[stack]].val;
    }
    
    void print(){
        for(int i = 0; i < 3; ++i){
            cout << "the " << i << " stack : " << endl;
            for(int j = ptop[i]; j > -1;j = a[j].pre_ind){
                cout << a[j].val << " ";
            }
            cout << endl;
        }
        return;
    }
    
};

int main(){
    Stack3f s3;
    for(int i = 0; i < 9; ++i)
        s3.push(0, i);
    s3.push(2, 11);
    for(int i = 2; i < 5; ++i)
        s3.push(1, i);
    for(int i = -3; i < 0; ++i)
        s3.push(2, i);
    s3.print();
    s3.top(1) = 10;
    s3.pop(2);
    s3.pop(0);
    s3.print();
    return 0;
}









