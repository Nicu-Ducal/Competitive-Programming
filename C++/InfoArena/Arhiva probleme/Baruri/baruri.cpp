/******** Ordered Set ********
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

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

const int INF = INT_MAX, MAXN = 100005;
ll t, n, m, p, q, b, d, x, aib[MAXN];

void update(ll i, ll val){
    while (i <= n){
        aib[i] += val;
        i += (-i & i);
    }
}

ll query(ll i){
    ll ans = 0;
    while (i > 0){
        ans += aib[i];
        i -= (-i & i);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("baruri.in");
    ofstream cout("baruri.out");

    cin >> t;
    while(t--){
        cin >> n;
        fill(aib, aib + n + 1, 0);
        for (int i = 1; i <= n; i++){
            cin >> p;
            update(i, p);
        }
        cin >> m;
        while (m--){
            cin >> q;
            switch (q){
                case 0:{
                    cin >> b >> d;
                    ll st = b - d;
                    ll dr = b + d;
                    if (st <= 0) st = 1;
                    if (dr > n) dr = n;
                    cout << query(b - 1) - query(st - 1) + query(dr) - query(b) << "\n";
                    break;
                }
                case 1:
                    cin >> x >> b;
                    update(b, x);
                    break;
                case 2:
                    cin >> x >> b;
                    update(b, -x);
                    break;
                case 3:
                    cin >> x >> b >> d;
                    update(b, -x);
                    update(d, x);
            }
        }
    }

    return 0;
}
