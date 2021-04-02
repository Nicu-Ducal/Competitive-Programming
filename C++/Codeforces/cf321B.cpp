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

const int INF = INT_MAX, maxN = 1e5 + 5;
ll t, n, d, p1, p2, ans = -INF, curr;
pll a[maxN];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> d;
    for (int i = 0; i < n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a, a + n);

    while (p2 < n){
        //cout << p1 << ' ' << p2 << "\n";
        curr += a[p2].se;
        while (p1 <= p2 and a[p2].fi - a[p1].fi >= d){
            curr -= a[p1].se;
            ++p1;
        }
        ans = max(ans, curr);
        ++p2;
    }
    cout << ans;

    return 0;
}
