//
//  2_5.cpp
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
// time complexity: O(n + m)
// space complexity: O(1)
void sumLinkedList(node *head1, node *head2){  // use head1 to store the result
    if(!head1){
        head1 = head2;
        return;
    }
    if(!head2)
        return;
    
    int len1 = 1;
    int len2 = 1;
    node *last1 = head1;
    node *last2 = head2;
    while(last1->next){                // step1: get the length of two number
        len1++;
        last1 = last1->next;
    }
    while(last2->next){
        len2++;
        last2 = last2->next;
    }
    if(len1 < len2){                  // step2: make the two number same length
        while(len2 != len1){
            node *p = new node(0);
            last1->next = p;
            last1 = p;
            --len2;
        }
    }
    else if(len1 > len2){
        while(len2 != len1){
            node *p = new node(0);
            last2->next = p;
            last2 = p;
            --len1;
        }
    }
    
    node *cur = head1;
    int add1 = 0;
    while(cur){                        // step3: add each digit
        int sum = cur->key + head2->key + add1;
        if(sum >= 10){
            cur->key = sum%10;
            add1 = 1;
        }
        else{
            cur->key = sum;
            add1 = 0;
        }
        cur = cur->next;
        head2 = head2->next;
    }
    if(add1){                           // step4: check the highest digit
        node *p = new node(1);
        last1->next = p;
        last1 = p;
    }
    return;
    
}

// start from the last node, quite easy to think
// time complexity: O(n)
void reverseLinkedList(node* &head){
    if(!head)
        return;
    node *last = head;
    int length = 1;
    while(last->next){
        length++;
        last = last->next;
    }
    
    for(int i = 1; i < length; ++i){
        node *tmp = last->next;
        last->next = head;
        head = head->next;
        last->next->next = tmp;
    }
}

// start from the first node, a little difficult to think
// time complexity: O(n)
void reverseLL(node* &head){
    if(!head)
        return;
    node *prev = nullptr;
    while(head){
        node *p = head->next;
        head->next = prev;
        prev = head;
        head = p;
    }
    head = prev;
}

void RsumLinkedList(node* &head1, node *head2){  // use head1 to store the result
    if(!head1){
        head1 = head2;
        return;
    }
    if(!head2)
        return;
    
    reverseLinkedList(head1);
    reverseLinkedList(head2);
    int len1 = 1;
    int len2 = 1;
    node *last1 = head1;
    node *last2 = head2;
    while(last1->next){                // step1: get the length of two number
        len1++;
        last1 = last1->next;
    }
    while(last2->next){
        len2++;
        last2 = last2->next;
    }
    if(len1 < len2){                  // step2: make the two number same length
        while(len2 != len1){
            node *p = new node(0);
            last1->next = p;
            last1 = p;
            --len2;
        }
    }
    else if(len1 > len2){
        while(len2 != len1){
            node *p = new node(0);
            last2->next = p;
            last2 = p;
            --len1;
        }
    }
    
    node *cur = head1;
    int add1 = 0;
    while(cur){                        // step3: add each digit
        int sum = cur->key + head2->key + add1;
        if(sum >= 10){
            cur->key = sum%10;
            add1 = 1;
        }
        else{
            cur->key = sum;
            add1 = 0;
        }
        cur = cur->next;
        head2 = head2->next;
    }
    if(add1){                           // step4: check the highest digit
        node *p = new node(1);
        last1->next = p;
        last1 = p;
    }
    reverseLinkedList(head1);
    return;
}

int main() {
/*
    int a[] = {7, 1, 6, 9};
    int al = 4;
    int b[] = {9, 5, 8};
    int bl = 3;
    node *head1 = init(a, al);
    node *head2 = init(b, bl);
    print(head1);
    print(head2);
    sumLinkedList(head1, head2);
    print(head1);
    
    
    int aa[] = {9, 6, 1, 7};
    int aal = 4;
    int bb[] = {8, 5, 9};
    int bbl = 3;
    node *head11 = init(aa, aal);
    node *head22 = init(bb, bbl);
    print(head11);
    print(head22);
    RsumLinkedList(head11, head22);
    print(head11);
 */

// test reverse linked list function
    int ab[] = {6, 1, 7};
    int abl = 3;
    node *head = init(ab, abl);
    print(head);
    reverseLL(head);
    print(head);

    return 0;
}






