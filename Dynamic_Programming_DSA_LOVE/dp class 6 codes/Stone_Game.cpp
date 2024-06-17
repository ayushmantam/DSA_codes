#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(vector<int>& piles, int n, int alice, int bob, int index) {
        if (index >= n / 2) {
            if (alice > bob) {
                return true;
            } else {
                return false;
            }
        }

        if (index + 1 < n) {
            int SS = solve(piles, n, alice + piles[index], bob + piles[index + 1], index + 2);
            int EE = solve(piles, n, alice + piles[n - 1 - index], bob + piles[n - 1 - index], index + 1);
            int ES = solve(piles, n, alice + piles[n - 1 - index], bob + piles[index], index + 1);
            int SE = solve(piles, n, alice + piles[index], bob + piles[n - 1 - index], index + 1);
            return SS || EE || ES || SE;
        } else {
            // Handle the case where index + 1 is out of bounds
            return solve(piles, n, alice + piles[index], bob, index + 1);
        }
    }
    bool solve(vector<int>& piles, int n, int alice, int bob, int index,vector<vector<vector<int>>>&dp) {
        if (index >= n / 2) {
            if (alice > bob) {
                return true;
            } else {
                return false;
            }
        }
        if(dp[index][alice][bob]!=-1){
            return dp[index][alice][bob];
        }
        if (index + 1 < n) {
            int SS = solve(piles, n, alice + piles[index], bob + piles[index + 1], index + 2,dp);
            int EE = solve(piles, n, alice + piles[n - 1 - index], bob + piles[n - 1 - index], index + 1,dp);
            int ES = solve(piles, n, alice + piles[n - 1 - index], bob + piles[index], index + 1,dp);
            int SE = solve(piles, n, alice + piles[index], bob + piles[n - 1 - index], index + 1,dp);
            return dp[index][alice][bob]=SS || EE || ES || SE;
        } else {
            // Handle the case where index + 1 is out of bounds
            return dp[index][alice][bob]=solve(piles, n, alice + piles[index], bob, index + 1,dp);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int alice = 0;
        int bob = 0;
        int index = 0;
        int n = piles.size();
        // return solve(piles, n, alice, bob, index);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>((500*500)+1,vector<int>(500*500+1,-1)));
        return solve(piles, n, alice, bob, index,dp);
    }
};

// four combination 
// ss
// ee
// es
// se
