/*A point on the two dimensional plane can be represented by two numbers: an X coordinate and a Y coordinate.
For example, (4,5) represents a point 4 units to the right of the origin along the X axis and 5 units up the Y axis.
The sum of two points can be defined as a new point those X coordinate is the sum of the X coordinates of the points and whose Y coordinate is the sum of their Y coordinates.
Write a program that uses a structure called point to model a point.*/
#include <iostream>
using namespace std;

struct point{
    int x,y;
};

int main(){
    struct point p1,p2,p3;
    cout<<"Enter 1st co-ordinate: ";
    cin>>p1.x>>p1.y;
    cout<<"Enter 2nd co-ordinate: ";
    cin>>p2.x>>p2.y;
    
    p3.x=p2.x+p1.x;
    p3.y=p2.y+p1.y;
    
    cout<<"Sum: ("<<p3.x<<" , "<<p3.y<<")"<<endl;
    return 0;
}
