//
//  18_9_1.cpp
//  
//
//  Created by Pengyan Qin on 7/25/15.
//
//

#include <iostream>
#include <queue>

using namespace std;

class Median{
private:
    priority_queue<int, vector<int>, greater<int> > min_heap;
    priority_queue<int, vector<int>, less<int> > max_heap;
    
public:
    // time complexity: O(logn)
    void insert(int n){
        if(max_heap.empty()){
            max_heap.push(n);
        }
        else if(min_heap.empty()){
            min_heap.push(n);
        }
        else if(max_heap.size() == min_heap.size()){
            if(n > min_heap.top()){
                int tmp = min_heap.top();
                max_heap.push(tmp);
                min_heap.pop();
                min_heap.push(n);
            }
            else{
                max_heap.push(n);
            }
        }
        else if(max_heap.size() > min_heap.size()){
            if(n > min_heap.top())
                min_heap.push(n);
            else{
                max_heap.push(n);
                int tmp = max_heap.top();
                max_heap.pop();
                min_heap.push(tmp);
            }
        }
        return;
    }
    // time complexity: O(1)
    int get_median(){
        if(max_heap.size() == 0)
            return 0;
        else if(min_heap.size() == max_heap.size())
            return (min_heap.top() + max_heap.top())/2;
        else
            return max_heap.top();
    }
    
    void get_size(){
        cout << "min heap size is " << min_heap.size() << endl;
        cout << "max heap size is " << max_heap.size() << endl;
    }
};


int main(){
    Median mm;
    int A[] = {3, 6, 2, 7, 3, 1, 10, 9, 17};
    int n = 9;
    for(int i = 0; i < n; ++i){
        mm.insert(A[i]);
    }
    mm.get_size();
    cout << mm.get_median() << endl;
    
}
