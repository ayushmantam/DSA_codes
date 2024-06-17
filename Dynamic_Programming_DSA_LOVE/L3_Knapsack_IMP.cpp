#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

// index =index of last element
int SolveByRecursion(int weight[], int value[], int index, int capacity)
{
    if (index == 0)
    {
        if (weight[0] <= capacity) // last weight can be fit
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    // include exclude
    int include = 0;
    if (weight[index] <= capacity) // capacity - weight[index]  should be positive
        include = SolveByRecursion(weight, value, index - 1, capacity - weight[index]) + value[index];

    int exclude = 0 + SolveByRecursion(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int SolveByMem(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    // include exclude
    int include = 0;
    if (weight[index] <= capacity)
        include = SolveByMem(weight, value, index - 1, capacity - weight[index], dp) + value[index];

    int exclude = 0 + SolveByMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

// int SolveByTab(int weight[],int value[],int index,int capacity){
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
//     for
// }
int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // int ans=SolveByRecursion(weight,value,n-1,capacity);
    // cout<<"Ans: "<<ans<<endl;

    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    int ans = SolveByMem(weight, value, n - 1, capacity, dp);
    cout << "Ans: " << ans << endl;

    // cout << "Ans: " << ans << endl;

    return 0;
}