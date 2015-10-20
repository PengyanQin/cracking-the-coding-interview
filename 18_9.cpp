//
//  18_9.cpp
//  
//
//  Created by Pengyan Qin on 7/25/15.
//
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

class Median{
private:
    int MAX;
    int size;
    int A[MAX_SIZE];
public:
    Median():MAX(MAX_SIZE), size(0){
        for(int i = 0; i < MAX; ++i)
            A[i] = 0;
    }
    // time complexity: O(nlogn)
    void insert(int n){
        if(size == MAX){
            cout << "the container is full" << endl;
            return;
        }
        A[size++] = n;
        sort(A, A + size);
    }
    // time complexity: O(1)
    int get_median(){
        int mid = size/2;
        if(size%2){
            return A[mid];
        }
        else
            return (A[mid] + A[mid - 1])/2;
    }
    // time complexity: O(n)
    void print(){
        for(int i = 0; i < size; ++i)
            cout << A[i] << " ";
        cout << endl;
    
    }
};

int main(){
    Median mm;
    
    int A[] = {3, 6, 2, 7, 3, 1, 10, 9, 17};
    int n = 9;
    for(int i = 0; i < n; ++i){
        mm.insert(A[i]);
    }
    mm.print();
    cout << mm.get_median() << endl;

}
