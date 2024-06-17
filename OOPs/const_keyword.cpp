#include <iostream>
using namespace std;
int main()
{
    const int a = 4;
    // a=10;   //this will give error
    // intilisaion can be done but we cant reassign a value
    cout << a << endl;
    /*this can not be done in modern compiler
    int *p=&a;
    *p=5;
    cout<<a<<endl;
    */
}