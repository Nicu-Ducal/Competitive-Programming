#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m, a[25][25], v[25], maxsum = 0;

ll suma()
{
    ll ans = 0;
    for (ll j = 1; j <= m; j++)
    {
        ll sumcol = 0;
        for (ll i = 1; i <= n; i++)
            sumcol += a[i][j] * v[i];
        ans += abs(sumcol);
    }
    return ans;
}

void flip(ll k)
{
    if (k > n)
        maxsum = max(maxsum, suma());
    else
    {
        v[k] = 1;
        flip(k + 1);
        v[k] = -1;
        flip(k + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("flip.in");
    ofstream cout("flip.out");

    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            cin >> a[i][j];

    flip(1);
    cout << maxsum;

    return 0;
}
