//Demonstrate how arguments can be passed from a derived class constructor to a base class constructor
#include <iostream>
using namespace std;

class Base{
  protected:
    int x;
  public:
    Base(int x){
        this->x=x;
    }
    void value(){
        cout<<"Value of x from base class: "<<x<<endl;
    }
};

class Derived:public Base{
  int y;
  public:
    Derived(int x,int y):Base(x){
        this->y=y;
    }
    void value(){
        cout<<"Value of x from derived class: "<<x<<endl;
        cout<<"Value of y from derived class: "<<y<<endl;
    }
};

int main(){
    cout<<"Calling base value() function from base class object:-\n";
    Base b(8);
    b.value();
    cout<<"Calling derived value() function from derived class object:-\n";
    Derived d(12,34);
    d.value();
    cout<<"Calling base value() function from derived class object:-\n";
    d.Base::value();
    return 0;
}
