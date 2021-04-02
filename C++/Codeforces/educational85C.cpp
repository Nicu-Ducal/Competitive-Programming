#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, ans, x, y, d, c[300005], sumc = 0;
pair <ll, ll> a[300005];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while(t--){
        ans = 0;
        sumc = 0;
        cin >> n;
        for (ll i = 0; i < n; i++){
            cin >> x >> y;
            a[i] = {x, y};
            if (i > 0){
                c[i] = max(0LL, a[i].fi - a[i - 1].se);
                sumc += c[i];
            }
        }
        c[0] = max(0LL, a[0].fi - a[n - 1].se);
        sumc += c[0];

        if (n == 1){
            cout << a[0].fi << "\n";
            continue;
        }

        ans = LLONG_MAX;
        for (ll i = 0; i < n; i++){
            ll current = sumc - c[i] + a[i].fi;
            ans = min(ans, current);
        }

        cout << ans << "\n";
    }

    return 0;
}
