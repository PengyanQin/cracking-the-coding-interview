//
//  3_2.cpp
//  
//
//  Created by Pengyan Qin on 6/23/15.
//
//

#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

const int SIZE = 100;

// using two array
// the problem is data redundancy
class minStack{
    int a[SIZE];
    int top;    // current position
    int minimum[SIZE];
public:
    minStack(){
        for(int i = 0; i < SIZE; ++i){
            a[i] = 0;
            minimum[i] = (1 << 30);
        }
        top = -1;
    }
    
    void push(int val){
        if(top >= (SIZE-1)){
            cout << "the stack is full!" << endl;
            return;
        }
        a[++top] = val;
        if(top == 0)
            minimum[0] = val;
        else
        {
            if(val < minimum[top-1])
                minimum[top] = val;
            else
                minimum[top] = minimum[top - 1];
        }

    }
    
    void pop(){
        if(top == -1){
            cout << "the stack is empty" << endl;
            return;
        }
        
        --top;
    }
    
    int& front(){
        if(top == -1){
            cout << "the stack is empty" << endl;
            exit(0);
        }
        return a[top];
    }
    
    int min(){
        if(top == -1){
            cout << "the stack is empty" << endl;
            exit(0);
        }
        return minimum[top];
    }
    
    void print_elt(){
        for(int i = 0; i <= top; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
    
    void print_min(){
        for(int i = 0; i <= top; ++i)
            cout << minimum[i] << " ";
        cout << endl;
    }
};

//using an array to store elts
// using a stack to store the minimal element, size is small
class StackWithMin{
    stack<int> minstack;
    int a[SIZE];
    int ntop;
public:
    StackWithMin(){
        for(int i = 0; i < SIZE; ++i){
            a[i] = 0;
        }
        ntop = -1;
        minstack.push((1<<30));
    }
    
    void push(int val){
        if(ntop >= (SIZE-1)){
            cout << "the stack is full!" << endl;
            return;
        }
        a[++ntop] = val;
        if(minstack.top() > val){
            minstack.push(val);
        }
        else if(minstack.top() == val){
            minstack.push(val);
        }
    }
                
    void pop(){
        if(ntop == -1){
            cout << "the stack is empty" << endl;
            return;
        }
        if(a[ntop] == minstack.top())
            minstack.pop();
        ntop--;
    }
                
    int& front(){
        if(ntop == -1){
            cout << "the stack is empty" << endl;
            exit(0);
        }
        return a[ntop];
    }
                
    int min(){
        return minstack.top();
    }
                
    void print_elt(){
        for(int i = 0; i <= ntop; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
    
};

// using two stack, one is storing the elts
// another one is storing the smallest elts
class stackm{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int val){
        s1.push(val);
        if(s2.empty())
            s2.push(val);
        else{
            if(val <= s2.top())
                s2.push(val);
        }
    }
    
    void pop(){
        if(s1.top() == s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int& top(){
        return s1.top();
    }
    
    int min(){
        return s2.top();
    }
    
    bool empty(){
        return s1.empty();
    }

};


int main(){
    stackm ms;
    ms.push(10);
    ms.push(8);
    ms.push(1);
    ms.push(11);
    ms.push(9);
    ms.push(1);
    ms.push(7);
    ms.push(3);
   // ms.print_elt();
    cout << ms.min()<< endl;
    ms.pop();
    ms.pop();
    ms.pop();
    cout << ms.min()<< endl;
    ms.pop();
    ms.pop();
    ms.pop();
    cout << ms.min()<< endl;
    ms.pop();
    cout << ms.min()<< endl;
    return 0;
}














