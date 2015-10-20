//
//  3_5.cpp
//  
//
//  Created by Pengyan Qin on 6/24/15.
//
//

#include <stack>
#include <iostream>
#include <cstdlib>
using namespace std;

//a queue cut into 2 pieces, s1 is the in, s2 is out
class MyQueue{
    stack<int> s1;
    stack<int> s2;
public:
    bool empty(){
        return s1.empty() && s2.empty();
    }
    void push(int val){
        s1.push(val);
    }
    void pop(){
        if(empty())
            return;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    int& top(){
        if(empty())
            exit(0);
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    int size(){
        return s1.size() + s2.size();
    }
};

int main(){
    MyQueue s;
    for(int i = 0; i < 4; ++i)
        s.push(i);  // 0, 1, 2, 3
    s.pop();
    s.pop(); // 2, 3
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.empty() << endl;

}
