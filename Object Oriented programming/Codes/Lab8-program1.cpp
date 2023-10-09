// Program to inherit Student class using single inheritance
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

class Result : public Student{
  private:
     int DSA;
     int OOP;
     int DEC;
     int total;
     double percentage;
  public:
     void set_marks(int dsa, int oop, int dec){
         DSA=dsa;
         OOP=oop;
         DEC=dec;
         total=dsa+oop+dec;
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
    Result obj;
    obj.set("Aayush Kukreja","3C1",159);
    obj.set_marks(78,89,90);
    obj.details();
    return 0;
}
