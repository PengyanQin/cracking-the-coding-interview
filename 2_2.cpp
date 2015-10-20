//
//  2_2.cpp
//  
//
//  Created by Pengyan Qin on 6/16/15.
//
//

#include <iostream>
#include <cassert>

using namespace std;

struct node{
    int key;
    node* next;
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

// time complexity: O(n)
int kth(node* head, int k){
    if(!head)
        return -1;
    int length = 1;
    node *walker = head;
    while(walker->next){
        length++;
        walker = walker->next;
    }
    int n = length - k;
    assert(n >= 0);
    walker = head;
    for(int i = 0; i < n; ++i){
        walker = walker->next;
    }
    return walker->key;
}

// time complexity: O(n)
int kth1(node *head, int k){
    if(!head)
        return -1;
    node *p = head;
    node *q = head;
    for(int i = 1; i < k; ++i){
        q = q->next;
    }
    
    while(q->next){
        p = p->next;
        q = q->next;
    }
    return p->key;
}


int main(){
    int a[10] = {2, 3, 4, 5, 6, 7, 9, 10, 15, 20};
    int n = 10;
    int k = 3;
    node* head = init(a, n);
    print(head);
    cout << kth1(head, k) << endl;
    return 0;
}


