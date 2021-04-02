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

const int INF = INT_MAX, MAXN = 15010;
ll t, n, m, q, a, x, y, aib[MAXN];

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
    ifstream cin("datorii.in");
    ofstream cout("datorii.out");

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a;
        update(i, a);
    }
    while (m--){
        cin >> q >> x >> y;
        if (q == 0){
            update(x, -y);
        } else {
            cout << query(y) - query(x - 1) << "\n";
        }
    }
    return 0;
}
