//
//  7_6.cpp
//  
//
//  Created by Pengyan Qin on 7/7/15.
//
//

#include <iostream>
#include <map>
#include <cmath> // abs()

using namespace std;

// line -> hash key -> hash value(frequency of lines)
struct point{
    double x, y;
};

struct line{
private:
    double slope, intercept, epsilon;
    bool bslope;
public:
    line():slope(0), intercept(0), bslope(false){}
    
    line(double slope_, double intercept_)
    :slope(slope_), intercept(intercept_), bslope(true){}
    
    line(point p1, point p2){
        double epsilon = 0.0001;
        if(abs(p1.x - p2.x) < epsilon){
            bslope = false;
            intercept = p1.x;
        }
        else{
            bslope = true;
            slope = (p1.y - p2.y)/(p1.x - p2.x);
            intercept = p1.y - slope * p1.x;
        }
    }
    
    int map_key(){
        int sl = (int) slope*1000;  // preserve 3 digits
        int in = (int) intercept*1000;
        return sl*1000 + in;
    }
    
    void print(){
        if(bslope)
            cout << "y = " << slope << "*x + " << intercept << endl;
        else
            cout << "x = " << intercept << endl;
    }
};

line findbestline(point *ptr, int pt_num){
    map<int,int> mymap;
    line bestline;
    int max = 0;
    for(int i = 0; i < pt_num; ++i){
        for(int j = i + 1; j < pt_num; ++j){
            line l(*(ptr + i), *(ptr + j));
            mymap[l.map_key()]++;
            
            if(mymap[l.map_key()] > max){
                max = mymap[l.map_key()];
                bestline = l;
            }
        }
    }
    return bestline;
}

int main(){
    int pt_num = 5;
    point *p = new point[pt_num];
    double xx[5] = {1, 2, 3, 2, 2};
    double yy[5] = {1, 2, 3, 4, 7};
    for(int i = 0 ; i < 5; ++i){
        p[i].x = xx[i];
        p[i].y = yy[i];
    }
    line bestline = findbestline(p, pt_num);
    bestline.print();
}





