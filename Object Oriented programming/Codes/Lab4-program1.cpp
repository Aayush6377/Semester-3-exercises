//Implement the four function calculator. Use switch case and functions
#include <iostream>
#include <math.h>
using namespace std;

int main(){
 cout<<"Aayush Kukreja"<<endl;
 cout<<"1/22/FET/BCS/159"<<endl<<endl;
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
