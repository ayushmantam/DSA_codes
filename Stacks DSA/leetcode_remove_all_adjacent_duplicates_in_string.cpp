#include<iostream>
using namespace std;
#include<stack>
#include<string>
#include<algorithm>
class Solution {
public:
  string removeDuplicates(string s, int k) {
  stack<pair<char, int>> st;
  for (int i = 0; i < s.length(); i++) {
    if (st.empty() || st.top().first != s[i]) {
      st.push(make_pair(s[i], 1));
    }
    else {
      st.top().second++;
      if (st.top().second == k) {
        st.pop();//pop hoga toh poora pair hoga
      }
    }
  }
  string res = "";
  int a=0;
  while (!st.empty()) {
    res.append(st.top().second,st.top().first);
    st.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}
};