#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Recursive function to explore all possible word combinations
    void solve(string s, vector<string>& result, unordered_set<string>& dict,
               vector<string>& current) {
        // Base case: if the remaining string is empty
        if (s.length() == 0) {
            // Construct a space-separated string from the current vector
            string str = "";
            for (auto it : current) {
                str += it + " ";
            }
            // Remove the trailing space and add the result to the final vector
            str.pop_back();  //romving last space
            result.push_back(str);
            return;
        }

        // Iterate through all possible substrings of 's'
        for (int i = 0; i < s.length(); i++) {
            // If the current substring is in the word dictionary
            if (dict.count(s.substr(0, i + 1))) {
                // Add the current substring to the 'current' vector
                current.push_back(s.substr(0, i + 1));

                // Recursively explore the remaining part of the string
                solve(s.substr(i + 1), result, dict, current);
                // s.substr(i + 1) gives substring form i+1
                // Backtrack: remove the last added word before exploring other possibilities
                current.pop_back();  
            }
        }
    }

    // Main function to break the input string into words
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Initialize vectors to store the final result and the current word combination
        vector<string> result, current;

        // Convert the wordDict vector to an unordered_set for efficient lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // Start the recursive exploration to find all valid word combinations
        solve(s, result, dict, current);

        // Return the final result
        return result;
    }
};
