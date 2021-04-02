#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, p, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--)
    {
        cin >> n >> p >> k;

        vector <ll> a;
        ll c;
        for (ll i = 0; i <= n; i++)
        {
            cin >> c;
            if (c <= p) a.pb(c);
        }
        n = a.size();

        if (a.empty())
        {
            cout << 0 << "\n";
            continue;
        }

        sort(a, a + a.size());



    }

    return 0;
}
