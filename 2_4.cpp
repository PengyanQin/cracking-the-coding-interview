//
//  2_4.cpp
//  
//
//  Created by Pengyan Qin on 6/16/15.
//
//

#include <iostream>
#include <algorithm>
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

//time complexity : O(n)
// similar to sort idea, only change the value that is out of order
// don't forgest to consider the special case
void partition(node *head, int x){
    if(head == nullptr || head->next == nullptr)
        return;
    node *runner = head;
    node *cur = head;
    bool flag = false;
    while(runner){
        while(cur && cur->key < x)
            cur = cur->next;     // cur->key > x
        
        if(flag == false){
            runner = cur;
            flag = true;
        }
        
        while(runner && runner->key >= x)
            runner = runner->next;  //runner->key < x
        
        if(!runner)
            break;
        else
            swap(cur->key, runner->key);
    }
    return;
}

//time complexity: O(n)
//take advantage of the linked list structure, this method is prefered
void partition1(node* &head, int x){
    node *last = head;
    int length = 1;
    while(last->next){
        length++;
        last = last->next;
    }
    node *p = new node;
    p->next = head;
    head = p;
    node *cur = head;
    for(int i = 0; i < length; ++i){
        if(cur->next->key >= x){
            last->next = cur->next;
            cur->next = cur->next->next;
            last = last->next;
            last->next = nullptr;
        }
        else
            cur = cur->next;
    }
    head = head->next;
    delete p;
}

int main(){
    int a[10] = {7, 3, 25, 5, 6, 7, 9, 2, 15, 3};
    int n = 10;
    int k = 3;
    node* head = init(a, n);
    print(head);
    partition1(head, k);
    print(head);
    return 0;
}







