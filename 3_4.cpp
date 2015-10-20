//
//  3_4.cpp
//  
//
//  Created by Pengyan Qin on 6/24/15.
//
//

#include <iostream>
#include <stack>

using namespace std;

//normal recursive
void hannoi(int n, char src, char bri, char dst){
    if(n == 1){
        cout << "move " << n << " from " <<  src << " to " << dst << endl;
    }
    else{
        hannoi(n-1, src, dst, bri);
        cout << "move " << n << " from " <<  src << " to " << dst << endl;
        hannoi(n-1, bri, src, dst);
    }
}

// using stack without output
void shannoi(int n, stack<int> *src, stack<int> *bri, stack<int> *dst){
    if(n == 0)
        return;
    shannoi(n-1, src, dst, bri);
    dst->push(n);
    src->pop();
    shannoi(n-1,bri, src, dst);
}

//using stack with output

struct op{
    int begin, end;
    char src, bri, dst; //  there are 1~n disks slide onto tower src move them to dst and
    op() {}
    op(int begin_, int end_, char src_, char bri_, char dst_)
    :begin(begin_), end(end_), src(src_), bri(bri_), dst(dst_) {}
};

void hannoi1(int n, char src, char bri, char dst){
    stack<op> st;
    op tmp;
    st.push(op(1, n, src, bri, dst));
    while(!st.empty()){
        tmp = st.top();
        st.pop();
        if(tmp.begin != tmp.end){
            st.push(op(tmp.begin, tmp.end-1, tmp.bri, tmp.src, tmp.dst));
            st.push(op(tmp.end, tmp.end, tmp.src, tmp.bri, tmp.dst));
            st.push(op(tmp.begin, tmp.end-1, tmp.src, tmp.dst, tmp.bri));
        }
        else{
            cout << "move " << tmp.begin << " from " << tmp.src << " to " << tmp.dst << endl;
        }
    }
}
    
int main(){
    hannoi1(3, 'A', 'B', 'C');
    
    /*
    stack<int> src1;
    stack<int> bri1;
    stack<int> dst1;
    stack<int> *src = &src1;
    stack<int> *bri = &bri1;
    stack<int> *dst = &dst1;
    src->push(3);
    src->push(2);
    src->push(1);
    shannoi(3, src, bri, dst);
    cout << src->size() << endl;
    cout << bri->size() << endl;
    cout << dst->size() << endl;
    cout << dst->top() << endl;
    return 0;
     */
}

