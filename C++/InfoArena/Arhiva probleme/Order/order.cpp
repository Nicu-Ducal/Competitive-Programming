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

const int INF = INT_MAX, maxN = 30005, maxStep = (1 << 15);
ll n, aib[maxN], step, ans, curr = 2;
bool viz[maxN];

void update(ll i, ll val){
    while (i <= n){
        aib[i] += val;
        i += (-i & i);
    }
}

ll query(ll i){
    ll ret = 0;
    while (i > 0){
        ret += aib[i];
        i -= (-i & i);
    }
    return ret;
}

ll binarySearch(ll x){
    step = maxStep;
    ll idx = 0;
    while (step){
        if (idx + step <= n and aib[idx + step] <= x){
            if (x - aib[idx + step] != 0 or viz[idx + step] == false){
                x -= aib[idx + step];
                idx += step;
            }
        }
        step >>= 1;
    }
    viz[idx] = true;
    return idx;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("order.in");
    ofstream cout("order.out");

    cin >> n;
    for (int i = 1; i <= n; i++)
        update(i, 1);
    for (int i = 1; i <= n; i++){
        curr = (curr + i - 1) % (n - i + 1);
        if (curr == 0)
            curr = n - i + 1;
        ans = binarySearch(curr);
        update(ans, -1);
        cout << ans << " ";
    }

    return 0;
}
