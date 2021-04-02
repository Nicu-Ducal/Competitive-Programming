#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, a, b, c, r;
const ll zero = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ll zero = 0;
    ll rez;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        ll ab = b - a;
        ll lo = max(a, c - r);
        ll hi = min(b, c + r);
        cout << (ab - max(zero, hi - lo)) << "\n";
    }

    return 0;
}
