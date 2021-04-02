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

const int MOD = 9917;
const int INF = INT_MAX;
int t, n, swaps, bit[100005];

void update(int i){
    while (i <= n){
        ++bit[i];
        i += (-i & i);
    }
}

int query(int i){
    int ret = 0;
    while (i > 0){
        ret += bit[i];
        i -= (-i & i);
    }
    return ret % MOD;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("inv.in");
    ofstream cout("inv.out");

    cin >> n;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(1 + all(a));
    for (int i = n; i > 0; i--){
        update(a[i].se);
        swaps += query(a[i].se - 1);
        swaps %= MOD;
    }
    cout << swaps;
    return 0;
}
