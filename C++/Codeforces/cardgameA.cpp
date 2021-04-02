#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k1, k2;
        cin >> n >> k1 >> k2;
        ll a1[k1], a2[k2];
        ll m1 = 0;
        for (ll i = 0; i < k1; i++)
        {
            cin >> a1[i];
            if (a1[i] > m1) m1 = a1[i];
        }
        ll m2 = 0;
        for (ll i = 0; i < k2; i++)
        {
            cin >> a2[i];
            if (a2[i] > m2) m2 = a2[i];
        }
        if (m1 < m2) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
