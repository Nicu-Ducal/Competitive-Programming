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
    while(t--)
    {
        cin >> n;
        ll a[n];
        ll even = 0;
        ll odd = 0;
        ll s = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
            if (a[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        if (s % 2 == 1)
        {
            cout << "YES\n";
            continue;
        }
        else if (even == 0 || odd == 0)
        {
            cout << "NO\n";
            continue;
        }
        else
            cout << "YES\n";
    }

    return 0;
}
