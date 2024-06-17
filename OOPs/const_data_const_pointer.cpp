#include <iostream>
using namespace std;
int main()
{
    const int *const a=new int(3);
    // *a=4;
    // cout<<*a<<endl; //both will give error non changable
    // int b=33;
    // a=&b;
    // cout<<*a<<endl; //both will give error non changable
}