//
//  4_9_2.cpp
//  
//
//  Created by Pengyan Qin on 7/2/15.
//
//  the path is start from root

#include <iostream>
#include <vector>

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

void find_sum(node *n, int sum, vector<int> &res){
    if(n == nullptr){
        res.push_back(0);
        return;
    }
    int tmp = 0;
    res.push_back(n->data);
    for(int i = 0; i < res.size(); ++i)
        tmp += res[i];
    if(tmp == sum){
        for(int i = 0; i < res.size(); ++i)
            cout << res[i] << " ";
        cout << endl;
    }
    find_sum(n->left, sum, res);
    res.pop_back();
    find_sum(n->right, sum, res);
    res.pop_back();
}

int main(){
    node *root = nullptr;
    int a[]= {8, 3, 11, -1, 7, 9, 14, 1};
    for(int i = 0; i < 8; ++i)
        insert(root, a[i]);
    int sum = 11;
    vector<int> res;
    find_sum(root, sum, res);
    return 0;
}
