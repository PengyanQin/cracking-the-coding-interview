//
//  4_5.cpp
//  
//
//  Created by Pengyan Qin on 6/27/15.
//
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = (1 << 30);
const int MIN = (1 << 31);

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

void insert1(node *root, int dat){ // create a tree (not BST)
    if(root == nullptr){
        node *n = new node(dat);
        root = n;
        return;
    }
    else if(root->left == nullptr){
        node *ptr = new node(dat);
        root->left = ptr;
        return;
    }
    else if(root->right == nullptr){
        node *ptr = new node(dat);
        root->right= ptr;
        return;
    }
    if(dat%2)
        insert1(root->left, dat);
    else
        insert1(root->right, dat);
}


void BFS(node* root){
    if(root == nullptr)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *tmp = q.front();
        q.pop();
        cout << tmp->data << " ";
        if(tmp->left){
            q.push(tmp->left);
        }
        if(tmp->right){
            q.push(tmp->right);
        }
    }
}

// method1: inorder print is from small to large
void InOrder(node *root, vector<int> &v){
    if(root == nullptr)
        return;
    InOrder(root->left, v);
    v.push_back(root->data);
    InOrder(root->right, v);
}

bool is_BST(node *root){
    vector<int> v;
    InOrder(root, v);
    for(int i = 0; i < v.size()-1; ++i){
        if(v[i] > v[i+1])
            return false;
    }
    return true;
}

// method2: compare parent node and parent->left, parent->right
void is_BST1(node *root, bool &BST){
    if(root == nullptr)
        return;
    if(root->left){
        if(root->left->data <= root->data)
            is_BST1(root->left, BST);
        else
            BST = false;
    }
    if(root->right){
        if(root->right->data > root->data)
            is_BST1(root->right, BST);
        else
            BST = false;
    }
}

//method3: use min and max to compare
bool is_BST2(node* root, int min, int max){
    if(root == nullptr)
        return true;
    if(root->data <= max && root->data > min){
        return is_BST2(root->left, min, root->data) &&
        is_BST2(root->right, root->data, max);
    }
    else
        return false;
}

int main(){
    node *root = new node(8);
    int a[8] = {11, 3, 18, 9, 6, 13, 4, 1};
    int num = 8;
    for(int i = 0; i < num; ++i){
        insert(root, a[i]);
    }
     BFS(root);
    cout << is_BST(root) << endl;
    cout << is_BST2(root, MIN, MAX) << endl;
    
    bool BST = true;
    is_BST1(root, BST);
    cout << BST << endl;
    
    node *root1 = new node(8);
    int b[8] = {11, 3, 18, 9, 6, 13, 4, 1};
    int numb = 8;
    for(int i = 0; i < numb; ++i){
        insert1(root1, b[i]);
  
    }
    BFS(root1);
    cout << is_BST(root1) << endl;
    cout << is_BST2(root1, MIN, MAX) << endl;
    
    bool BST1 = true;
    is_BST1(root1, BST1);
    cout << BST1 << endl;
    
}
