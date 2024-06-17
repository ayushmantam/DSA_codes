#include <iostream>
using namespace std;
class Animal
{
public:
    void speak()
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

    Animal a;
    a.speak();

    Dog d;
    d.speak();
    return 0;
}