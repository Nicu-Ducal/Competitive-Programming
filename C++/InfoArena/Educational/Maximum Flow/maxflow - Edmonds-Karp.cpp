#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define sqr(x) (x) * (x)

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

ll t, n;

struct Graph {
    vector<vector<ll>> adj, capacity;
    vector<ll> parent;

    Graph(int n = -1) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
        capacity.resize(n + 1, vector<ll>(n + 1, 0));
        parent.resize(n + 1);
    }

    void addEdge(ll u, ll v, ll cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = cap;
    }

    ll bfs(ll s, ll t) {
        fill(all(parent), -1);
        parent[s] = -2;
        queue<pll> Q;
        Q.push({s, INF});

        while (not Q.empty()) {
            ll cur = Q.front().first;
            ll flow = Q.front().second;
            Q.pop();

            for (auto nxt: adj[cur]) {
                if (parent[nxt] == -1 and capacity[cur][nxt]) {
                    parent[nxt] = cur;
                    ll new_flow = min(flow, capacity[cur][nxt]);
                    if (nxt == t) return new_flow;
                    Q.push({nxt, new_flow});
                }
            }
        }

        return 0;
    }

    ll maxFlow(ll s, ll t) {
        ll flow = 0;
        ll new_flow, time = 0;

        while (bfs(s, t)) {
            for (auto node: adj[t]) {
                if (parent[node] != -1 && capacity[node][t]) {
                    new_flow = INF;
                    parent[t] = node;
                    int cur = t;
                    while (cur != s) {
                        new_flow = min(new_flow, capacity[parent[cur]][cur]);
                        cur = parent[cur];
                    }

                    if (new_flow == 0) continue;
                    cur = t;
                    while (cur != s) {
                        capacity[parent[cur]][cur] -= new_flow;
                        capacity[cur][parent[cur]] += new_flow;
                        cur = parent[cur];
                    }
                    flow += new_flow;
                }
            }
            /*flow += new_flow;
            ll cur = t;
            while (cur != s) {
                ll par = parent[cur];
                capacity[par][cur] -= new_flow;
                capacity[cur][par] += new_flow;
                cur = par;
            }*/
        }

        return flow;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("maxflow.in");
    ofstream cout("maxflow.out");

    ll m, u, v, c;
    cin >> n >> m;
    Graph g(n);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        g.addEdge(u, v, c);
    }

    cout << g.maxFlow(1, n);

    return 0;
}
