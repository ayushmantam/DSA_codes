// <-----JAI SHREE RAM----->//
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define pans cout << ans << endl;
#define Sort(a) sort(a.begin(), a.end())

/*
arr= 1 -4 10 -5 15 20 -100 25

way1 all time op2
1 3 13 8 23 43 57 82

way2 only one time at -100
1 -3 7 2 17 37 63 (63+25)=88

way3 one time at -5
1 -3 7 2 17 --- -ve
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int minProfit = LONG_LONG_MAX;
    int minIndex = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        sum += a[i];
        if (minProfit > sum)
        {
            minProfit = sum;
            minIndex = i;
        }
    }

    // op2 at minIndex;
    minProfit=abs(minProfit);
    int maxProfit=abs(minProfit);
    for (int i = minIndex + 1; i < n; i++)
    {
        maxProfit += a[i];
    }

    cout << maxProfit << endl;
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