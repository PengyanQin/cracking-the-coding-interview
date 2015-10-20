//
//  2_1.cpp
//  
//
//  Created by Pengyan Qin on 6/15/15.
//
//

#include <iostream>
#include <unordered_map> // for unordered_map

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
// space complexity: O(n)， use a temporary buffer
void remove_dup(node* head){
    if(!head)
        return;
    unordered_map<int, bool> map;
    node* walker =  head;
    map[head->key] = 1;
    while(walker->next){
        if(map[walker->next->key]){
            node* del = walker->next;
            walker->next = walker->next->next;
            delete del;
        }
        else{
            map[walker->next->key] = 1;
            walker = walker->next;
        }
    }
    return;
}

// time complexity:O(n^2)
// space complexity: O(1)
void remove_dup1(node *head){
    if(!head)
        return;
    node *cur = head;
    node *runner = head;
    while(cur){
        runner = cur;
        while(runner->next){
            if(cur->key == runner->next->key){
                node *del = runner->next;
                runner->next = del->next;
                delete del;
            }
            else{
                runner = runner->next;
            }
        }
        cur = cur->next;
    }
    return;
}

int main(){
    int a[10] = {2, 2, 4, 5, 2, 7, 9, 10, 15, 15};
    int n = 10;
    node* head = init(a, n);
    print(head);
    remove_dup1(head);
    print(head);
    return 0;
}






