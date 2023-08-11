//Swap two values using call by value using C++
#include <iostream>
using namespace std;

void swap(int a, int b){
    int temp=a;
    a=b;
    b=temp;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}

int main(){
    int a,b;
    cout<<"Enter numbers: ";
    cin>>a>>b;
    cout<<"Before swapping"<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"After swapping"<<endl;
    swap(a,b);
    return 0;
}
