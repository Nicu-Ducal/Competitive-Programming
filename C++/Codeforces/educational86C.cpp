#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

const int INF = INT_MAX;
ll t, n, l, r, a, b, q;

ll countMultiples(ll a, ll b, ll m) {
    if (a % m == 0)
        return (b / m - a / m + 1);
    return (b / m - a / m);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--){
        cin >> a >> b >> q;
        if (a > b)
            swap(a, b);
        for (ll query = 0; query < q; query++){
            cin >> l >> r;
            if (a == b){
                cout << "0 ";
                continue;
            }
            if (l < b and r < b){
                cout << "0 ";
                continue;
            }
            if (l < b and r >= b){
                l = b;
            }
            ll ans = r - l + 1;
            ll mult = lcm(a, b);
            ll numMult = countMultiples(l + 1, r, mult);
            ll currMult = mult * (l / mult);
            if (currMult + b - 1 >= l){
                ans -= (currMult + b - l);
            }
            ll lastMult = mult * (r / mult);
            if (lastMult + b - 1 < r){
                ans -= (numMult * b);
            }
            else{
                ans -= ((numMult - 1) * b);
                ans -= (r - lastMult + 1);
            }

            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}
