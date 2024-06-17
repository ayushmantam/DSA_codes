#include <iostream>
using namespace std;
#define PI 3.1415
#define MAXX (x, y)(x > y ? x : y)
float circlearea(float r)
{
    return PI * r * r;
}
void fun(){
    int a=9;
    int b=3;
    int c=MAXX(a,b);
}
int main()
{
    cout << circlearea(2.0) << endl;
   