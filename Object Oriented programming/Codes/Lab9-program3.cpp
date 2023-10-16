//Demonstrate the concept of abstract class and pure virtual function
#include <iostream>
using namespace std;

class Vehicle{
  public:
     virtual void details()=0;
};

class Car:public Vehicle{
  string Model;
  string color;
  float price;
  public:
     Car(string m,string c, float p){
         Model=m;
         color=c;
         price=p;
     }
     void details(){
         cout<<"Car details:-\n";
         cout<<"Model: "<<Model<<endl;
         cout<<"Color: "<<color<<endl;
         cout<<"Prize: "<<price<<endl;
     }
};

class Bike:public Vehicle{
  string Model;
  string color;
  float price;
  public:
    Bike(string m,string c, float p){
         Model=m;
         color=c;
         price=p;
     }
     void details(){
         cout<<"Bike details:-\n";
         cout<<"Model: "<<Model<<endl;
         cout<<"Color: "<<color<<endl;
         cout<<"Prize: "<<price<<endl;
     }
};

int main(){
    Vehicle* a=new Car("Honda City","White",1600000);
    a->details();
    cout<<endl;
    Vehicle* b=new Bike("Honda SP 125","Red",200000);
    b->details();
    return 0;
}
