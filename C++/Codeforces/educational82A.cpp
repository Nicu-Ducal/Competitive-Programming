#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, g, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--)
    {
        cin >> n >> g >> b;
        ll jum =  n / 2 + (n % 2 > 0);
        ll c = (jum / g) - (jum % g == 0);
        ll tot = (jum - c * g) + c *(g + b);
        if (c * b >= n - jum)
        {
            cout << tot << "\n";
            continue;
        }
        else
            cout << tot + (n - jum - c * b) << "\n";
    }

    return 0;
}
