#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int> &stack, int num)
{
    // base case
    if (stack.empty() || (!stack.top() < num))
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();

    // recursive call
    sortedInsert(stack, num);
    stack.push(n);
}

stack<int> sortStack(stack<int> s)
{
    // base stack
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, num);
}
