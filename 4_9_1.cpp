//
//  4_9_1.cpp
//  do not have parent node
//
//  Created by Pengyan Qin on 7/2/15.
//
//

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

void print_path(vector<int> path, int level){
    for(int i = level; i < path.size(); ++i)
        cout << path[i] << " ";
    cout << endl;
}

void find_sum(node* n, int sum, vector<int> &path, int level){
    if(n == nullptr){
        path.push_back(0);
        return;
    }
    path.push_back(n->data);
    int tmp = 0;
    for(int i = level; i > -1; --i){
        tmp += path[i];
        if(tmp == sum)
            print_path(path, i);  // i is the start of the path, level is the end of the path
    }
    find_sum(n->left, sum, path, level+1);
    path.pop_back();
    find_sum(n->right, sum, path, level+1);
    path.pop_back();
}

int main(){
    node *root = nullptr;
    int a[]= {8, 3, 11, -1, 7, 9, 14, 1};
    for(int i = 0; i < 8; ++i)
        insert(root, a[i]);
    int sum = 11;
    vector<int> res;
    find_sum(root, sum, res, 0);
    return 0;
}


