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

const int MAXN = 360005;
const int INF = INT_MAX;
ll t, n, m, k, a, b, c, dist[MAXN], ans[MAXN];
vector<pll> g[MAXN];
vector<ll> finNodes;
priority_queue<pll, vector<pll>, greater<pll>> heap;
bool viz[MAXN];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("catun.in");
    ofstream cout("catun.out");

    cin >> n >> m >> k;
    for (ll i = 0; i < k; i++){
        cin >> t;
        finNodes.pb(t);
        ans[t] = t;
    }
    for (ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    fill(dist, dist + n + 1, INF);
    sort(all(finNodes));
    for (auto fort : finNodes){
        dist[fort] = 0;
        heap.push({0, fort});
        viz[fort] = 1;
    }
    while (!heap.empty()){
        auto curr = heap.top().se;
        auto cost = heap.top().fi;
        heap.pop();
        for (auto nxt : g[curr]){
            if (ans[nxt.fi] == 0 or (viz[nxt.fi] == 1 and dist[nxt.fi] > cost + nxt.se) or (viz[nxt.fi] == 1 and ans[nxt.fi] > ans[curr] and dist[nxt.fi] == cost + nxt.se)){
                if (!viz[nxt.fi])
                    viz[nxt.fi] = 1;
                ans[nxt.fi] = ans[curr];
                dist[nxt.fi] = cost + nxt.se;
                heap.push({dist[nxt.fi], nxt.fi});
            }
        }
    }

    for (ll i = 1; i <= n; i++){
        if (ans[i] == i)
            cout << "0 ";
        else
            cout << ans[i] << " ";
    }

    return 0;
}
