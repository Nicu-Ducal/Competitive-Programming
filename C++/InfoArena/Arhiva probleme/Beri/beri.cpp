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

const int INF = INT_MAX;
ll t, n, k, q, x, y, z, ans;
vector<int> a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("beri.in");
    ofstream cout("beri.out");

    cin >> n >> k >> q >> x >> y >> z;
    a.pb(q);
    for (int i = 1; i < n; i++){
        t = (a[i - 1] * x + y) % z + k;
        a.pb(t);
    }

    nth_element(a.begin(), a.begin() + n - k - 1, a.end());
    for (int i = n - 1; i >= n - k; i--){
        ans += a[i] - (i + k - n);
    }
    cout << ans;

    return 0;
}
