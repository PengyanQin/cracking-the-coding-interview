//
//  17_13.cpp
//  
//
//  Created by Pengyan Qin on 7/22/15.
//
//

#include <iostream>

using namespace std;

struct BiNode{
    int data;
    BiNode *node1, *node2;
};

struct NodePair{
    BiNode *head;
    BiNode *tail;
    NodePair():head(nullptr), tail(nullptr){}
    NodePair(BiNode *head_, BiNode *tail_):head(head_), tail(tail_){}
};

void insert(BiNode *&root, int val){
    if(root == nullptr){
        BiNode* ptr = new BiNode();
        ptr->data = val;
        ptr->node1 = nullptr;
        ptr->node2 = nullptr;
        root = ptr;
        return;
    }
    if(val <= root->data)
        return insert(root->node1, val);
    if(val > root->data)
        return insert(root->node2, val);
}

void InOrderPrint(BiNode *root){
    if(root == nullptr)
        return;
    InOrderPrint(root->node1);
    cout << root->data << " ";
    InOrderPrint(root->node2);
}

// method 1: take advantage of the structure NodePair to represent the linked list
void concat(BiNode *n, BiNode *m){
    n->node2 = m;
    m->node1 = n;
}
NodePair convert(BiNode *root){
    if(root == nullptr)
        return NodePair();
    NodePair part1 = convert(root->node1);
    NodePair part2 = convert(root->node2);
    if(part1.tail != nullptr)
        concat(part1.tail, root);
    if(part2.head != nullptr)
        concat(root, part2.head);
    return NodePair(part1.head == nullptr ? root : part1.head, part2.tail == nullptr ? root : part2.tail);
}

void print_NodePair(NodePair np){
    BiNode *runner = np.head;
    while(runner){
        cout << runner->data << " ";
        runner = runner->node2;
    }
    cout << endl;
}

// method 2: don't use the NodePair structure, only return BiNode
BiNode* convert1(BiNode *root){ // the structure is not bad
    if(root == nullptr)
        return nullptr;
    BiNode* left = convert1(root->node1);
    BiNode* right = convert1(root->node2);
    if(left == nullptr){
        if(right != nullptr){
            root->node2 = right;
            right->node1 = root;
        }
        return root;
    }
    else{
        BiNode *tmp = left;
        while(tmp->node2){
            tmp = tmp->node2;
        }
        tmp->node2 = root;
        root->node1 = tmp;
        root->node2 = right;
        if(right != nullptr){
            right->node1 = root;
        }
        return left;
    }
}

BiNode* convert11(BiNode *root){
    if(root == nullptr)
        return nullptr;
    BiNode* left = convert1(root->node1);
    BiNode* right = convert1(root->node2);
    if(left != nullptr){
        BiNode *tmp = left; // tmp is the tail of left part of linked list
        while(tmp->node2){
            tmp = tmp->node2;
        }
        concat(tmp, root);
    }
    if(right != nullptr)
        concat(root, right);
    return left == nullptr ? root : left;
}

void print_BiNode(BiNode *head){
    while(head){
        cout << head->data << " ";
        head = head->node2;
    }
    cout << endl;
}

//method 3: Circular Linked List
BiNode* convert_circular(BiNode *root){
    if(root == nullptr)
        return nullptr;
    cout << root->data << endl;
    BiNode* part1 = convert_circular(root->node1);
    BiNode* part3 = convert_circular(root->node2);
    
    if(part1 == nullptr && part3 == nullptr){
        root->node1 = root;
        root->node2 = root;
        return root;
    }
    BiNode *tail3 = (part3 == nullptr) ? nullptr : part3->node1;
    if(part1 == nullptr){
        concat(part3->node1, root);
    }
    else{
        concat(part1->node1, root);
    }
    
    if(part3 == nullptr){
        concat(root, part1);
    }
    else{
        concat(root, part3);
    }
    
    if(part1 != nullptr && part3 != nullptr)
        concat(tail3, part1);
    return part1 == nullptr ? root : part1;
}

BiNode* convert2(BiNode *root){
    BiNode *head = convert_circular(root);
    head->node1->node2 = nullptr;
    head->node1 = nullptr;
    return head;
}

int main(){
    int A[] = {5, 1, 6, 3, 0};
    int n = 5;
    BiNode *root = nullptr;
    for(int i = 0; i < n; ++i)
        insert(root, A[i]);
    InOrderPrint(root);
    cout << endl;
    /*
    NodePair np = convert(root);
    print_NodePair(np);
    */
    BiNode *head = convert2(root);
    print_BiNode(head);

}

