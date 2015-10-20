//
//  4_1_2.cpp
//  
//
//  Created by Pengyan Qin on 6/26/15.
//
//

#include <iostream>
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

// second definition of balanced tree:
// a balanced tree is defined to be a tree such that no two leaf nodes differ
// in distance from the root by more than one

const int MAX = 100;

void getDepth(node *root, int &d, int &num, int dist[]){
    if(!root)
        return;
    ++d;
    getDepth(root->left, d, num, dist);
    if(root->left == nullptr && root->right == nullptr){  //  whether leaf node
        dist[num++] = d; // record the depth of lead node
    }
    getDepth(root->right, d, num, dist);
    --d;
}

bool is_balanced(node *root){
    if(!root)
        return true;
    
    int d = 0;
    int num = 0;
    int dist[MAX] = {};
    getDepth(root, d, num, dist);
    int min_depth = dist[0];
    int max_depth = dist[0];
    for(int i = 1; i < num; ++i){
        if(min_depth > dist[i])
            min_depth = dist[i];
        if(max_depth < dist[i])
            max_depth = dist[i];
    }
    if(max_depth - min_depth > 1)
        return false;
    else
        return true;
}

int main(){
    node *root1 = new node(8);
    int a[5] = {3, 9, 13, 4, 1};
    int num1 = 5;
    for(int i = 0; i < num1; ++i){
        insert(root1, a[i]);
    }
    cout << is_balanced(root1) << endl; //balanced

    node *root2 = new node(8);
    int b[7] = {3, 9, 13, 4, 1, 14, 16};
    int num2 = 7;
    for(int i = 0; i < num2; ++i){
        insert(root2, b[i]);
    }
    cout << is_balanced(root2) << endl; //not balanced
}


