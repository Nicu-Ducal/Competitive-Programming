#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ll a[n + 1], s[n + 1], p[m + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            s[i] = a[i];
        }
        for (ll i = 1; i <= m; i++)
            cin >> p[i];

        sort(p + 1, p + m + 1);
        sort(s + 1, s + n + 1);

        ll sorted[n + 1];
        for (ll i = n; i > 0; i--)
            if (i == p[m])
                sorted[i] = 1;
            else
                sorted[i] = 0;
        for (ll i = m - 1; i > 0; i--)
            sorted[p[i]] = sorted[p[i] + 1] + 1;
        /*
        for (ll i = 1; i <= n; i++)\
            cout << sorted[i] << ' ';
        cout << '\n'; */

        ll i = 1;
        while (i != n)
        {
            if (sorted[i] == 0)
            {
                i++;
                continue;
            }
            sort(a + i, a + i + sorted[i] + 1);
            i += sorted[i];
        }
        /*
        for (ll i = 1; i <= n; i++)
            cout << a[i] << " "; */

        bool good = 1;
        for (ll i = 1; i <= n; i++)

            if (a[i] != s[i])
            {
                cout << "NO\n";
                good = 0;
                break;
            }
        if (good)
            cout << "YES\n";
    }

    return 0;
}
