//
//  3_7.cpp
//  
//
//  Created by Pengyan Qin on 6/24/15.
//
//

#include <iostream>
#include <queue>

using namespace std;
// it is tricky to think of using separate queues for dog and cat
// and number the animals`
class shelter{
    queue<int> cat, dog;
    int order;
public:
    shelter():order(0) {}
    void enqueue(string s){
        if(s == "cat")
            cat.push(++order);
        else{
            dog.push(++order);
        }
    }
    
    int dequeueDog(){
        int i = dog.front();
        dog.pop();
        return i;
    }
    
    int dequeueCat(){
        int i = cat.front();
        cat.pop();
        return i;
    }
    
    int dequeueAny(){
        int tmp;
        if(cat.front() < dog.front()){
            tmp = cat.front();
            cat.pop();
        }
        else{
            tmp = dog.front();
            dog.pop();
        }
        return tmp;
    }
};

int main(){
    shelter ms;
    ms.enqueue("cat"); // 1
    ms.enqueue("cat"); // 2
    ms.enqueue("dog"); // 3
    cout << ms.dequeueAny() << endl;
    cout << ms.dequeueDog() <<  endl;
    return 0;
}



