#include <iostream>
using namespace std;

class Mammals{
    public:
       void who(){
           cout<<"I am a mammal\n";
       }
};

class MarineAnimals{
    public:
       void who(){
           cout<<"I am marine animal\n";
       }
};

class BlueWhale: public Mammals, public MarineAnimals{
    public:
       void who(){
           cout<<"I belong to both the categories: Mammals as well as Marine Animals\n";
       }
};

int main(){
    Mammals mam;
    MarineAnimals mar;
    BlueWhale blue;
    
    cout<<"Function of Mammals by the object of Mammals:-\n";
    mam.who();
    cout<<"Function of MarineAnimals by the object of MarineAnimals:-\n";
    mar.who();
    cout<<"Function of BlueWhale by the object of BlueWhale:-\n";
    blue.who();
    cout<<"Function of Mammals by the object of BlueWhale:-\n";
    blue.Mammals::who();
    cout<<"Function of MarineAnimals by the object of BlueWhale:-\n";
    blue.MarineAnimals::who();
    return 0;
}
