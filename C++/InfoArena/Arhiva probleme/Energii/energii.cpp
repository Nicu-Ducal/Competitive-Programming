#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, e, v, c;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("energii.in");
    ofstream cout("energii.out");

    cin >> n >> e;

    ll dp[2][e + 1];
    dp[0][0] = dp[1][0] = 0;
    for (ll j = 1; j < e + 1; j++)
        dp[0][j] = dp[1][j] = 2e9;
    for (ll i = 1; i <= n; i++)
    {
        cin >> v >> c;
        for (ll j = 1; j <= e; j++)
        {
            if (j <= v)
                dp[1][j] = min(c, dp[0][j]);
            else
                dp[1][j] = min(c + dp[0][j - v], dp[0][j]);
        }
        for (ll j = 1; j <= e; j++)
            swap(dp[0][j], dp[1][j]);
    }

    if (dp[1][e] == 2e9)
        cout << -1;
    else
        cout << dp[1][e];

    return 0;
}
