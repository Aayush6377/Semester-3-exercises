/*Phone number, such as (212) 767-8900, can be thought of as having three parts: the area code (212), the exchange (767) and the number
(8900). Write a program that uses a structure to store these three parts of a phone number separately.Call the structure phone. Create 
two structure variables of type phone. Initialize one and have the user input a number for the other one. Then display both numbers.
*/
#include <iostream>
using namespace std;

struct phone{
  int area_code;
  int exchange;
  int number;
};
int main(){
    struct phone p1,p2;
    p1.area_code=212;
    p1.exchange=767;
    p1.number=8900;
    
    cout<<"Enter your area code, exchange and number: ";
    cin>>p2.area_code>>p2.exchange>>p2.number;
    
    cout<<"My number is ";
    cout<<"("<<p1.area_code<<") "<<p1.exchange<<"-"<<p1.number<<endl;
    cout<<"Your number is ";
    cout<<"("<<p2.area_code<<") "<<p2.exchange<<"-"<<p2.number<<endl;
    return 0;
}
