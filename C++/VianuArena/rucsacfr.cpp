#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

bool raport(pair <ll, ll> i1, pair <ll, ll> i2)
{
    double r1 = (double) i1.se / i1.fi;
    double r2 = (double) i2.se / i2.fi;
    return (r2 < r1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("rucsacfr.in");
    ofstream cout("rucsacfr.out");

    ll n, k;
    cin >> n >> k;

    pair <ll, ll> ob[n];
    for (ll i = 0; i < n; i++)
        cin >> ob[i].fi >> ob[i].se;

    sort(ob, ob + n, raport);
    double ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (k >= ob[i].fi)
        {
            ans += ob[i].se;
            k -= ob[i].fi;
        }
        else
        {
            ans += ((double) k / ob[i].fi) * ob[i].se;
            break;
        }
    }
    cout.precision(2);
    cout << fixed << ans;
    return 0;
}
