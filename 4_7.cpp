//
//  4_7.cpp
//  have parent node in node struct
//
//  Created by Pengyan Qin on 6/27/15.
//
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct node{  // declare the node
    int data;
    node* left;
    node* right;
    node* parent;
    node() {}
    node(int data_in):data(data_in), left(nullptr), right(nullptr){}
};

void insert(node* &root, node* parent, int dat){  // create BST
    if(root == nullptr){
        node *n = new node(dat);
        n->parent = parent;
        root = n;
        return;
    }
    if(dat < root->data){
        insert(root->left,root, dat);
    }
    else{
        insert(root->right,root, dat);
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

// using hash table
node* commonAncestor(node *p, node *q){
    if(p == q)
        return p;
    unordered_map<node*, int> map;
    while(p){
        map[p] = 1;
        p = p->parent;
    }
    while(q){
        if(map[q])
            return q;
        q = q->parent;
    }
    return nullptr;
}

// no additional storage
node* commonAncestor1(node *p, node *q){
    if(p == q)
        return p;
    while(p){
        p = p->parent;
        node *t = q;
        while(t){
            t = t->parent;
            if(t == p)
                return p;
        }
    }
    return nullptr;
}

int main(){
    node *root = nullptr;
    int a[]= {8, 3, 13, 1, 5, 9, 14, 16};
    for(int i = 0; i < 8; ++i)
        insert(root, nullptr, a[i]);
    node *p;
    node *q;
    get_node(root, p, 9);
    get_node(root, q, 16);
    node* res = commonAncestor(p, q);
    node* res1 = commonAncestor1(p, q);
    cout << res->data << endl;
    cout << res1->data << endl;
    return 0;
}



