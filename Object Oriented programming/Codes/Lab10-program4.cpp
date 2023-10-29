//C++ program to create a function template
#include <iostream>
using namespace std;

template <typename type>
type fmax(type a,type b){
    cout<<"Max of "<<a<<" and "<<b<<": ";
    if (a>=b) return a;
    if (a<b) return b;
}

int main(){
    cout<<fmax(34,87)<<endl;
    cout<<fmax(45.56,12.45)<<endl;
    cout<<fmax('A','K')<<endl;
    cout<<fmax("OOP","DSA")<<endl;
    return 0;
}