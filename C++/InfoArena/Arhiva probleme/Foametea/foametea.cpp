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

struct owo{
    ll nx, l, sc;
};

struct ska{
    ll nod, timp, sarm;
    bool operator <(const ska& ska2) const{
        return timp > ska2.timp;
    }
};

const ll maxN = 5010, maxk = 35;
ll n, m, k, s[maxN], dist[maxN][maxk], a, b, l, c;
vector<owo> g[maxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("foametea.in");
    ofstream cout("foametea.out");

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = 0; i < m; i++){
        cin >> a >> b >> l >> c;
        g[a].pb({b, l, c});
    }
    for (int i = 0; i <= n; i++)
        fill(dist[i], dist[i] + 35, INT_MAX);
    // Dijkstra
    dist[1][0] = 0;
    priority_queue<ska> pq;
    pq.push({1, 0, 0});
    while(!pq.empty()){
        ll curr = pq.top().nod;
        ll timp = pq.top().timp;
        ll sarm = pq.top().sarm;
        pq.pop();

        if (dist[curr][sarm] != timp) continue;

        for (auto &it : g[curr]){
            for (ll num = max(sarm, it.sc); num <= k; num++){
                if (num - sarm > s[curr])
                    break;
                if (dist[it.nx][num - it.sc] > timp + it.l * (1 + (num - it.sc) * (num - it.sc))){
                    dist[it.nx][num - it.sc] = timp + it.l * (1 + (num - it.sc) * (num - it.sc));
                    pq.push({it.nx, dist[it.nx][num - it.sc], num - it.sc});
                }
            }
        }
    }

    ll ans = INT_MAX;
    for (int i = 0; i <= k; i++){
        ans = min(ans, dist[n][i]);
    }

    if (ans == INT_MAX)
        cout << "Fomistul moare de foame";
    else
        cout << ans;

    return 0;
}
