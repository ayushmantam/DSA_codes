#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> preSmallerElement(vector<int> &input)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());

    // left to right->prev smaller
    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        // chhota element mil chuka hai->ans store

        ans[i] = s.top();
    }
}
vector<int> NextSmaller(vector<int> &input)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());
    for (int i = input.size() - 1; i >= 0; i--)
    {
        int curr = input[i];

        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int>ans1=NextSmaller(v);
    cout << "Printing " << endl;
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }

    cout<<endl;    
    vector<int>ans2=preSmallerElement(v);
    cout << "Printing " << endl;
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
}

//tc
// jaruri nhi hai ki two loops hai tho time comlexicity n^2 hogi


//  THIS IS LEETCODE QUESTION