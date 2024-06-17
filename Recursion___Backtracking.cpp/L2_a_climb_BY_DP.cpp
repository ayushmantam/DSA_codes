#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ClimbStairs(int n, vector<int> &dp)
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
        
        int oneStep = ClimbStairs(n - 1, dp);
        int twoStep = ClimbStairs(n - 2, dp);

        dp[n] = oneStep + twoStep;
        return dp[n];
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return ClimbStairs(n, dp);
    }
};