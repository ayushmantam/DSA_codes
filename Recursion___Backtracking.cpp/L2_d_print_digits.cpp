#include <iostream>
using namespace std;

int countdigits(int num, int &count)
{
    if (num == 0)
    {
        return 0;
    }

    count++;
    return countdigits(num / 10, count);
}

void printDigits(int num)
{
    if (num == 0)
    {
        return;
    }

    // 1 case solve
    int newValueOfnum = num / 10;

    printDigits(newValueOfnum);

    int digit = num % 10;

    cout << digit << " ";
}

void print(int num)
{
    if (num == 0)
    {
        return;
    }
    int numby10 = num / 10;
    print(numby10);
    cout << num % 10 << " ";
}
int main()
{
    int num = 347;

    // int count=0;
    // int ans=countdigits(num,count);
    // cout<<ans<<endl;

    // printDigits(num );
    print(num);
}