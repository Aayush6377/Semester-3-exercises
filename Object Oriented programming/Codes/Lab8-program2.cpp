// Program to demonstrate multilevel inheritance
#include <iostream>
using namespace std;

class Student{
  protected:
     string Name;
     string Class;
     int roll;
  public:
     void set(string n,string c,int r){
         Name=n;
         Class=c;
         roll=r;
     }
};

class Test : public Student{
  protected:
     int DSA;
     int OOP;
     int DEC;
  public:
     void set_marks(int dsa, int oop, int dec){
         DSA=dsa;
         OOP=oop;
         DEC=dec;
     }
};

class Result: public Test{
    private:
      int total;
      double percentage;
    public:
      void calculate(){
          total=DSA+DEC+OOP;
          percentage=total/3;
      }
      void details(){
         cout<<"Name: "<<Name<<endl;
         cout<<"Class: "<<Class<<endl;
         cout<<"Roll no.: "<<roll<<endl;
         cout<<"Marks:-\n";
         cout<<"DSA: "<<DSA<<"/100"<<endl;
         cout<<"DEC: "<<DEC<<"/100"<<endl;
         cout<<"OOP: "<<OOP<<"/100"<<endl;
         cout<<"Percentage: "<<percentage<<"%"<<endl;
     }
};

int main(){
    Result ra;
    ra.set("Rahul","3A2",1121);
    ra.set_marks(65,87,23);
    ra.calculate();
    ra.details();
    return 0;
}
