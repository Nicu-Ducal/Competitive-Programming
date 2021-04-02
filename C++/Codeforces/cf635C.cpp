#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len length()
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

ll t, n, k, a, b, sz[200005], dep[200005];
vector<ll> g[200005];
vector<ll> dp;

ll dfs(ll u, ll v){
    sz[v] = 1, dep[v] = dep[u] + 1;
    for (auto &child : g[v]){
        if (child == u)
            continue;
        sz[v] += dfs(v, child);
    }
    //cout << u << " " << v << " " << dep[v] << " " << sz[v] << "\n";
    dp.pb(dep[v] - sz[v]);
    return sz[v];
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> k;
    for (ll i = 0; i < n - 1; i++){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ll ans = 0;
    dfs(0,1);

    sort(all(dp), greater<ll>());
    for (ll i = 0; i < k; i++){
        ans += dp[i];
        //cout << dp[i] << " ";
    }

    cout << ans;

    return 0;
}
