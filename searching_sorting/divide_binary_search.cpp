#include <iostream>
using namespace std;
int solve(int dividend, int divisor)
{
    int s = 0;
    int e = abs(dividend);
    int mid = s + (e - s) / 2;
    int ans = 1;
    while (s <= e)
    {
        // perfact solution
        if (abs(mid * divisor) == abs(dividend))
        {
            return mid;
        }
        // not perfact
        if (abs(mid * divisor) > abs(dividend))
        {
            e = mid - 1; // left s
        }
        else
        {
            // ans store
            ans = mid;
            // right search
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    if ((divisor < 0 && dividend < 0) || divisor > 0 && dividend > 0)
    {
        return ans;
    }
    else
    {
        return -ans;
    }

    return ans;
}
int main()
{
    int dividend = 22;
    int divisor = -7;
    int ans = solve(dividend, divisor);
    cout << "ans is " << ans << endl;
    return 0;
}