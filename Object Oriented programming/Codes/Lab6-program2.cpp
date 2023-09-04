//Program to overload unary operator using friend function
#include <iostream>
using namespace std;

class Point{
  private:
     int x,y,z;
  public:
     Point(){
         x=y=z=0;
     }
     Point(int x, int y, int z){
         this->x=x;
         this->y=y;
         this->z=z;
     }
     void display(){
         cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
     }
     friend Point operator++(Point &);
};

Point operator++(Point &p){
    p.x++;
    p.y++;
    p.z++;
    return p;
}

int main(){
    Point p1(12,56,78);
    p1.display();
    cout<<"After using post increment operator\n";
    ++p1;
    p1.display();
    return 0;
}
