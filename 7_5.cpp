//
//  7_5.cpp
//  
//
//  Created by Pengyan Qin on 7/6/15.
//
//

#include <iostream>
#include <cmath>  // for abs()
using namespace std;

// "line": is a line defined by a slope and a y-intercept? Or by any two points on the line?
// Or should the line be reallly a line segment, which starts and ends at the edges of the squares

struct line{
    double slope;
    double intercept;
    line():slope(0), intercept(0){}
    line(double slope_, double intercept_): slope(slope_), intercept(intercept_){}
};

struct square{
    double top;
    double  bottom;
    double  left;
    double  right;
    square(): top(0), bottom(0), left(0), right(0){}
    square(double top_, double bottom_, double left_, double right_)
    :top(top_), bottom(bottom_), left(left_), right(right_){}
};

line cut_square(square s1, square s2){
    double epsilon = 0.001;
    double x1 = (s1.left + s1.right)/2;
    double y1 = (s1.top + s1.bottom)/2;
    double x2 = (s2.left + s2.right)/2;
    double y2 = (s2.top + s2.bottom)/2;
    
    if(abs(x1 - x2) < epsilon){  // vertical line
        cout << "x = " << x1 << endl;
        return line();
    }
    else{   // normal line
        double slope = (y2 - y1)/(x2 - x1);
        double intercept = y2 - slope*x2;
        line l(slope, intercept);
        return l;
    }
}

int main(){
    square s1(3, 1, 1, 3);
    square s2(4, 0, 0, 4);
    line res = cut_square(s1, s2);
    cout << "y = " << res.slope << "x + " << res.intercept << endl;
}

