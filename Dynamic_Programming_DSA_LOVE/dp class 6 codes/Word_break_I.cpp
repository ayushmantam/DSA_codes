#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(string &s, unordered_set<string> &dict, int index,
               vector<int>& dp) {
        if (index >= s.length()) {
            return dp[index] = true;
        }

        if (dp[index] != -1) {
            return dp[index];
        }
        for (int i = index; i < s.length(); i++) {
            string str = s.substr(index, (i - index) + 1);
            if (dict.count(str)) {
                cout << str << endl;
                if (solve(s, dict, i + 1, dp)) {
                    return dp[index] = true; // Continue exploring after finding
                                             // a valid substring
                }
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string &s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto str : wordDict) {
            dict.insert(str);
        }

        // return solve(s, dict, 0);
        vector<int> dp(s.length() + 1, -1);
        return solve(s, dict, 0, dp);
    }
};