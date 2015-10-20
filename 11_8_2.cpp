//
//  11_8_2.cpp
//  
//
//  Created by Pengyan Qin on 7/17/15.
//
//

#include <iostream>

using namespace std;

// tree implementation
// make every node store the left subtree size
class question{
private:
    struct node{
        int data;
        int leftside;
        node* left;
        node* right;
        node(){}
        node(int data_): data(data_), leftside(0), left(nullptr), right(nullptr){}
    };
    void insert(node* &nd, int n){
        if(nd == nullptr){
            node *nn = new node(n); // can't create a variable and take the address to nd, since it will be
            nd = nn;                // destroyed automatically when the function is exit
            return;
        }
        if(n <= nd->data){
            nd->leftside += 1;
            insert(nd->left, n);
        }
        else{
            insert(nd->right, n);
        }
    }
    int getRankOfNumber_helper(node* nd, int n){
        if(nd == nullptr)
            return -1;
        if(n == nd->data)
            return nd->leftside;
        if(n < nd->data)
            return getRankOfNumber_helper(nd->left, n);
        else
            return nd->leftside + 1 + getRankOfNumber_helper(nd->right, n);
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
        return getRankOfNumber_helper(root, n);
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


