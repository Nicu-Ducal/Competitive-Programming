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

const ll maxN = 50005;
ll n, m, a, b, c, dist[maxN];
bool viz[maxN];
vector<pll> g[maxN];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("dijkstra.in");
    ofstream cout("dijkstra.out");

    cin >> n >> m;
    for (ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }

    dist[1] = 0;
    for (int i = 2; i <= n; i++)
        dist[i] = INT_MAX;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        ll nod = pq.top().se;
        pq.pop();
        if(!viz[nod]){
            viz[nod] = 1;
            for (auto &it : g[nod]){
                dist[it.fi] = min(dist[it.fi], dist[nod] + it.se);
                pq.push({dist[it.fi], it.fi});
            }
        }
    }

    for (int i = 2; i <= n; i++){
        if (dist[i] == INT_MAX)
            cout << 0 << " ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}
