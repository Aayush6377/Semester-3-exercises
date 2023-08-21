/*Create the equivalent of a four function calculator.The program should request the user to enter a number, an operator and another
number .It should then carry out the specified arithmetical operation: adding. subtracting, multiplying or dividing the two numbers.
(It should use a switch statement to select the operation). Finally it should display the result. When it finishes the calculation, the
program should ask if the user wants to do another calculation.*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){
 float a,b;
 char c;
 while(true){
     cout<<"Enter expression: ";
     cin>>a>>c>>b;
     cout<<"Solution: ";
     switch(c){
      case '+':
         cout<<a+b;
         break;
      case '-':
         cout<<a-b;
         break;
      case '*':
      case 'x':
         cout<<a*b;
         break;
      case '/':
         cout<<a/b;
         break;
      case '^':
         cout<<pow(a,b);
         break;
      default:
         cout<<"No such operator found";
     }
     cout<<endl;
     bool ask;
     cout<<"Do you want to continue (1/0): ";
     cin>>ask;
     if (ask==0) break;
 }
 return 0;
}
