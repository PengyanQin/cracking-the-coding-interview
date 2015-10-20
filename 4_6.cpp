//
//  4_6.cpp
//  
//
//  Created by Pengyan Qin on 6/27/15.
//
//

#include <iostream>
#include <vector>
#include <stack>
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

// consider different situdation
node* next_node(node* spot){
    if(spot == nullptr)
        return nullptr;
    if(spot->right){
        node *p = spot->right;
        while(p->left){
            p = p->left;
        }
        return p;
    }
    node *q = spot->parent;
    while(q && q->right == spot){
        spot = q;
        q = q->parent;
    }
    return q;
    /*
    if(spot->parent && spot->parent->left == spot)
        return spot->parent;
    if(spot->parent && spot->parent->right == spot){
        while(!spot->parent || spot->parent->left != spot){
            spot = spot->parent;
        }
        return spot->parent;
    }
    return nullptr;
     */
}

// inorder traversal, most easiest way, but must know root node, can without parent node
void inorder(node* root, vector<node*> &vec){
    if(root == nullptr)
        return;
    if(root->left)
        inorder(root->left, vec);
    vec.push_back(root);
    if(root->right)
        inorder(root->right, vec);
}

node* next_node1(node* root, node* spot){
    vector<node*> vec;
    inorder(root, vec);
    for(int i = 0; i < vec.size(); ++i){
        if(spot == vec[i])
            return vec[i+1];
    }
    return nullptr;
}

// inorder traversal using stack

node* next_node2(node *root, node *spot){
    stack<node*> s;
    bool search = false;
    node* tmp = root;
    while(true){
        while(tmp){
            s.push(tmp);
            tmp = tmp->left;
        }
        if(s.empty())
            break;
        tmp = s.top();
        s.pop();
        if(search)
            return tmp;
        if(spot == tmp)
            search = true;
        tmp = tmp->right;
    }
    return nullptr;
}

int main(){
    node *root = nullptr;
    int a[]= {8, 3, 13, 1, 5, 9, 14, 16};
    for(int i = 0; i < 8; ++i)
        insert(root, nullptr, a[i]);
    node *spot1 = root->left->right;
    //node *find1 = next_node1(root, spot1);
    //node *find1 = next_node(spot1);
    node *find1 = next_node2(root,spot1);
    cout << find1->data << endl;
    
    node *spot2 = root;
    //node *find2 = next_node1(root, spot2);
    //node *find2 = next_node(spot2);
    node *find2 = next_node2(root, spot2);
    cout << find2->data << endl;
    
    return 0;
}

