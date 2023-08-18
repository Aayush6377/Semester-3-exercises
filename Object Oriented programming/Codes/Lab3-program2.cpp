//Create student class and display student data of a single student.
#include <iostream>
using namespace std;
class Student{
    private:
       string Name;
       int roll;
       string course;
       string section;
    public:
       Student(string name,int roll,string course, string section){
           this->Name=name;
           this->roll=roll;
           this->course=course;
           this->section=section;
       }
       void display(){
           cout<<"Name: "<<Name<<endl;
           cout<<"Roll no.: "<<roll<<endl;
           cout<<"Course: "<<course<<endl;
           cout<<"Section: "<<section<<endl;
       }
};

int main(){
    Student st("Aayush",159,"Btech CSE","3C1");
    st.display();
    return 0;
}
