#include <iostream>
using namespace std;
#include <vector>
// NO of ways for reaching nth stais
int ClimbStairsRec(int n)
{
    // base case: Stopping condition
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return ClimbStairsRec(n - 1) + ClimbStairsRec(n - 2);
}

int ClimbStairsMem(int n, vector<int> &dp)
{
    // base case: Stopping condition
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = ClimbStairsMem(n - 1, dp) + ClimbStairsMem(n - 2, dp);
    return dp[n];
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);

    return ClimbStairsMem(n, dp);
}

int main()
{
    int ans = climbStairs(3);
    cout << ans << endl;
}
