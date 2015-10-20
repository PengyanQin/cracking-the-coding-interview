//
//  4_1.cpp
//  
//
//  Created by Pengyan Qin on 6/25/15.
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

//recursive function
// from top to bottom, when it reaches bottom, means the above parent nodes are all balanced
// height(leaf) = 0
// time complexity: O(nlogn)
int height(node *ptr){
    if(ptr == 0)
        return 0;
    return max(height(ptr->left), height(ptr->right)) + 1;
}
bool is_balanced(node *ptr){
    if(ptr == nullptr)
        return true;  // base case
    int bal_factor = abs(height(ptr->left) - height(ptr->right));
    if(bal_factor > 1)
        return false;
    else
        return is_balanced(ptr->left) && is_balanced(ptr->right);

}

// improve the efficiency, check balance while calculating height

int checkheight(node *root){
    if(root == nullptr)
        return 0;
    int left = checkheight(root->left);
    if(left == -1)
        return -1;
    int right = checkheight(root->right);
    if(right == -1)
        return -1;
    int dif = abs(left - right);
    if(dif > 1)
        return -1;
    else
        return max(left, right) + 1;
}

bool is_balanced1(node *root){
    int check = checkheight(root);
    if(check == -1)
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
    cout << "the height of the first tree is " << height(root1) << endl;
    cout << is_balanced1(root1) << endl; //balanced

    node *root2 = new node(8);
    int b[6] = {3, 9, 13, 4, 1, 14};
    int num2 = 6;
    for(int i = 0; i < num2; ++i){
        insert(root2, b[i]);
    }
    cout << "the height of the first tree is " << height(root2) << endl;
    cout << is_balanced1(root2) << endl; //not balanced
}



