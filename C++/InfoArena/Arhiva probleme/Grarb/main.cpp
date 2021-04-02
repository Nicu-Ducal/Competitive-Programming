#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
using i64 = long long int;

const int INF = INT_MAX, MOD = 1e9 + 7;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
const int dy[] = {0, -1, 1, 0, 0, -1, 1, -1, 1};

struct Graph {
    vector<vector<int>> adj;
    vector<bool> marked;
    vector<int> parent, level;
    int n, m;

    Graph(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        adj.resize(n + 1);
        marked.resize(n + 1, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int solve() {
        int ans = 0;
        for (int node = 1; node <= n; node++) {
            if (not marked[node]) {
                dfs(node);
                ans++;
            }
        }
        return ans - 1;
    }

    void dfs(int node) {
        marked[node] = true;
        for (auto nei: adj[node])
            if (not marked[nei])
                dfs(nei);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ifstream cin("grarb.in");
    ofstream cout("grarb.out");

    int n, m;
    cin >> n >> m;
    Graph g(n);
    g.m = m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int add = g.solve();
    int rem = m + add - (n - 1);
    cout << rem << "\n" << add << "\n";

    return 0;
}