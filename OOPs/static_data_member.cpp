#include <iostream>
using namespace std;
class abc
{
public:
    static int x, y;
    void print() const
    {
        // this is pointer type parameter for particluar object
        cout << x << " " << y << endl;
    }
};
int main()
{
    abc obj1, obj2;
    obj1.x = 1;
    obj1.y = 2;
    obj1.print();
    obj2.x = 4;
    obj2.y = 5;
    obj2.print();
    return 0;
}
