//
//  3_3.cpp
//  
//
//  Created by Pengyan Qin on 6/24/15.
//
//

#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;
const int SIZE = 3;

//fixed number of stack, there is alot of space waste

// pay attention: for top() and pop(), cur = 0 is different from other situations
// first consider the curstack size, they the stack num
class SetOfStacks{
    stack<int> sof[SIZE];
    int cur;
    int threshold;
public:
    SetOfStacks(int threshold_in):  cur(0), threshold(threshold_in){}
    void push(int val){
        if(sof[cur].size() >= threshold){
            if(cur == (SIZE - 1)){
                cout << "the stack is full!" << endl;
                return;
            }
            cur++;
        }
        sof[cur].push(val);
    }
    
    void pop(){
        if(sof[cur].size() == 0){
            if(cur == 0){
                cout << "the stack is empty!" << endl;
                return;
            }
            cur--;
        }
        sof[cur].pop();
    }
    
    int& top(){
        if(sof[cur].size() == 0){
            if(cur == 0){
                cout << "the stack is empty!" << endl;
                exit(0);
            }
            cur--;
        }
        return sof[cur].top();
    }
    
    bool empty(){
        return sof[0].size() == 0;
    }
    
};

// a list of stack, there is no maximum limit of the number of the elts
// list is doubly linked list, operade on two side

class SetOfStacks1{
    list<stack<int> > sof;
    int threshold;
public:
    SetOfStacks1(int threshold_in){
        threshold = threshold_in;
        sof.push_back(stack<int> ());
    }
    
    void push(int val){
        if(sof.back().size() == threshold){
            sof.push_back(stack<int> ());
        }
        sof.back().push(val);
    }
    
    void pop(){
        if(sof.back().size() == 0){
            if(sof.size() == 1){
                cout << "the stack is empty!" << endl;
                return;
            }
            sof.pop_back();
        }
        sof.back().pop();
    }
    
    int& top(){
        if(sof.back().size() == 0){
            if(sof.size() == 1){
                cout << "the stack is empty!" << endl;
                exit(0);
            }
            sof.pop_back();
        }
        return sof.back().top();
    }
    
    bool empty(){
        return sof.front().empty();
    }
};

// a vector of stack, there is no maximum limit of the number of the elts
//vector is an array that can change its size, operades on one side

class SetOfStacks2{
    vector<stack<int> > sof;
    int threshold;
public:
    SetOfStacks2(int threshold_in){
        threshold = threshold_in;
        sof.push_back(stack<int> ());
    }
    
    void push(int val){
        if(sof.back().size() == threshold){
            sof.push_back(stack<int> ());
        }
        sof.back().push(val);
    }
    
    void pop(){
        if(sof.back().size() == 0){
            if(sof.size() == 1){
                cout << "the stack is empty!" << endl;
                return;
            }
            sof.pop_back();
        }
        sof.back().pop();
    }
    
    int& top(){
        if(sof.back().size() == 0){
            if(sof.size() == 1){
                cout << "the stack is empty!" << endl;
                exit(0);
            }
            sof.pop_back();
        }
        return sof.back().top();
    }
    
    bool empty(){
        return sof.front().empty();
    }
};

//follow up

class follow_SetOfStacks{
    stack<int> sof[SIZE];
    int cur;
    int threshold;
public:
    follow_SetOfStacks(int threshold_in):  cur(0), threshold(threshold_in){}
    
    void push(int val){
        if(sof[cur].size() >= threshold){
            if(cur == (SIZE - 1)){
                cout << "the stack is full!" << endl;
                return;
            }
            cur++;
        }
        sof[cur].push(val);
    }
    
    void pop(){
        while(sof[cur].size() == 0){
            if(cur == 0){
                cout << "the stack is empty!" << endl;
                return;
            }
            cur--;
        }
        sof[cur].pop();
    }
    
    void popAt(int index){
        if(sof[index].size() == 0){
            cout << "the stack is empty!" << endl;
            return;
        }
        sof[index].pop();
    }
    
    int& top(){
        while(sof[cur].size() == 0){
            if(cur == 0){
                cout << "the stack is empty!" << endl;
                exit(0);
            }
            cur--;
        }
        return sof[cur].top();
    }
    
};

// improve the time complexity at the expense of space waste
class follow_SetOfStacks2{
    vector<stack<int> > sof;
    int threshold;
public:
    follow_SetOfStacks2(int threshold_in){
        threshold = threshold_in;
        sof.push_back(stack<int> ());
    }
    
    void push(int val){
        if(sof.back().size() == threshold){
            sof.push_back(stack<int> ());
        }
        sof.back().push(val);
    }
    
    void pop(){
        while(sof.back().size() == 0){
            if(sof.size() == 1){
                cout << "the stack is empty!" << endl;
                return;
            }
            sof.pop_back();
        }
        sof.back().pop();
    }
    void popAt(int index){
        if(sof[index].size() == 0){
            cout << "the stack is empty!" << endl;
            return;
        }
        sof[index].pop();
    }
    
    int& top(){
        while(sof.back().size() == 0){
            if(sof.size() == 1){
                cout << "the stack is empty!" << endl;
                exit(0);
            }
            sof.pop_back();
        }
        return sof.back().top();
    }

};


int main(){
    /*
    SetOfStacks2 s(3);
    for(int i = 2; i< 6; ++i)
        s.push(i);    //5, 4, 3, 2
   
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.empty() << endl;
    s.pop();
    cout << s.empty() << endl;
     
    */
    
    follow_SetOfStacks s(3);
    for(int i = 2; i< 10; ++i)
        s.push(i);  // [9, 8] [7, 6, 5] [4, 3, 2]
    s.popAt(1);
    s.popAt(1);
    s.popAt(1);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}



