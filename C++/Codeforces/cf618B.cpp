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
        ll a[2 * n];
        for (ll i = 0; i < 2 * n; i++)
            cin >> a[i];
        sort(a, a + 2 * n);
        cout << a[n] - a[n - 1] << '\n';
    }
    return 0;
}
