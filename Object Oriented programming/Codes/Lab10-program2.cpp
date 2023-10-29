//C++ program to throw multiple exception
#include <iostream>
using namespace std;

class range{
    int a;
    public:
       range(int var){
        a=var;
       }
       void what(){
        cout<<a<<" not a positive number"<<endl;
       }
};
class multiple{
    int a;
    public:
       multiple(int v){
        a=v;
       }
       void what(){
        cout<<a<<" is not a multiple of 2"<<endl;
       }
};

int main(){
    int a;
    printf("Enter a positive multiple of 2: ");
    cin>>a;
    try{
        if (a<=0){
            throw range(a);
        }
        if (a%2!=0){
            throw multiple(a);
        }
        cout<<"Yes!!! "<<a<<" is a positive multiple of 2"<<endl;
    }
    catch(range a){
        a.what();
    }
    catch(multiple c){
        c.what();
    }
    catch(...){
        cout<<"Some exception has occurred"<<endl;
    }
    return 0;
}