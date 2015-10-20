//
//  7_3.cpp
//  
//
//  Created by Pengyan Qin on 7/6/15.
//
//

#include <iostream>
#include <cmath>  // for abs()
using namespace std;

// pay attention: limitations of floating point representations, never check for equality
// with ==, check if the difference is less than an epsilon value
struct point{
    int x;
    int y;
    point() {}
    point(int x_, int y_):x(x_), y(y_) {}
};

struct line{
    point p1;
    point p2;
    line () {}
    line(point p1_, point p2_):p1(p1_), p2(p2_){}
};

struct line1{
    double slope;
    double intercept;
    line1() {}
    line1(double slope_, double intercept_): slope(slope_), intercept(intercept_) {}
};

// line is composed of two points
// assumption: the point is integer value, the same line regarded as intersect
// pay attention: slop is double type
bool is_intersect(line l1, line l2){
    double epsilon = 0.001;
    int x11 = l1.p1.x;
    int y11 = l1.p1.y;
    int x12 = l1.p2.x;
    int y12 = l1.p2.y;
    
    int x21 = l1.p1.x;
    int y21 = l1.p1.y;
    int x22 = l1.p2.x;
    int y22 = l1.p2.y;
    
    if((x11 == x12) && (x21 == x22)){ // two lines are all vertical
        if(x11 == x22){  // same line
            cout << "the two lines are the same" << endl;
            return true;
        }
        else            // parallel lines
            return false;
    }
    else if((x11 == x12) || (x21 == x22)){ // only one line is vertical
        return true;
    }
    else{  // no line is vertical
        double slop1 = (y12 - y11)/(x12 - x11);
        double slop2 = (y22 - y21)/(x22 - x21);
        if(abs(slop1 - slop2) < epsilon){
            if(abs((y12 - slop1*x12)-(y22 - slop2*x22)) < epsilon){ // same line
                cout << "the two lines are the same" << endl;
                return true;
            }
            else              // parallel lines
                return false;
        }
        else
            return true; // intersect lines
    }
}

// line is composed of slope and intercept
// assumption: the same line is regarded as intercept
bool is_intersect1(line1 l1, line1 l2){
    double epsilon = 0.001;
    if(abs(l1.slope - l2.slope) > epsilon) // intercept
        return true;
    else{
        if(abs(l1.intercept - l2.intercept) < epsilon){  // same line
            cout << "the two lines are the same" << endl;
            return true;
        }
        else  // parallel
            return  false;
    }
}

int main(){
    point p1(1, 1);
    point p2(3, 3);
    point p3(1, 2);
    point p4(2, 2);
    point p5(2, 0);
    point p6(0, -2);
    line l1(p1, p2);
    line l2(p1, p2);
    cout << is_intersect(l1, l2) << endl;
    
    line1 ll1(5, 7);
    line1 ll2(5, 9);
    line1 ll3(8, 1);
    cout << is_intersect1(ll1, ll2) << endl;
    cout << is_intersect1(ll1, ll3) << endl;
}




