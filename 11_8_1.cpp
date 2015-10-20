//
//  11_8_1.cpp
//  
//
//  Created by Pengyan Qin on 7/17/15.
//
//

#include <iostream>

using namespace std;

// tree implementation

class question{
private:
    struct node{
        int data;
        node* left;
        node* right;
        node(){}
        node(int data_): data(data_), left(nullptr), right(nullptr){}
    };
    void insert(node* &nd, int n){
        if(nd == nullptr){
            node *nn = new node(n); // can't create a variable and take the address to nd, since it will be
            nd = nn;                // destroyed automatically when the function is exit
            return;
        }
        if(n <= nd->data){
            insert(nd->left, n);
        }
        else{
            insert(nd->right, n);
        }
    }
    void in_order_traversal(node* nd, int n, int &cnt){
        if(nd == nullptr){
            return;
        }
        in_order_traversal(nd->left, n, cnt);
        if(nd->data <= n)
            cnt++;
        else
            return;
        in_order_traversal(nd->right, n, cnt);
    }
    
    node* root;
public:
    question(): root(nullptr){}
    // time complexity: O(logn)
    void track(int n){
        insert(root, n);
    }
    // time complexity: O(logn)
    int getRankOfNumber(int n){
        int cnt = 0;
        in_order_traversal(root, n, cnt);
        return (cnt - 1);
    }
};

int main(){
    int A[] = {5, 1, 4, 4, 5, 9, 7, 13, 3};
    int n = 9;
    question q;
    for(int i = 0; i < n; ++i)
        q.track(A[i]);
    
    cout << "getRankOfNumber(1) = " << q.getRankOfNumber(1) << endl;
    cout << "getRankOfNumber(3) = " << q.getRankOfNumber(3) << endl;
    cout << "getRankOfNumber(4) = " << q.getRankOfNumber(4) << endl;
}

