#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("rucsac.in");
    ofstream cout("rucsac.out");

    ll n, g;
    cin >> n >> g;
    pair <ll, ll> ob[n];
    for (ll i = 0; i < n; i++)
        cin >> ob[i].fi >> ob[i].se;

    ll dp[2][g + 1];
    for (ll j = 0; j <= g; j++)
        dp[0][j] = dp[1][j] = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j <= g; j++)
        {
            if (j < ob[i].fi)
                dp[1][j] = dp[0][j];
            else if (j >= ob[i].fi)
                dp[1][j] = max(dp[0][j], ob[i].se + dp[0][j - ob[i].fi]);
        }
        for (ll j = 1; j <= g; j++)
            swap(dp[0][j], dp[1][j]);
    }

    cout << dp[0][g];

    return 0;
}
