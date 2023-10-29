//C++ program to create a class template
#include <iostream>
using namespace std;

template <typename t1,typename t2>
class Pair{
    t1 x;
    t2 y;
    public:
      Pair(){}
      Pair(t1 a,t2 b){
        x=a;
        y=b;
      }
      void show();

      template <typename t3,typename t4>
      friend Pair<t3,t4> operator+(Pair<t3,t4>,Pair<t3,t4>);
};

template <typename t1,typename t2>
void Pair<t1,t2>::show(){
    cout<<"( "<<x<<" , "<<y<<" )\n";
}

template <typename t3,typename t4>
Pair<t3,t4> operator+(Pair<t3,t4> p1,Pair<t3,t4> p2){
    Pair<t3,t4> pair;
    pair.x=p1.x+p2.x;
    pair.y=p1.y+p2.y;
    return pair;
}

int main(){
    Pair <int,int> a(8,9);
    Pair <int,int> b(56,78);
    Pair <int,int> c=a+b;
    cout<<"Sum of pairs: ";
    c.show();
    
    cout<<"Sum of pairs: ";
    Pair<string,float> st1("Learning ",23.5);
    Pair<string,float> st2("templates",78.9);
    Pair<string,float> st3=st1+st2;
    st3.show();
    return 0;
}