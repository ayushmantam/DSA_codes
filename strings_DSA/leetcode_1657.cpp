#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
        {
            return false;
        }

        unordered_map<char, int> freq1;
        set<char> charSet1;
        for (auto ch : word1)
        {
            charSet1.insert(ch);
            freq1[ch]++;
        }
        vector<int> freqarr1;
        for (auto it : freq1)
        {
            freqarr1.push_back(it.second);
        }
        sort(freqarr1.begin(), freqarr1.end()); // Sort the frequency array
        vector<char> charArr1(charSet1.begin(), charSet1.end());

        unordered_map<char, int> freq2;
        set<char> charSet2;
        for (auto ch : word2)
        {
            charSet2.insert(ch);
            freq2[ch]++;
        }
        vector<int> freqarr2;
        for (auto it : freq2)
        {
            freqarr2.push_back(it.second);
        }
        sort(freqarr2.begin(), freqarr2.end()); // Sort the frequency array
        vector<char> charArr2(charSet2.begin(), charSet2.end());

        return (freqarr1 == freqarr2) && (charArr1 == charArr2);
    }
};
