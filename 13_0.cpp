//
//  13_0.cpp
//  
//
//  Created by Pengyan Qin on 7/17/15.
//
//

#include <iostream>

using namespace std;

template <class T>
class ShiftedList{
private:
    T* array;
    int size;
    int offsize;
    int convert(int n){
        int ind = n - offsize;
        if(ind < 0)
            ind += size;
        return ind;
    }

public:
    ShiftedList(int size_):size(size_), offsize(0){ // constructor
        array = new T[size];
    }
    ~ShiftedList(){ // destructor
        delete[] array;
    }
    // don't forget the original offsize
    void shiftedby(int n){ // shift left
        offsize = (offsize + n) % size; // offsize >= 0 && offsize <= size
    }
    T getVal(int n){
        return array[convert(n)];
    }
    void setVal(int n, T val){
        array[convert(n)] = val;
    }
};

int main(){
    int lsize = 4;
    ShiftedList<int> *slist = new ShiftedList<int>(lsize);
    for(int i = 0; i < lsize; ++i){
        slist->setVal(i, i);
    }
    cout << slist->getVal(0) << endl;
    cout << slist->getVal(1) << endl;
    cout << slist->getVal(2) << endl;
    cout << slist->getVal(3) << endl;
    slist->shiftedby(1);
    cout << slist->getVal(0) << endl;
    cout << slist->getVal(1) << endl;
    cout << slist->getVal(2) << endl;
    cout << slist->getVal(3) << endl;
}







