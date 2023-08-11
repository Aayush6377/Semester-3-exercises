//Program to create a class 'Part' and create two objects of it.
#include <iostream>
using namespace std;
class Part{
    private:
      int Modelnumber;
      int Partnumber;
      float Cost;
    public:
      void setpart(int m,int p,float c){
          Modelnumber=m;
          Partnumber=p;
          Cost=c;
      }
      void printpart(){
          cout<<"Model number: "<<Modelnumber<<endl;
          cout<<"Part number: "<<Partnumber<<endl;
          cout<<"Cost: "<<Cost<<endl;
      }
};

int main(){
    Part p1,p2;
    
    cout<<"Part 1"<<endl;
    p1.setpart(6245,3454,900);
    p1.printpart();
    
    cout<<endl<<"Part 2"<<endl;
    p1.setpart(5543,2133,430.56);
    p1.printpart();
    return 0;
}
