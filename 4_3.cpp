//
//  4_3.cpp
//  
//
//  Created by Pengyan Qin on 6/26/15.
//
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node() {}
    node(int data_in):data(data_in), left(nullptr), right(nullptr){}
};

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

void minBST(int a[], int start, int end, node* &root){
    if(start > end)
        return;
    int mid = (start + end)/2;
    insert(root, a[mid]);
    minBST(a, start, mid-1, root);
    minBST(a, mid+1, end, root);
}

void minBST1(int a[], int start, int end, node* &root){
    if(start > end)
        return;
    int mid = (start + end)/2;
    if(root == nullptr){
        node* n = new node(a[mid]);
        root = n;
        minBST(a, start, mid-1, root->left);
        minBST(a, mid+1, end, root->right);
    }
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 8, 9, 13, 14, 15};
    node *root = nullptr;
    minBST(a, 0, 10, root);
    //minBST1(a, 0, 10, root);
    BFS(root);
    cout << endl;
    return 0;
}



