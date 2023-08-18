//Input and display data of 5 employees using array of objects and constructors in C++
#include <iostream>
using namespace std;
class Employee{
  private:
     string Name;
     float salary;
     string DOB;
  public:
     static int i;
     Employee(){
         cout<<"For "<<i<<" employee"<<endl;
         cout<<"Enter Name: ";
         cin>>Name;
         cout<<"Enter DOB: ";
         cin>>DOB;
         cout<<"Enter salary: ";
         cin>>salary;
         i++;
     }
     void display(){
         cout<<"Name: "<<Name<<endl;
         cout<<"DOB: "<<DOB<<endl;
         cout<<"Salary: "<<salary<<endl;
     }
};

int Employee::i=1;
int main(){
    Employee arr[5];
    cout<<endl;
    for (int i=0; i<5; i++){
        cout<<"Employee "<<i+1<<endl;;
        arr[i].display();
        cout<<endl;
    }
    return 0;
}
