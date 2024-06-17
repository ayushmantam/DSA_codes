#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void speak()
    {
        cout << "speaking\n";
    };
};

class Dog : public Animal
{
public:
    // function or method overiding
    void speak()
    {
        cout << "Barking\n";
    }
};

// jaha subclass me hume custom function chahiye wha hum fuction overiding kartehai
// warna yadi hume parent class ka function le sakte hai

int main()
{
    
    Animal *a = new Animal();
    a->speak();

    Dog *d = new Dog();
    d->speak();
    /*
        //Upcasting  jab humne parent class ke funtion ke samne "virtual" keyword nhi lagaya hai
        Animal* b=new Dog();
        b->speak();  //output will be: speaking why is it not barking ?
    */

    // for solving above problem we use "virtual" kryword
    // Upcasting
    Animal *b = new Dog();
    b->speak(); // NOW output will be:barking


    // //DownCasting
    // Dog* g= new Animal();   //nhi chalta

     //DownCasting= using downcastings
     Dog* g= (Dog *)new Animal();   //chalta output=barking


}