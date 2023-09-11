//Program to overload binary '+' operator to add two complex numbers using friend function
#include <iostream>
using namespace std;

class Complex{
    private:
        float real;
        float img;
    public:
        Complex(float r=0, float i=0){
            real=r;
            img=i;
        }
        void display(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }
        friend Complex operator+(Complex&,Complex&);
};

Complex operator+(Complex &c,Complex &d){
    Complex temp;
    temp.real=d.real+c.real;
    temp.img=d.img+c.img;
    return temp;
}

int main(){
    Complex a(9.12,90);
    Complex b(22.21,5.6);
    Complex c=a+b;
    cout<<"a = ";
    a.display();
    cout<<"b = ";
    b.display();
    cout<<"a + b = ";
    c.display();
    return 0;
}