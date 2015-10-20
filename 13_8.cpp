//
//  13_8.cpp
//  
//
//  Created by Pengyan Qin on 7/18/15.
//
//

#include <iostream>

using namespace std;
/*
 * The smart pointer class needs pointer to both the object itself and to the ref count.
 * These must be pointer, rather than the actual object or ref count value, since the goal 
 * of a smart pointer is that the ref count is tracked across multiple smart pointers to one
 * object.
 */

template <class T>
class smartPointer{
private:
    T* ref;
    unsigned int *ref_cnt;
    void remove(){
        cout << "clear " << *ref << " " << *ref_cnt << endl;
        delete ref;
        delete ref_cnt;
        ref = nullptr;
        ref_cnt = nullptr;
    }
public:
    smartPointer(T* ptr_){ // ref can get memory form main, while ref_count need assign memory
        cout << "pointer constructor " << *ptr_ << endl;
        ref = ptr_;
        ref_cnt = new unsigned int;
        *ref_cnt = 1;
    }
    
    smartPointer(smartPointer<T> &spt){
        cout << "smartPointer constructor" << endl;
        ref = spt.ref;
        ref_cnt = spt.ref_cnt;
        *ref_cnt += 1;
    }
    
    ~smartPointer(){
        cout << "destructor run " << *ref << " " << *ref_cnt << endl;
        *ref_cnt -= 1;
        if(*ref_cnt == 0){
            cout << "destructor clear" << endl;
            remove();
        }
    }
    
    smartPointer<T>& operator=(smartPointer<T> &spt){
        cout << "operator overloading" << endl;
        if(this == &spt){
            *ref_cnt += 1;
        }
        else{
            *ref_cnt -= 1;
            if(*ref_cnt == 0){
                cout << "operator clear" << endl;
                remove();
            }
            ref = spt.ref;
            ref_cnt = spt.ref_cnt;
            *ref_cnt += 1;
        }
        return *this;
    }
    
    T getVal(){
        return *ref;
    }
    
    unsigned getRefCnt(){
        return *ref_cnt;
    }
};

int main(){
    int *p1 = new int();
    *p1 = 1111;
    int *p2 = new int();
    *p2 = 2222;
    smartPointer<int> sp1(p1), sp2(p2);
    smartPointer<int> spa = sp1;
    //sp2 = spa;
    cout << sp1.getVal() << " " << sp1.getRefCnt() << endl;
    cout << sp2.getVal() << " " << sp2.getRefCnt() << endl;
    return 0;

}





