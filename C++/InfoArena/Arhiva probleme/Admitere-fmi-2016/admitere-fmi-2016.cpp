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

ll t, n, m, k;

struct Graph {
    vector<vector<int>> adj;
    vector<int> nei;
    vector<bool> marked;

    Graph(int n = -1) {
        init(n);
    }

    void init(int n) {
        adj.resize(n + 1);
        nei.resize(n + 1, 0);
        marked.resize(n + 1, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++nei[u], ++nei[v];
    }

    bool findSets() {
        for (int node = 1; node <= n; node++)
            if (nei[node] < k and not marked[node]) dfs(node);
        bool ok = false;
        for (int node = 1; node <= n; node++) {
            if (not marked[node]) {
                ok = true;
                break;
            }
        }
        return ok;
    }

    void dfs(int node) {
        marked[node] = true;
        for (auto next: adj[node]) {
            --nei[next];
            if (nei[next] < k and not marked[next])
                dfs(next);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("admitere-fmi-2016.in");
    ofstream cout("admitere-fmi-2016.out");

    int u, v;
    cin >> n >> m >> k;
    Graph g(n);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    for (int node = 1; node <= n; node++) cout << g.nei[node] << " ";
    cout << "\n";
    if (g.findSets()) {
        for (int node = 1; node <= n; node++)
            if (not g.marked[node]) cout << node << " ";
    } else cout << "NU";

    return 0;
}
