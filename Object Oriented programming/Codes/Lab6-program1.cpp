//Program to overload unary '-' operator
#include <iostream>
using namespace std;

class Velocity{
    private:
       float v;
    public:
       Velocity(){
           v=0;
       }
       Velocity(float v){
           this->v=v;
       }
       void display(){
           cout<<"Velocity: "<<v<<" m/s"<<endl;
       }
       Velocity operator-();
};

Velocity Velocity::operator-(){
    Velocity temp;
    temp.v=-v;
    return temp;
}

int main(){
    Velocity v1(120);
    v1.display();
    Velocity v2=-v1;
    v2.display();
    return 0;
}
