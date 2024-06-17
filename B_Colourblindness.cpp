// <-----JAI SHREE RAM----->//
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define py printf("YES\n");
#define pn printf("NO\n");
#define pans cout << ans << endl;
#define Sort(a) sort(a.begin(), a.end())

void parr(vector<int> &a)
{
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        py return;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == 'R' || s2[i] == 'R')
        {
            if (s1[i] != s2[i])
            {
                pn return;
            }
        }
    }
    py return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}