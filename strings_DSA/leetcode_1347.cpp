#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> freq;
        for (auto ch : s) {
            freq[ch]++;
        }
        for (auto ch : t) {
            if (freq[ch] > 0)
                freq[ch]--;
        }
        int count = 0;
        for (auto it : freq) {
            count += it.second;
        }

        return count;
    }
};