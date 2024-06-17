// <-----JAI SHREE RAM----->//
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int left = 0;
    int right = n - 1;

    // calculating prefix and suffix sum
    int sumFromLeft = a[0];
    int sumFromRight = a[n - 1];
    int ans = 0;

    while (left < right)
    {
        if (sumFromLeft == sumFromRight)
        {
            ans = max(ans, left + 1 + n - right);
        }

        if (sumFromLeft <= sumFromRight)
        {
            left++;
            sumFromLeft += a[left];
        }
        else if (sumFromRight < sumFromLeft)
        {
            right--;
            sumFromRight += a[right];
        }
    }

    cout << ans << endl;
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