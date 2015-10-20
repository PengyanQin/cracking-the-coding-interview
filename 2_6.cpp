//
//  2_6.cpp
//  
//
//  Created by Pengyan Qin on 6/17/15.
//
//
#include <iostream>
#include <unordered_map>

using namespace std;

struct node{
    int key;
    node* next;
    node(int x):key(x), next(nullptr){}
};

node* createCircular(){
    node *head = new node(3);
    node *a = new node(4);
    head->next = a;
    node *b = new node(5);
    a->next = b;
    node *c = new node(6);
    b->next = c;
    node *d = new node(7);
    c->next = d;
    d->next = b;
    return head;
}

// hash table
void circular(node *head){
    if(!head)
        return;
    unordered_map<node*, bool> map;
    while(head->next){
        if(map[head] == false){
            map[head] = true;
            head = head->next;
        }
        else{
            cout << head->key << endl;
            return;
        }
    }
}

// fast pointer and slow pointer
void circular1(node *head){
    node *fast = head;
    node *slow = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    cout << fast->key << endl;
    return;
}

int main(){
    node *head = createCircular();
    circular(head);
    circular1(head);
    return 0;
}



