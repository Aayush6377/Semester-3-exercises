/*Create two classes DM and DB which store value of distances. DM stores distances in metres and centimeters and DB in feet and inches.
Write a program that can read values for the class objects and add one object of DM with another object of DB.

Use a friend function to carry out the addition operator. The object that stores the results maybe a DM object or DB object depending on the
units in which the results are required. The display should be in the format of feet and inches or metres and centimetres depending on object on display*/

#include <iostream>
#include <cmath>
using namespace std;

class DB;
class DM{
    float meters,centimeters;
    public:
       DM(float m,float cm){
           meters=m;
           centimeters=cm;
       }
       void display(){
           cout<<"Distance: "<<round(meters)<<" m "<<round(centimeters)<<" cm\n";
       }
       friend DM add(DM,DB);
       friend DB add(DB,DM);
};

class DB{
    float feet,inches;
    public:
       DB(float f,float i){
           feet=f;
           inches=i;
       }
       void display(){
           cout<<"Distance: "<<round(feet)<<" feet "<<round(inches)<<" inches\n";
       }
       friend DM add(DM,DB);
       friend DB add(DB,DM);
};

DM add(DM d1, DB d2){
    DM temp(0,0);
    temp.meters=d1.meters+(3.2808*d2.feet);
    temp.centimeters=d1.centimeters+(d2.inches/2.54);
    return temp;
}
DB add(DB d2, DM d1){
    DB temp(0,0);
    temp.feet=d2.feet+d1.meters*0.3048;
    temp.inches=d2.inches+d1.centimeters*2.54;
    return temp;
}

int main(){
    DM a(2,3);
    DB b(10,5);
    DM c=add(a,b);
    c.display();
    DB d=add(b,a);
    d.display();
    return 0;
}
