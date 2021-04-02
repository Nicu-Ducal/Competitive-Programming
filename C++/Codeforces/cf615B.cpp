#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        pair <ll, ll> p[n];
        for (ll i = 0; i < n; i++)
            cin >> p[i].fi >> p[i].se;
        sort(p, p + n);
        bool ok = 1;
        for (ll i = 0; i < n - 1; i++)
            if (p[i].se > p[i + 1].se)
            {
                ok = 0;
                break;
            }
        if (ok == 0)
        {
            cout << "NO\n";
            continue;
        }

        string s = "";
        for (ll i = 0; i < p[0].fi; i++)
            s += "R";
        for (ll i = 0; i < p[0].se; i++)
            s += "U";

        ll xcurr = p[0].fi;
        ll ycurr = p[0].se;
        for (ll i = 1; i < n; i++)
        {
            if (xcurr < p[i].fi)
            {
                for (ll j = 0; j < p[i].fi - xcurr; j++)
                    s += "R";
                xcurr = p[i].fi;
            }
            if (p[i].fi == xcurr)
            {
                for (ll j = 0; j < p[i].se - ycurr; j++)
                    s += "U";
                ycurr = p[i].se;
            }
        }
        cout << "YES\n" << s << "\n";
    }


    return 0;
}
