#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--)
    {
        cin >> n;

        ll a[n], b[n], d[n];
        bool good = 1;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            d[i] = b[i] - a[i];
            if (d[i] < 0)
            {
                cout << "NO\n";
                good = 0;
            }
        }
        if (!good)
            continue;

        ll k = 0;
        ll knum = 0;
        for (ll i = 0; i < n; i++)
        {
            if (d[i] != 0 && !k)
            {
                k = d[i];
                knum++;
            }
            else if (d[i] != 0 && k != 0 && k != d[i])
            {
                good = 0;
                break;
            }
            else if (d[i] == 0)
                k = 0;
            if (knum > 1)
            {
                good = 0;
                break;
            }
        }

        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
