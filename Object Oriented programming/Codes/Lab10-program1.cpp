//C++ program for throwing an exception
#include <iostream>
using namespace std;

int main(){
    float a,b;
    printf("Enter two numbers: ");
    cin>>a>>b;

    try{
        if (b==0){
            throw "Divided by 0 exception";
        }
        cout<<a<<"/"<<b<<" = "<<a/b<<endl;
    }
    catch(const char* error){
        cout<<error<<endl;
    }
    catch(...){
        cout<<"Some exceptional error has occurred"<<endl;
    }
}

