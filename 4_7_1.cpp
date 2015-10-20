//
//  4_7_1.cpp
//  no additional nodes in node struct
//
//  Created by Pengyan Qin on 6/28/15.
//
//

#include <iostream>

using namespace std;

struct node{  // declare the node
    int data;
    node* left;
    node* right;
    node() {}
    node(int data_in):data(data_in), left(nullptr), right(nullptr){}
};

void insert(node* &root, int dat){  // create BST
    if(root == nullptr){
        node *n = new node(dat);
        root = n;
        return;
    }
    if(dat < root->data){
        insert(root->left, dat);
    }
    else{
        insert(root->right, dat);
    }
}

void get_node(node* root, node* &store, int k){
    if(root == nullptr)
        return;
    if(root->data == k){
        store = root;
        return;
    }
    get_node(root->left, store, k);
    get_node(root->right, store, k);
}

// find the common ancestor
bool isAncestor(node* root, node* p){ // whether root is the ancestor of p
    if(root == nullptr)
        return false;
    if(root == p)
        return true;
    return isAncestor(root->left, p) || isAncestor(root->right, p);
}

void commonAncestor(node *root, node *p, node *q, node *&ans){
    if(root == nullptr){
        ans = nullptr;
        return;
    }
    if(p == root || q == root){
        ans = root;
        return;
    }
    bool pl = isAncestor(root->left, p);
    bool ql = isAncestor(root->left, q);
    if(pl && ql)
        commonAncestor(root->left, p, q, ans);
    else if(pl || ql){
        ans = root;
        return;
    }
    else
        commonAncestor(root->right, p, q, ans);
    
}

int main(){
    node *root = nullptr;
    int a[]= {8, 3, 13, 1, 5, 9, 14, 16};
    for(int i = 0; i < 8; ++i)
        insert(root, a[i]);
    node *p;
    node *q;
    node *ans;
    get_node(root, p, 9);
    get_node(root, q, 16);
    commonAncestor(root, p, q, ans);
    cout << ans->data << endl;
    return 0;
}






