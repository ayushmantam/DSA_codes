#include <iostream>
using namespace std;
int main()
{

    // int*a=new int;
    // *a=2;
    // cout<<*a<<endl;
    // //to remove memory leak
    // delete a;
    // int b=5;
    // a=&b;
    // cout<<*a<<endl;

    // const with pointer
    const int *a = new int(2); // const data created and non const pointer
   //equal to previous line's codeN int const *a= =new int(2);
    cout << *a << endl;
    // *a=2; cant be update
    int b = 20;
    a = &b; // pointer can be re-assigned
    cout << *a << endl;

    // hum  pointer ka content/data tho modifiy nhi kar sakter par poiner ko modify kar sakte hai
}