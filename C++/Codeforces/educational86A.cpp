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
ll t, n, x, y, a, b;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> t;
    while (t--){
        cin >> x >> y >> a >> b;
        ll fsans = (x + y) * a;
        ll ans = 0;
        ll c = min(x, y);
        ans = min(c * b, 2 * c * a);
        x -= c, y -= c;
        cout << min(fsans, ans + max(x, y) * a) << "\n";
    }
    return 0;
}
