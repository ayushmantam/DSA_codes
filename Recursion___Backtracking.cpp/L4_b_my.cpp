// <-----JAI SHREE RAM----->//
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define pans cout << ans << endl;
#define Sort(a) sort(a.begin(), a.end())
// rest 0 contest 1 gym 2
int solveRec(vector<int> &a, int index, int last)
{
    if (index == 0)
    { // last day
        if (a[index] == 0)
        { // all closed
            return 1;
        }
        if (a[index] == 1 || a[index] == 2 || a[index] == 3)
        { // koi to kuhla hai
            return 0;
        }
    }

    int restdays = 0;
    if (a[index] == 0)
    {
        restdays += solveRec(a, index + 1, 0);
    }

    if (a[index] == 1)
    { // contest
        restdays += min(solveRec(a, index + 1, 0), solveRec(a, index + 1, 1));
    }

    if (a[index] == 2)
    {
        restdays += min(solveRec(a, index + 1, 0), solveRec(a, index + 1, 2));
    }

    return restdays;
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
    int firstDayActivity = a[0];
    int ans = solveRec(a, n, firstDayActivity);
    pans
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}