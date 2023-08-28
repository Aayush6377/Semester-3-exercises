//program to implement inline function
#include <iostream>
using namespace std;

inline void swapp(float &a,float &b){
    float temp=a;
    a=b;
    b=a;
}

int main(){
    float a=12.2;
    float b=45.3;
    cout<<"Before swapping: a="<<a<<", b="<<b<<endl;
    swapp(a,b);
    cout<<"After swapping: a="<<a<<", b="<<b<<endl;
    return 0;
}
