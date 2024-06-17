#include <iostream>
using namespace std;
int main()
{
    int *const a = new int(2);
    cout << *a << endl;
    *a = 20; // chal jayega
    cout << *a << endl;

    // int b=29;
    // a=&b;//this will give error bcoz const pointer
    // cout<<*a<<endl;
    return 0;
}