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
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};  /// 0, U, D, L, R
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};  /// LU, RD, RU, LD

ll t, n, m, x;

struct Graph {
    vector<vector<pii>> adj;
    vector<bool> marked;

    Graph(int n = 0) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
        marked.resize(n + 1);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll dfs(int node, int x) {
        marked[node] = true;
        ll count = 1;
        for (auto next: adj[node]) {
            if (not marked[next.first] and next.second <= x)
                count += dfs(next.first, x);
        }
        return count;
    }

    ll countPairs(int x) {
        ll ans = 0;
        fill(all(marked), false);
        for (int node = 1; node <= n; node++)
            if (not marked[node]) {
                ll comp = dfs(node, x);
                ans += comp * (comp - 1) / 2;
            }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int u, v, w;
    cin >> n >> m >> x;
    Graph g(n);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        if (w <= x) g.addEdge(u, v, w);
    }

    cout << g.countPairs(x) - g.countPairs(x - 1);

    return 0;
}
