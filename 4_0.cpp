//
//  4_0.cpp
//  
//
//  Created by Pengyan Qin on 6/25/15.
//
//

#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node() {}
    node(int data_in):data(data_in), left(nullptr), right(nullptr){}
};

// recursive version
void insert(node* &root, int dat){
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

// DFS_inorder, recursive version
void InOrerPrint(node* root){
    if(root == nullptr){
        return;
    }
    InOrerPrint(root->left);
    cout << root->data << " ";
    InOrerPrint(root->right);
}

//BFS, use queue
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

// BFS, print out null
void BFS_null(node* root){
    if(root == nullptr){
        cout << "null";
        return;
    }
    queue<node*> q;
    q.push(root);
    cout << root->data << " ";
    while(!q.empty()){
        node *tmp = q.front();
        q.pop();
        if(tmp->left){
            q.push(tmp->left);
            cout << tmp->left->data << " ";
        }
        else{
            cout << "null ";
        }
        if(tmp->right){
            q.push(tmp->right);
            cout << tmp->right->data << " ";
        }
        else{
            cout << "null ";
        }
    }
}


int main(){
    node *root = new node(8);
    int a[5] = {3, 9, 13, 4, 1};
    int num = 5;
    for(int i = 0; i < num; ++i){
        insert(root, a[i]);
    }

    InOrerPrint(root);
    cout << endl;
    
    BFS(root);
    cout << endl;
    
    BFS_null(root);
    cout << endl;
    
    delete root;
}




