#include<iostream>
using namespace std;
int x=2; //global variable
int main(){
    x=4;   //global x
    int x=20;//local to main fn
    cout<<x<<endl;
    cout<<::x<<endl; //accessing global variable with ::
    ::x=45;
    cout<<::x<<endl;
    {
        x=40;
        cout<<x<<endl;
    }
    return 0;
}
