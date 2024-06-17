#include <iostream>
using namespace std;
class Animal
{
public:
    Animal()
    {
        cout << "I am inside Animal constructor\n";
    }
    virtual void speak()
    {
        cout << "speaking\n";
    };
};

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "I am inside Dog constructor\n";
    }
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
    //virtual keyword ke
    Animal *a = new Animal();
    cout << endl;
    Animal *b = new Dog(); // jis type ka obejct ( Dog ) usi ka function call hoga
    cout << endl;
    Dog *c = new Dog();
    cout << endl;
    Dog *d = (Dog *)new Animal();
    cout << endl;
}