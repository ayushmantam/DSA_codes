#include <iostream>
using namespace std;
class abc{
    int x;
    int *y;
    abc(int _x,int _y): x(_x),y(new int(_y)){}
};
int main(){
    return 0;
}