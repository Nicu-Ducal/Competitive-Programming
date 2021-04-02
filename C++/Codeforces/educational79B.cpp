#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        ll a[n], asort[n];
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            asort[n];
            sum += a[i];
        }
        if (sum <= s)
        {
            cout << 0 << "\n";
            continue;
        }

        sort(asort, asort + n);


    }
    return 0;
}
