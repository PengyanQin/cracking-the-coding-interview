//
//  2_7.cpp
//  
//
//  Created by Pengyan Qin on 6/17/15.
//
//

#include <iostream>
#include <stack>
using namespace std;

struct node{
    int key;
    node* next;
    node() {}
    node(int x):key(x), next(nullptr){}
};

node* init(int a[], int n){
    node* head = nullptr;
    node* q = nullptr;
    for(int i = 0; i < n; ++i){
        node *p = new node;
        p->key = a[i];
        p->next = nullptr;
        if(i == 0){
            head = p;
            q = p;
        }
        else{
            q->next = p;
            q = p;
        }
    }
    return head;
}

void print(node* head){
    node *walker = head;
    while(walker->next){
        cout << walker->key << " ";
        walker = walker->next;
    }
    cout << walker->key << endl;
    
    return;
}

// use stack
// time complexity: O(n)
// space complexity: O(n)
bool is_palindrome(node *head){
    int length = 1;
    node *cur = head;
    while(cur->next){
        length++;
        cur = cur->next;
    }
    stack<int> s;
    cur = head;
    for(int i = 0; i < length/2; ++i){
        s.push(cur->key);
        cur = cur->next;
    }
    if(length%2)
        cur = cur->next;
    
    while(cur){
        if(s.top() == cur->key){
            s.pop();
            cur = cur->next;
        }
        else
            return false;
    
    }
    return true;
}

// take advantage of the feature of the palindrome, original = reverse
// time complexity: O(n)
// space complexity: O(n)
bool is_palindrome1(node *head){
    node *cur = head;
    node *rhead = nullptr;
    while(cur){
        node *ptr = new node(cur->key);
        ptr->next = rhead;
        rhead = ptr;
        cur = cur->next;
    }
    while(rhead && head){
        if(rhead->key == head->key){
            rhead = rhead->next;
            head = head->next;
        }
        else
            return false;
    }
    return true;
}

int main(){
    int a[] = {2, 3, 1, 1, 3, 2};
    int n = 6;
    int b[] = {2, 3, 1, 1, 3, 5};
    int m = 6;
    node* head1 = init(a, n);
    node* head2 = init(b, m);
    print(head1);
    print(head2);
    cout << is_palindrome1(head1) << endl;
    cout << is_palindrome1(head2) << endl;
    
    return 0;
}




