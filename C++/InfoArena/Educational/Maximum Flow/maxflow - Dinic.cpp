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

struct Edge {
    ll u, v, cap, flow = 0;
    Edge(ll _u, ll _v, ll _cap) : u(_u), v(_v), cap(_cap) {}
};

struct Graph {
    vector<vector<ll>> adj;
    vector<Edge> edges;
    vector<ll> ptr, level;
    int m;

    Graph(int n = -1) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
        level.resize(n + 1);
        ptr.resize(n + 1);
        m = 0;
    }

    void addEdge(ll u, ll v, ll cap) {
        edges.push_back(Edge(u, v, cap));
        edges.push_back(Edge(v, u, 0));
        adj[u].push_back(m++);
        adj[v].push_back(m++);
    }

    bool bfs(ll s, ll t) {
        queue<ll> Q;
        Q.push(s);
        while (not Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (auto next: adj[cur]) {
                if (edges[next].cap - edges[next].flow < 1) continue;
                if (level[edges[next].v] != -1) continue;
                level[edges[next].v] = level[cur] + 1;
                Q.push(edges[next].v);
            }
        }
        return level[t] != -1;
    }

    ll dfs(ll u, ll pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed;

        for (ll& cid = ptr[u]; cid < (ll) adj[u].size(); cid++) {
            ll id = adj[u][cid];
            ll v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1) continue;
            ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow(ll s, ll t) {
        ll flow = 0;
        while (true) {
            fill(all(level), -1);
            level[s] = 0;
            if (not bfs(s, t)) break;
            fill(all(ptr), 0);
            while (ll pushed = dfs(s, INF))
                flow += pushed;
            cout << "pula";
        }

        return flow;
    }

};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("maxflow.in");
    //ofstream cout("maxflow.out");

    ll m, u, v, c;
    cin >> n >> m;
    Graph g(n);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        g.addEdge(u, v, c);
    }

    cout << g.flow(1, n);

    return 0;
}
