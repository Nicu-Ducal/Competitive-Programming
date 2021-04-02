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
    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    ll m = max(a, max(b, c));
    n = n - (m - a) - (m - b) - (m - c);
    if (n < 0)
    {
        cout << "NO\n";
        continue;
    }
    if (n % 3 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    }

    return 0;
}
