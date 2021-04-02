#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, t[805], sol = 0;

ll cautbin(ll x, ll st, ll dr)
{
    ll left = st - 1;
    ll ans = 0;
    while (st <= dr)
    {
        ll mid = st + (dr - st) / 2;
        if (t[mid] <= x)
        {
            ans = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }
    return (ans == 0) ? 0 : ans - left;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("nrtri.in");
    ofstream cout("nrtri.out");

    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> t[i];
    sort(t + 1, t + n + 1);

    for (ll i = 1; i <= n - 2; i++)
    {
        for (ll j = i + 1; j <= n - 1; j++)
        {
            ll c = cautbin(t[i] + t[j], j + 1, n);
            sol += c;
        }
    }
    cout << sol;
    return 0;
}
