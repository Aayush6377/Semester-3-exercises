/* Write a function called power that takes double values for n and an int value for for p.It returns a double value.Use a default argument of 2 for p so that if this argument is omitted the number will be squared.Write a main function that gets value from the user to test this function.*/
#include <iostream>
using namespace std;
double power(double base,int pow=2){
    double a=1;
    for (int i=0;i<pow;i++){
        a*=base;
    }
    return a;
}

int main(){
    cout<<"Aayush Kukreja"<<endl;
    cout<<"1/22/FET/BCS/159"<<endl;
    double base;
    int p;
    cout<<"Enter base:";
    cin>>base;
    cout<<"Enter power:";
    cin>>p;
    cout<<base<<" ^ "<<p<<" = "<<power(base,p)<<endl;
    return 0;
}