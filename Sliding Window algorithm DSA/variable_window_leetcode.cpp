#include<iostream>
using namespace std;
#include<vector>
#include<climits>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int start = 0;
        int end = 0;
        int minlength = INT_MAX; // Initialize to a large value
        int sum = 0;

        while (end < nums.size()) {
            sum += nums[end];
            
//window ko minimize karna
            while (sum >= target) {
                minlength = std::min(minlength, end - start + 1);
                sum -= nums[start];
                start++;
            }

            end++;
        }

        return (minlength == INT_MAX) ? 0 : minlength;
    }
};