#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int require(string myString, string other, unordered_map<char, int> freqOther)
    {
        for (auto ch : myString)
        {
            if (freqOther[ch] > 0)
                freqOther[ch]--;
        }
        int count = 0;
        for (auto it : freqOther)
        {
            count += it.second;
        }
        return count;
    }
    int minSteps(string s, string t)
    {
        unordered_map<char, int> freqS;
        for (auto ch : s)
        {
            freqS[ch]++;
        }
        unordered_map<char, int> freqT;
        for (auto ch : t)
        {
            freqT[ch]++;
        }
        int totalreq = require(s, t, freqT) + require(t, s, freqS);
        return totalreq;
    }
};