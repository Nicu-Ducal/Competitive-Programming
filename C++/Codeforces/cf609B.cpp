#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> m;

    ll a[n+5], b[n+5], c[n+5];
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) cin >> b[i];

    sort(b + 1, b + n + 1);
    sort(a + 1, a + n + 1);

    ll x;
    ll ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        x = b[i] - a[1] + m;
        x %= m;
        for (int i = 1; i <= n; i++)
            c[i] = (a[i] + x) % m;
        sort (c + 1, c + n + 1);
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (c[i] != b[i])
            {
                flag = 0;
                break;
            }
        if (flag) ans = min(ans, x);
    }

    cout << ans;
    return 0;
}
