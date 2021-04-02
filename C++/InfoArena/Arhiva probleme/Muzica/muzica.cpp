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

const int INF = INT_MAX, MOD = 100005;
ll t, n, m, a, b, c, d, e, curr, ans;

vector<int> hsh[MOD + 2];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("muzica.in");
    ofstream cout("muzica.out");

    cin >> n >> m;
    cin >> a >> b >> c >> d >> e;
    for (int i = 1; i <= n; i++){
        cin >> curr;
        hsh[curr % MOD].pb(curr);
    }

    for (int i = 1; i <= m; i++){
        if (i == 1){
            curr = a;
        } else if (i == 2){
            curr = b;
        } else {
            curr = (c * b + d * a) % e;
            a = b, b = curr;
        }
        for (auto &it : hsh[curr % MOD]){
            if (it == curr){
                ++ans;
                it = hsh[curr % MOD][hsh[curr % MOD].size() - 1];
                hsh[curr % MOD].pop_back();
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
