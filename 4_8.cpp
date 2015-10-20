//
//  4_8.cpp
//  
//
//  Created by Pengyan Qin on 6/29/15.
//
//

#include <iostream>
#include <string>
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

//check each node and if it is same, check the child node
// time complexity: O(mn) or O(m + n)
bool is_identical(node *p, node *q){
    if(p == nullptr && q == nullptr)
        return true;
    if(p == nullptr || q == nullptr)
        return false;
    if(p->data != q->data)
        return false;
    else
        return is_identical(p->left, q->left) && is_identical(p->right, q->right);
}

bool is_subtree(node *root, node *p){  // check whether p is a subtree of root
    if(root == nullptr)  // big tree empty, small tree cannot find
        return false;
    if(p == nullptr) // the big tree is always a subtree
        return true;
    if(is_identical(root, p))
        return true;
    else
        return is_identical(root->right, p) || is_identical(root->left, p);
}

// get the in order and pre order sequence of two tree, check whether one string
// is the substring of another string, take advantage of suffix tree
// time complexity: O(m + n)

void in_order(node *root, string &res){
    if(root == nullptr){
        res += 'N';
        return;
    }
    in_order(root->left, res);
    res +=  to_string(root->data);
    in_order(root->right, res);
}

void pre_order(node *root, string &res){
    if(root == nullptr){
        res += 'N';
        return;
    }
    res +=  to_string(root->data);
    pre_order(root->left, res);
    pre_order(root->right, res);

}

bool is_substring(string s1, string s2){ // check whether s2 is the substring of s1
    int start = 0;
    int runner = 0;
    while(start + runner < s1.length()){
        if(s1[start + runner] ==  s2[runner]){
            if(runner == s2.length() - 1)
                return true;
            else
                ++runner;
        }
        else{
            ++start;
            runner = 0;
        }
    }
    return false;
}

bool is_subtree1(node *root, node *root1){
    string pre;
    string in;
    in_order(root, in);
    pre_order(root, pre);
    
    string pre1;
    string in1;
    in_order(root, in1);
    pre_order(root, pre1);
    
    if(is_substring(in, in1) && is_substring(pre, pre1))
        return true;
    else
        return false;
}


int main(){
    node *root = nullptr;
    int a[]= {8, 3, 13, 1, 5, 9, 14, 16};
    for(int i = 0; i < 8; ++i)
        insert(root, a[i]);
    
    node *root1 = nullptr;
    int b[] = {13, 9, 14, 16};
    for(int i = 0; i < 4; ++i)
        insert(root1, b[i]);
   
    cout << is_identical(root, root1) << endl;
    cout << is_subtree(root, root1) << endl;
    
    /*
    // test in_order and pre_order
    string in1;
    string pre1;
    in_order(root, in1);
    pre_order(root, pre1);
    cout << in1 << endl;
    cout << pre1 << endl;
     */
    /*
    // test is_substring
    string s1 = "ABCDABCDABDE";
    string s2 = "ABCDABD";
    string s3 = "ABE";
    cout << is_substring(s1, s2) << endl;
    cout << is_substring(s2, s3) << endl;
    */
}






