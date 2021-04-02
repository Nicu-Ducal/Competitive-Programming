#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n;
ll m[32000][32000];
ll t = 1;

void completare(ll l, ll n, ll i, ll j)
{
    if (n == 1)
    {
        m[i][j] = t;
        m[i][j + 1] = t + 1;
        m[i + 1][j] = t + 2;
        m[i + 1][j + 1] = t + 3;
        t += 4
        return;
    }
    else
    {
        ll x, y = i, j
        completare(l / 2, n - 1, i, j);
        completare(l / 2, n - 1, i, j + l/2);
        completare(l / 2, n - 1, i + l/2, j);
        completare(l / 2, n - 1, i + l/2, j + l/2);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //ifstream cin("z.in");
    //ofstream cout("z.out");

    ll n, k;
    cin >> n >> k;

    pair <ll, ll> coord[k];
    for (ll i = 0; i < k; i++)
        cin >> coord[i].fi >> coord[i].se;

    completare(l, n, 0, 0);

    for (ll i = 0; i < k; i++)
        cout << m[coord[i].fi - 1][coord[i].se - 1] << "\n";

    return 0;
}
