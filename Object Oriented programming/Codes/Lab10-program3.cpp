//C++ program for re-throwing an exception
#include <iostream>
using namespace std;

int main(){
    float a,b;
    cout<<"Enter two numbers (2nd should be +ve): ";
    cin>>a>>b;
    try{
        if (b<0){
            throw b;
        }
        try{
            if (b==0){
                throw "Divide by zero exception";
            }
            cout<<a<<"/"<<b<<" = "<<a/b;
        }
        catch(const char* c){
            throw;
        }
    }
    catch(float b){
        cout<<b<<" is a negative number";
    }
    catch(const char *c){
        cout<<c;
    }
    catch(...){
        cout<<"Some exception has occurred"<<endl;
    }
    return 0;
}