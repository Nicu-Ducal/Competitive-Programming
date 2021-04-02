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
    vector<int> ans;
    int n;

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
    }

    void dfs(int node) {
        marked[node] = true;
        for (auto next: adj[node])
            if (not marked[next])
                dfs(next);
        ans.push_back(node);
    }

    void solve() {
        for (int i = 1; i <= n; i++)
            if (not marked[i])
                dfs(i);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ifstream cin("semne3.in");
    ofstream cout("semne3.out");

    int n;
    cin >> n;
    Graph graph(n);
    for (int i = 1; i <= n - 1; i++) {
        char sgn;
        cin >> sgn;
        if (sgn == '>') graph.addEdge(i, i + 1);
        else graph.addEdge(i + 1, i);
    }
    graph.solve();
    for (auto node: graph.ans) cout << node << " ";

    return 0;
}