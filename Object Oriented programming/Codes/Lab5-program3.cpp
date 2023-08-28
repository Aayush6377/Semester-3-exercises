//program to implement inline function
#include <iostream>
using namespace std;

inline void vol(float &a,float &b,float &c){
    cout<<"Volume of cuboid: "<<a*b*c<<endl;
}

int main(){
    float a,b,c;
    cout<<"Enter dimensions: ";
    cin>>a>>b>>c;
    vol(a,b,c);
    return 0;
}
