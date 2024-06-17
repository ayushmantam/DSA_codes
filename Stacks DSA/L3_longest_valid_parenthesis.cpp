
#include<iostream>
using namespace std;
#include<stack>

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1); //-1 length nikalne ke liye
        int maxlen=0;
        for(int i=0;i<s.length();i++){
          char ch=s[i];
          if(ch=='('){
            st.push(i); // '(' ka index push kar rhe hai
          } 
          else{//(ch==')')
            st.pop();
            if(st.empty()){
              st.push(i);
            }
            else{
              int len=i-st.top();
              maxlen=max(len,maxlen);
            }
          }
        }
          return maxlen;

    }
};