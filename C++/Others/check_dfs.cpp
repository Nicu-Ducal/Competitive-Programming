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

ll t, n, m;

struct Graph {
    vector<unordered_set<int>> adj;
    vector<int> permutation, nei;
    vector<bool> marked;
    int idx = 1;

    Graph(int n = 0) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
        marked.resize(n + 1);
        permutation.resize(n + 1);
        nei.resize(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
        nei[u]++, nei[v]++;
    }

    bool checkDFS() {
        //adj[permutation[idx]].insert(-1);
        return dfs(permutation[idx]);
    }

    bool dfs(int node) {
        marked[node] = true;
        if (idx == n) return true;
        bool ok = true;
        for (auto nb: adj[node]) if (marked[nb]) --nei[nb], --nei[node];
        while (nei[node] and idx < n and ok) {
            if (adj[node].find(permutation[idx + 1]) != adj[node].end()) {
                idx++;
                ok &= dfs(permutation[idx]);
            } else
                return false;
        }
        return ((idx == n) or ok);
    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> n >> m;
    Graph G(n);
    for (int i = 1; i <= n; i++) cin >> G.permutation[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }

    cout << G.checkDFS();

    return 0;
}
