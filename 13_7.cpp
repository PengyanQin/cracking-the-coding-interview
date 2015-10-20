//
//  13_7.cpp
//  
//
//  Created by Pengyan Qin on 7/17/15.
//
//

#include <iostream>
#include <map>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node() {}
    node(int data_in):data(data_in), left(nullptr), right(nullptr){}
};

typedef map<node*,node*> nodemap;

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

void InOrerPrint(node* root){
    if(root == nullptr){
        return;
    }
    InOrerPrint(root->left);
    cout << root->data << " ";
    InOrerPrint(root->right);
}

node* copy_recursive(node* ptr, nodemap &nmap){
    if(ptr == nullptr)
        return nullptr;
    
    nodemap::iterator it = nmap.find(ptr);
    if(it != nmap.end()){
        return it->second;
    }
    node* p = new node();
    nmap[ptr] = p;
    p->data = ptr->data;
    p->left = copy_recursive(ptr->left, nmap);
    p->right = copy_recursive(ptr->right, nmap);
    return p;
}

node* complete_copy(node* ptr){
    nodemap nmap;
    return copy_recursive(ptr, nmap);
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
    
    node *copy = complete_copy(root);
    InOrerPrint(copy);
    cout << endl;
    
    cout << "original address " << root << endl;
    cout << "copy address " << copy << endl;
}

