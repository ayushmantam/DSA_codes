#include <iostream>
using namespace std;
#include <limits.h>
int solve(int n, int x, int y, int z)
{
    // base case
    if (n == 0) // length of rod is zero
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MAX;
    }

    int ans1 = 1 + solve(n - x, x, y, z);
    int ans2 = 1 + solve(n - y, x, y, z);
    int ans3 = 1 + solve(n - z, x, y, z);

    int ans = max(ans1, max(ans2, ans3));
    return ans;
}

int main()
{
    int n = 7;
    int ans = solve(7, 5, 2, 2);
    if(ans==INT_MIN){
        cout<<"no way of doing this"<<endl; 
    }
    cout << "ans is:" << ans << endl;
}