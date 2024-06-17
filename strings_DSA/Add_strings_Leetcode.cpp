#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
class Solution {
public:
    string addStrings(string num1, string num2) {
    // Reverse the input strings to make the addition easier
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // Initialize variables for the result and carry
    string result = "";
    int carry = 0;

    // Determine the maximum length of the two numbers
    int len1 = num1.size();
    int len2 = num2.size();
    int max_len = max(len1, len2);

    // Loop through the digits of both numbers
    for (int i = 0; i < max_len; i++) {
        // Get the digits at the current position or 0 if the position is out of range
        int digit1 = (i < len1) ? (num1[i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[i] - '0') : 0;

        // Calculate the sum of the current digits and the carry
        int total = digit1 + digit2 + carry;

        // Calculate the carry for the next iteration
        carry = total / 10;

        // Append the current digit to the result
        result += to_string(total % 10);
    }

    // If there is a carry left after the loop, append it to the result
    if (carry) {
        result += to_string(carry);
    }

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());

    return result;
}
};