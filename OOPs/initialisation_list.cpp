#include <iostream>
using namespace std;
class abc
{
    /*mutable*/ int x;
    int *y;
    // const naam ka promise breakkar skate hain mutable keyword se
public:
    abc()
    {
        x = 0;
        y = new int(0);
    }
    abc(int x, int y)
    {
        this->x = x;
        this->y = new int(y);
    }
    void setx(int val)
    {
        x = val;
    }
    // int getx(){
    //     return x;
    // }
    int getx() const
    {
        // if x, mutable
        // x=10; we can change or update x
        return x;
    }
    void sety(int val)
    {
        *y = val;
    }
    int gety() const
    {
        return *y;
    }
    // int gety()
    // {
    //     int f = 20;
    //     y = &f;
    //     return *y;
    // }
};
void printABC(const abc &a)
{
    // a.setx(10); //non const function call guve error  because humne abc ko const liya hai
    cout << a.getx() << " " << a.gety() << endl;
}

int main()
{
    abc a;
    cout << a.getx() << endl;
    cout << a.gety() << endl;

    abc A(2, 3);
    printABC(A);
}