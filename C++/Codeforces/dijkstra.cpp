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

ll n, m, a, b, c, dist[200005], pred[200005];
bool viz[200005];
vector<pll> g[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n >> m;
    for (ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    dist[1] = 0;
    fill(dist + 2, dist + n + 1, LLONG_MAX);

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll nod = pq.top().se;
        pq.pop();
        if (!viz[nod]){
            viz[nod] = 1;
            for (auto &it : g[nod])
                if (dist[it.fi] > dist[nod] + it.se){
                    dist[it.fi] = dist[nod] + it.se;
                    pred[it.fi] = nod;
                    pq.push({dist[it.fi], it.fi});
                }
        }
        if (nod == n)
            break;
    }

    vector<ll> ans;
    ll i = n;
    while(i){
        ans.pb(i);
        i = pred[i];
    }
    if (ans.size() == 1 && ans[0] == n)
        cout << -1;
    else
        for(ll i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";

    return 0;
}
