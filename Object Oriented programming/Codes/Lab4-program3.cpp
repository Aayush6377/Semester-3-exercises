//Create a class Time that store hours and minutes.Inside it create a function that returns sum of two time.
#include <iostream>
using namespace std;

class Time{
    private:
      int hour;
      int min;
    public:
     void set_time(int h,int m){
         min=m%60;
         hour=h%24+m/60;
     }
     Time add_time(Time b){
         Time c;
         c.min=(min+b.min)%60;
         c.hour=(hour+b.hour)%24+(min+b.min)/60;
         return c;
     }
     void print_time(){
         cout<<hour<<" hr "<<min<<" mins"<<endl;
     }
};

int main(){
    Time a,b;
    int hour,min;
    cout<<"Enter time 1: ";
    cin>>hour>>min;
    a.set_time(hour,min);
    cout<<"Time 1: ";
    a.print_time();
    
    cout<<"Enter time 2: ";
    cin>>hour>>min;
    b.set_time(hour,min);
    cout<<"Time 2: ";
    b.print_time();
    
    Time t=a.add_time(b);
    cout<<"Sum: ";
    t.print_time();
    return 0;
}
