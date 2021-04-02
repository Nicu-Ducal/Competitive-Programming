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
        ll a[n], b[n];
        bool egal = 1;

        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] != a[i]) egal = 0;
        }

        if (egal)
        {
            cout << "YES\n";
            continue;
        }

        ll k = 0;
        int ans = 0;
        bool good = 1;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] != b[i] && !k)
            {
                k = b[i] - a[i];
                if (k < 0)
                {
                    cout << "NO\n";
                    good = 0;
                    break;
                }
                ans++;
                continue;
            }
            else if (a[i] != b[i])
            {
                if (b[i] - a[i] != k)
                {
                    cout << "NO\n";
                    good = 0;
                    break;
                }
            }
            else if (a[i] = b[i])
            {
                k = 0;
            }
        }
        if (ans == 1 && good)
            cout << "YES\n";
        else if (ans > 1)
            cout << "NO\n";
    }
    return 0;
}
