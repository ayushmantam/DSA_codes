#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i, j, k) for (ll i = j; i < k; i++)

void solve() {
    string s;
    cin >> s;
    int x = s[0];
    int y = s[1]-'0';

    for (int i = 'a'; i <= 'a'+7; i++) {
        for (int j = 8; j >= 1; j--) {
            if (j == y || i == x) {
                string ans="";
                ans += (char)i;
                ans += (char)(j + '0');
                if(ans!=s)
                cout << ans << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
