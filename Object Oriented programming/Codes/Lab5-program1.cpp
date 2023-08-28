//Calculate area of a square using friend function.
#include <iostream>
using namespace std;

class Square{
    private:
      float side;
    public:
      Square(float side){
          this->side=side;
      }
      friend float area(Square);
};

float area(Square sq){
    return sq.side*sq.side;
}

int main(){
    float a;
    cout<<"Enter side: ";
    cin>>a;
    Square sq(a);
    cout<<"Area: "<<area(sq);
    return 0;
}
