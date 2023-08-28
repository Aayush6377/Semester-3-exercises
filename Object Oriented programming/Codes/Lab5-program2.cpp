//Program to implement concept of destructors
#include <iostream>
using namespace std;

class Books{
  private:
    static int i;
    int data;
  public:
    Books(){
        i++;
        cout<<i<<"th object constructor call\n";
    }
    ~Books(){
        cout<<i<<"th object destructor call\n";
        i--;
    }
};
int Books::i=0;

int main(){
    Books b1,b2,b3;
    return 0;
}
