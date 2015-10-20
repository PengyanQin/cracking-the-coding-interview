//
//  7_7.cpp
//  
//
//  Created by Pengyan Qin on 7/8/15.
//
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 3 queues to manage the data
// time compleicyt: O(k)
int kth_num(int k){
    if(k < 0)
        return 0;
    queue<int> q3, q5, q7;
    q3.push(3);
    q5.push(5);
    q7.push(7);
    int count = 0;
    int res = 0;
    while(count < k){
        if((q3.front() < q5.front()) && (q3.front() < q7.front())){
            res = q3.front();
            q3.push(3*res);
            q5.push(5*res);
            q7.push(7*res);
            q3.pop();
        }
        else if((q5.front() < q3.front()) && (q5.front() < q7.front())){
            res = q5.front();
            q5.push(5*res);
            q7.push(7*res);
            q5.pop();
        }
        else if((q7.front() < q3.front()) && (q7.front() < q5.front())){
            res = q7.front();
            q7.push(7*res);
            q7.pop();
        }
        count++;
    }
    return res;
}

// one priority queue to manage the data
// time complexity: O(k^2), there are a lot of repetition
int kth_num1(int k){
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(3);
    pq.push(5);
    pq.push(7);
    int count = 0;
    int res = 0;
    while(count < k){
        if(res == pq.top())
            pq.pop();
        else{
            res = pq.top();
            pq.push(3*res);
            pq.push(5*res);
            pq.push(7*res);
            pq.pop();
            count++;
        }
    }
    return res;
}

int main(){
    int k = 12;
    cout << kth_num(k) << endl;
    cout << kth_num1(k) << endl;
}

