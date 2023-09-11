//Program to overload binary '+' operator to add two complex numbers
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
        Complex operator+(Complex&);
};

Complex Complex::operator+(Complex &c){
    Complex temp;
    temp.real=real+c.real;
    temp.img=img+c.img;
    return temp;
}

int main(){
    Complex a(23,5);
    Complex b(12,34);
    Complex c=a+b;
    cout<<"a = ";
    a.display();
    cout<<"b = ";
    b.display();
    cout<<"a + b = ";
    c.display();
    return 0;
}