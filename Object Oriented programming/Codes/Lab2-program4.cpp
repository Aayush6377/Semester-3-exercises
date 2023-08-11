//Program to create a class 'Part' and demonstrate the concept of array of objects
#include <iostream>
using namespace std;
class Part{
    private:
      int Modelnumber;
      int Partnumber;
      float Cost;
    public:
      void setpart(int,int,float);
      void printpart();
};

void Part::setpart(int m,int p,float c){
    Modelnumber=m;
    Partnumber=p;
    Cost=c;
}
void Part::printpart(){
    cout<<"Model number: "<<Modelnumber<<endl;
    cout<<"Part number: "<<Partnumber<<endl;
    cout<<"Cost: "<<Cost<<endl;
}
int main(){
    Part parts[3];
    
    for (int i=0;i<3;i++){
        int m,p;
        float c;
        cout<<"For Part "<<i+1<<endl;
        cout<<"Enter Model no., Part no., cost: ";
        cin>>m,p,c;
        parts[i].setpart(m,p,c);
        cout<<endl;
    }
    
    cout<<endl;
    for (int i=0; i<3; i++){
        parts[i].printpart();
        cout<<endl;
    }
    return 0;
}
