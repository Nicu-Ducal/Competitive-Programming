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
int t, n, a[1005], l;
double ans = 0;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> l;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n + 1; i++)
        ans = max(((a[i + 1] - a[i]) * 1.0 / 2), ans);
    if (a[0] != 0) ans = max(ans, a[0] * 1.0);
    if (a[n - 1] != l) ans = max(ans, 1.0 * (l - a[n - 1]));
    cout << fixed << setprecision(9) << ans;
    return 0;
}
