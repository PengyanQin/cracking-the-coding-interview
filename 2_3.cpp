//
//  2_3.cpp
//  
//
//  Created by Pengyan Qin on 6/16/15.
//
//

#include <iostream>

using namespace std;

struct node{
    int key;
    node* next;
};

node* init(int a[], int n, node* &ptr, int k){
    node* head = nullptr;
    node* q = nullptr;
    for(int i = 0; i < n; ++i){
        node *p = new node;
        p->key = a[i];
        p->next = nullptr;
        if(i == (k-1))
            ptr = p;
        
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

// time complexity: O(1)
// space complexity: O(1)

void delete_mid(node *mid){
    if(!mid || mid->next == nullptr) // first node or last node
        return;
    mid->key = mid->next->key;
    node *del = mid->next;
    mid->next = mid->next->next;
    delete del;
}

// in fact, the node can be first or middle node, but can't be the
// last node in the linked list, if delete the node directly, p->next
// will still have an address and undefined

int main(){
    int a[10] = {2, 3, 4, 5, 6, 7, 9, 10, 15, 20};
    int n = 10;
    int k = 5;
    node *mid = nullptr;
    node* head = init(a, n, mid, k);
    cout << mid->key << endl;
    print(head);
    delete_mid(mid);
    print(head);
    return 0;
}










