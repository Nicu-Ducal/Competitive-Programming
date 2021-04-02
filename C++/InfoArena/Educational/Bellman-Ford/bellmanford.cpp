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

ll n, m, a, b, c, dist[50005], cnt[50005];
vector<pll> g[50005];
bool inqueue[50005];

bool SPFA(){
    fill(dist, dist + n + 1, INT_MAX);
    queue<ll> q;

    dist[1] = 0;
    q.push(1);
    inqueue[1] = 1;
    while(!q.empty()){
        ll nod = q.front();
        q.pop();
        inqueue[nod] = 0;

        for (auto &it : g[nod]){
            if (dist[nod] + it.se < dist[it.fi]){
                dist[it.fi] = dist[nod] + it.se;
                if (!inqueue[it.fi]){
                    q.push(it.fi);
                    inqueue[it.fi] = 1;
                    cnt[it.fi]++;
                    if (cnt[it.fi] > n)
                        return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("bellmanford.in");
    ofstream cout("bellmanford.out");

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }

    if (!SPFA())
        cout << "Ciclu negativ!";
    else{
        for (ll i = 2; i <= n; i++)
            cout << dist[i] << " ";
    }

    return 0;
}
