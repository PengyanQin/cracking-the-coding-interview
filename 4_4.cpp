//
//  4_4.cpp
//  
//
//  Created by Pengyan Qin on 6/26/15.
//
//

#include <iostream>
#include <list>
#include <vector>
#include <queue>

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

// BFT traversal
// use two queue to alternate store different depth of nodes
vector<list<node*> > ll_depty(node* root){
    queue<node*> q[2];  // used to store nodes of different depth
    int cur = 0;
    int prev = 1;
    q[cur].push(root);
    
    list<node*> l;
    l.push_back(root);
    vector<list<node*> > res;
    res.push_back(l);

    while(!q[cur].empty()){
        cur = !cur;
        prev = !prev;
        l.clear();
        while(!q[prev].empty()){
            node *tmp = q[prev].front();
            q[prev].pop();
            if(tmp->left){
                l.push_back(tmp->left);
                q[cur].push(tmp->left);
            }
            if(tmp->right){
                l.push_back(tmp->right);
                q[cur].push(tmp->right);
            }
        }
        res.push_back(l);
    }
    return res;
}

//don't use queue, since list can use iterator
//take advantage of vector can access by []
vector<list<node*> > ll_depth(node *root){
    vector<list<node*> > res;
    list<node*> li;
    li.push_back(root);
    res.push_back(li);
    int depth = 0;
    while(!res[depth].empty()){
        list<node*> l;
        for(list<node*>::iterator it = res[depth].begin(); it != res[depth].end(); ++it){
            node* n = *it;
            if(n->left)
                l.push_back(n->left);
            if(n->right)
                l.push_back(n->right);
        }
        res.push_back(l);
        ++depth;
    }
    return res;
}

/*
 
 the first method use two queues to access different level of nodes
 use FIFO property of queue to traverasal nodes(left->right) in each depth
 
 the second method take advantage of vector[] to access different leverl of nodes
 use list:iterator to traversal nodes (left->right) in each depth
 */

int main(){
    node *root = new node(8);
    int a[8] = {11, 3, 18, 9, 6, 13, 4, 1};
    int num = 8;
    for(int i = 0; i < num; ++i){
        insert(root, a[i]);
    }
    
    vector<list<node*> > res = ll_depty(root);
    vector<list<node*> > res1 = ll_depth(root);
    for(int i = 0; i < res.size(); ++i){
        for(list<node*>::iterator it = res[i].begin(); it != res[i].end(); ++it){
            cout << (*it)->data << " ";
        
        }
        cout << endl;
    }
    
    for(int i = 0; i < res1.size(); ++i){
        for(list<node*>::iterator it = res1[i].begin(); it != res1[i].end(); ++it){
            cout << (*it)->data << " ";
            
        }
        cout << endl;
    }
    return 0;
}



