//
//  4_9.cpp
//  have parent node
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

// when the path is found, print it out directly
// start from end to begin because the parent of a node is unique
void print_path(node *n, int level){
    vector<int> path;
    for(int i = 0; i < level; ++i){
        path.push_back(n->data);
        n = n->parent;
    }
    while(!path.empty()){
        cout << path.back() << " ";
        path.pop_back();
    }
    cout << endl;
    return;
}

void find_sum(node *n, int sum){ // n is the start node
    if(n == nullptr)
        return;
    int level = 1;
    int s = 0;
    node *tmp = n;
    while(tmp){
        s += tmp->data;  // sum is from n to tmp, the number of node is level
        if(s == sum)
            print_path(n, level);
        tmp = tmp->parent;
        ++level;
    }
    find_sum(n->left, sum);
    find_sum(n->right, sum);
}

int main(){
    node *root = nullptr;
    int a[]= {8, 3, 11, -1, 7, 9, 14, 1};
    for(int i = 0; i < 8; ++i)
        insert(root, nullptr, a[i]);
    int sum = 11;
    find_sum(root, sum);
    return 0;
}









