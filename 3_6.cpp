//
//  3_6.cpp
//  
//
//  Created by Pengyan Qin on 6/24/15.
//
//

#include <stack>
#include <iostream>
#include <queue>

using namespace std;
// don't forget to consider corner case when s is empty
stack<int> sortstack(stack<int> s){
    if(s.empty())
        return s;
    stack<int> res;
    while(!s.empty()){
        int tmp = s.top();
        s.pop();
        while(!res.empty() && tmp < res.top()){
            s.push(res.top());
            res.pop();
        }
        res.push(tmp);
    }
    return res;
}

// using priority_queue
void sortstack1(stack<int> &s){
    if(s.empty())
        return;
    priority_queue<int, vector<int>, greater<int> > pq;
    while(!s.empty()){
        pq.push(s.top());
        s.pop();
    }
    while(!pq.empty()){
        s.push(pq.top());
        pq.pop();
    }
}
int main(){
    stack<int> s;
    s.push(2);
    s.push(19);
    s.push(4);
    s.push(1);
    /*
    stack<int> sort = sortstack(s);
    while(!sort.empty()){
        cout << sort.top() << " ";
        sort.pop();
    }
    cout << endl;
     */
    
    sortstack1(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
 
}

