//
//  3_0.cpp
//  
//
//  Created by Pengyan Qin on 6/17/15.
//
//

#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX_SIZE 100

/*
//stack array implementation
template<typename T>
class stack_arr{
private:
    T a[MAX_SIZE];
    int top;
public:
    stack_arr():top(-1){}
    bool is_empty(){
        return top == -1;
    }
    void pop(){
        if(is_empty())
            cout << "No element!" << endl;
        else
            top--;
        return;
    }
    
    void push(T item){
        if(top == MAX_SIZE - 1)
            cout << "The Stack is full!" << endl;
        else
            a[++top] = item;
        return;
    }
    T& front() {
        if(is_empty()){
            cout << "No element in the stack!" << endl;
            exit(EXIT_FAILURE);
        }
        else
            return a[top];
    }
    void print(){
        for(int i = 0; i <= top; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
};
*/

//stack linked list implementation
template<typename T>
class stack_ll{
private:
    struct node{
        T data;
        node* next;
    };
    node *top;
    int max_size;
    int count;
public:
    stack_ll(int max):top(nullptr),max_size(max),count(0){}
    bool is_empty(){
        return count == 0;
    }
    void push(T elt){
        if(count == max_size){
            cout << "The stack is full" << endl;
            return;
        }
        node *p = new node;
        p->data = elt;
        p->next = top;
        top = p;
        ++count;
        return;
    }
    void pop(){
        if(count == 0){
            cout << "No element!" << endl;
            return;
        }
        node *tmp = top;
        top = top->next;
        delete tmp;
        --count;
        return;
    }
    T& front(){
        if(count == 0){
            cout << "No element!" << endl;
            exit(EXIT_FAILURE);
        }
        return top->data;
    }
    void print(){
        node *cur = top;
        while(cur){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
        return;
    }
};


int main(){
    //stack_arr <int> s;
    stack_ll<int> s(MAX_SIZE);
    for(int i = 0; i < 10; ++i)
        s.push(i);
    s.print();
    cout << s.front() << endl;

    while(!s.is_empty())
        s.pop();
    s.pop();
    s.print();

    return 0;
}




